#include <client.hpp>

Client::Client() : _fd(-1) {
    memset(&_serv, 0, sizeof(struct sockaddr_storage));
}

Client::~Client() {
    if (_fd != -1) {
        disconnect();
    }
}

// Public
void Client::connect(const std::string &address, const size_t &port) {
    struct addrinfo *res, *ai, hints;
    std::string _port = std::to_string(port);
    int ret;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_protocol = 0;
    hints.ai_socktype = SOCK_STREAM;
    ret = getaddrinfo(address.c_str(), _port.c_str(), &hints, &res);
    if (ret != 0) {
        throw std::runtime_error(gai_strerror(ret));
    }
    for (ai = res; ai != NULL; ai = ai->ai_next) {
        char str[INET6_ADDRSTRLEN];
        if (ai->ai_addr->sa_family == AF_INET) {
            struct sockaddr_in *p = (struct sockaddr_in *)ai->ai_addr;
            printf("%s\n", inet_ntop(AF_INET, &p->sin_addr, str, sizeof(str)));
        } else if (ai->ai_addr->sa_family == AF_INET6) {
            struct sockaddr_in6 *p = (struct sockaddr_in6 *)ai->ai_addr;
            printf("%s\n",
                   inet_ntop(AF_INET6, &p->sin6_addr, str, sizeof(str)));
        }
        _fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);

        if (_fd < 0)
            continue;

        ret = ::connect(_fd, ai->ai_addr, ai->ai_addrlen);
        if (ret == 0)
            break;

        close(_fd);
        _fd = -1;
    }
    if (ai == NULL) {
        freeaddrinfo(res);
        throw std::runtime_error("Unable to connect");
    }

    freeaddrinfo(res);
}

void Client::disconnect() {
    close(_fd);
    _fd = -1;
}

void Client::defineAction(
    const Message::Type &messageType,
    const std::function<void(const Message &msg)> &action) {
    if (_actions.find(messageType) != _actions.end())
        throw ActionDefinedException();
    _actions[messageType] = action;
}

void Client::send(const Message &message) {
    Message temp = message;
    // sends type, size and body of message

    size_t type = 0, size = 0;
    int ret;
    temp >> type;
    size = temp.size();
    if (size <= 0)
        return;
    ret = ::send(_fd, &type, sizeof(size_t), 0);
    if (ret == 0)
        throw ClientDisconnected();
    ret = ::send(_fd, &size, sizeof(size_t), 0);
    if (ret == 0)
        throw ClientDisconnected();
    ret = ::send(_fd, temp.data(), size, 0);
    if (ret == 0)
        throw ClientDisconnected();
}

void Client::update() {
    if (_fd == -1)
        throw NotConnectedException();
    int ret;
    size_t type = 0, size = 0;
    ret = ::recv(_fd, &type, sizeof(size_t), MSG_DONTWAIT); // receive the type

    if (ret == 0)
        throw ClientDisconnected();
    else if (ret < 0)
        return;
    ret = ::recv(_fd, &size, sizeof(size_t), MSG_DONTWAIT); // receive the size

    if (ret == 0)
        throw ClientDisconnected();
    else if (ret < 0)
        return;
    std::vector<uint8_t> msg;
    int received = 0;
    while (true) { // receive the rest of the message
        ret = ::recv(_fd, msg.data() + received, size - received, MSG_DONTWAIT);
        if (ret == 0)
            throw ClientDisconnected();
        if (ret < 0)
            continue;
        received += ret;
        if (static_cast<size_t>(received) >= size)
            break;
    }
    // perform the action
    auto action = _actions.find(type);
    Message message(type);
    for (size_t i = 0; i < msg.size(); i++)
        message << msg[i];
    if (action != _actions.end())
        action->second(message);
}
