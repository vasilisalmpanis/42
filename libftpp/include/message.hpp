#pragma once
#include <data_buffer.hpp>
#include <includes.hpp>

class Message : public DataBuffer {
public:
    using Type = size_t;
    explicit Message(Type type);
    Message(Message &&) = default;
    Message &operator=(Message &&) = default;
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

public:
    size_t type() const noexcept;

private:
    Type _type;
};
