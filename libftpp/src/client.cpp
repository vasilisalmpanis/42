#include <client.hpp>

Client::Client(): _fd(-1) {
}

Client::~Client() {
}

// Public
void Client::connect(const std::string &address, const size_t &port) {}

void Client::disconnect() {}

void Client::defineAction(const Message::Type& messageType, const std::function<void(const Message& msg)>&action) {}

void Client::send(const Message& message) {}

void Client::update() {}
