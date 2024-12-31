#include "data_buffer.hpp"
#include <message.hpp>

Message::Message(Type type) : DataBuffer(), _type(type) {}

Message::Message(const Message &other) : DataBuffer(other) {
    if (this != &other)
        *this = other;
}

Message &Message::operator=(const Message &other) {
    if (this != &other) {
        DataBuffer::operator=(other);
        _type = other._type;
    }
    return *this;
}

Message::~Message() {}

size_t Message::type() const noexcept { return _type; }
