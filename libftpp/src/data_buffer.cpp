#include <data_buffer.hpp>

DataBuffer::DataBuffer() {}

DataBuffer::~DataBuffer() {}

DataBuffer::DataBuffer(const DataBuffer &other) { *this = other; }
DataBuffer::DataBuffer(DataBuffer &&other) : buffer(std::move(other.buffer)) { 
}

DataBuffer &DataBuffer::operator=(const DataBuffer &other) {
    if (this != &other) {
        buffer = other.buffer;
    }
    return *this;
}

template <>
DataBuffer &DataBuffer::operator<<(const std::string &string) {
    size_t string_size = string.size();
    *this << string_size;
    buffer.insert(buffer.end(), string.begin(), string.end());
    return *this;
}

template <>
DataBuffer &DataBuffer::operator>>(std::string &string) {
    size_t size;
    *this >> size; // Deserialize the size first
    if (size > buffer.size()) {
        throw std::out_of_range("Buffer underflow");
    }
    string.assign(reinterpret_cast<const char *>(buffer.data()), size);
    buffer.erase(buffer.begin(), buffer.begin() + size);
    return *this;
}
