#include "thread_safe_iostream.hpp"
#include <asm-generic/socket.h>
#include <netdb.h>
#include <server.hpp>
#include <sys/socket.h>

Server::Server() {
    FD_ZERO(&_master);
    FD_ZERO(&_read_fds);
    _fd = -1;
}

Server::~Server() {
    if (_fd != -1)
        close(_fd);
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _running.store(false);
    }
    if (_thread.joinable())
        _thread.join();
}

Server::Server(const Server &other) { this->_fd = other._fd; }

Server &Server::operator=(const Server &other) {
    this->_fd = other._fd;
    return *this;
}

void Server::backgroundWork() {
    threadSafeCout << "polling" << std::endl;
    while (_running.load()) {
    }
}

void Server::start(const size_t &port) {
    struct addrinfo hints, *res, *ai;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int ret = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &res);
    if (ret < 0)
        return;
    for (ai = res; ai != NULL; ai = ai->ai_next) {
        int server_fd =
            socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (server_fd == -1) {
            perror("socket");
            continue;
        }

        int reuse = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse,
                       sizeof(reuse)) == -1) {
            perror("setsockopt");
            continue;
        }

        // Bind the socket to the port
        if (bind(server_fd, res->ai_addr, res->ai_addrlen) == -1) {
            perror("bind");
            close(server_fd);
            continue;
        }

        if (listen(server_fd, 1000) == -1) {
            perror("listen");
            close(server_fd);
            continue;
        }
        _fd = server_fd;
        break;
    }
    if (ai == NULL) {
        freeaddrinfo(res);
        std::cerr << "problem setting up server" << std::endl;
        return;
    }
    freeaddrinfo(res);

    // set server to running and start the background task to poll for events
    _running.store(true);
    this->_thread = std::thread(&Server::backgroundWork, this);
}
