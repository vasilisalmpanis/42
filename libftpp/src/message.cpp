#include <cstddef>
#include <message.hpp>

Message::Message(Type type) : DataBuffer(), _type(type) {}

Message::~Message() {}

size_t Message::type() const noexcept { return _type; }
