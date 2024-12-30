#pragma once
#include <cstddef>
#include <data_buffer.hpp>
#include <includes.hpp>

class Message : public DataBuffer {
public:
    using Type = size_t;
    explicit Message(Type type);
    Message(Message &&) = default;
    Message(const Message &) = delete;
    Message &operator=(Message &&) = default;
    Message &operator=(const Message &) = delete;
    ~Message();

public:
    size_t type() const noexcept;

private:
    Type _type;
};
