#pragma once
#include <data_buffer.hpp>
#include <includes.hpp>


class Message: public DataBuffer {
public:
	using Type = int;
	explicit Message(Type type);
	Message(Message &&) = default;
	Message(const Message &) = delete;
	Message &operator=(Message &&) = default;
	Message &operator=(const Message &) = delete;
	~Message();

public:
	int type() const noexcept;
private:
	Type _type;
};

