#include <message.hpp>

Message::Message(int type) {
	switch (type) {
		case Messsage_type::INT:
		case Messsage_type::BOOL:
		case Messsage_type::FLOAT:
		case Messsage_type::DOUBLE:
		case Messsage_type::STRING:
			break;
		default:
			throw std::runtime_error("Invalid Message Type");
	}
	__type = type;
}

Message::~Message()
{
}

int Message::type() const noexcept {
	return __type;
}
