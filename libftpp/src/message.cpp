#include <message.hpp>

Message::Message(int type): DataBuffer() , _type(type) {
}

Message::~Message()
{
}

int Message::type() const noexcept {
	return _type;
}
