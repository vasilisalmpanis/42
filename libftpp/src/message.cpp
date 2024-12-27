#include <message.hpp>

Message::Message(Type type) : DataBuffer(), _type(type) {}

Message::~Message() {}

int Message::type() const noexcept { return _type; }
