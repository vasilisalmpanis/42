#include <client.hpp>

Client::Client(): _fd(-1) {
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
		_fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);

		if (_fd < 0) continue;

		ret = ::connect(_fd, ai->ai_addr, ai->ai_addrlen);
		if (ret == 0) break;

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

void Client::defineAction(const Message::Type& messageType, const std::function<void(const Message& msg)>&action) {
	_actions[messageType] = action;
}

void Client::send(const Message& message) {
	(void)message;
}

void Client::update() {}
