#include <includes.hpp>

enum Messsage_type {
	INT,
	BOOL,
	CHAR,
	DOUBLE,
	FLOAT,
	STRING,
};

class Message {
public:
	Message(int type);
	Message(Message &&) = default;
	Message(const Message &) = delete;
	Message &operator=(Message &&) = default;
	Message &operator=(const Message &) = delete;
	~Message();

public:
	template<typename T>
	Message &operator<<(const T &object);

	template<typename T>
	Message &operator>>(T &object);

	int type() const noexcept;
private:
	int __type;
	std::stringstream __buffer;
};

template<typename T>
Message &Message::operator<<(const T &object) 
{
	__buffer << object;
	return *this;
}

template<typename T>
Message &Message::operator>>(T &object) {
	__buffer >> object;
	return *this;
}
