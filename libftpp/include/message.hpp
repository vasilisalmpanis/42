#pragma once
#include <data_buffer.hpp>
#include <includes.hpp>


class Message: public DataBuffer {
public:
	explicit Message(int type);
	Message(Message &&) = default;
	Message(const Message &) = delete;
	Message &operator=(Message &&) = default;
	Message &operator=(const Message &) = delete;
	~Message();

public:
	int type() const noexcept;
private:
	int _type;
};

