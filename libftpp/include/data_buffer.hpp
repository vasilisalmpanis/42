#pragma once
#include <cstddef>
#include <includes.hpp>
#include <type_traits>

class DataBuffer {
public:
    DataBuffer();
    DataBuffer(DataBuffer &&);
    DataBuffer(const DataBuffer &);
    DataBuffer &operator=(const DataBuffer &);
    ~DataBuffer();

    template <typename T>
    DataBuffer &operator>>(T &data);
    template <typename T>
    DataBuffer &operator>>(const T &data);
    template <typename T>
    DataBuffer &operator<<(const T &data);

    template <typename TType>
	    DataBuffer &operator<<(const std::vector<TType> &vector);

    template <typename TType>
	    DataBuffer &operator>>(std::vector<TType> &vector);
private:
    std::vector<uint8_t> buffer;
};

template <typename T>
DataBuffer &DataBuffer::operator<<(const T &data) {
    size_t size = sizeof(T);
    try {
        buffer.resize(buffer.size() + size);
    } catch (const std::bad_alloc &e) {
        return *this;
    }
    std::memcpy(buffer.data() + buffer.size() - size, &data, size);
    return *this;
}

template <typename T>
DataBuffer &DataBuffer::operator>>(T &data) {
    size_t size = sizeof(T);
    if (size > buffer.size()) {
        throw std::out_of_range("Buffer underflow");
    }
    std::memcpy(&data, buffer.data(), size);
    buffer.erase(buffer.begin(), buffer.begin() + size);
    return *this;
}

template <typename TType>
DataBuffer &DataBuffer::operator<<(const std::vector<TType> &vector) {
    size_t size = vector.size();
    try {
        buffer.resize(buffer.size() + size * sizeof(TType) + sizeof(size_t));
    } catch (const std::bad_alloc &e) {
        return *this;
    }
    *this << size;
    for (const auto &element : vector) {
        *this << element;  // Serialize each element using operator<< for TType
    }

    return *this;
}

template <typename TType>
DataBuffer &DataBuffer::operator>>(std::vector<TType> &vector) {
    size_t vector_size;
    *this >> vector_size;  // Deserialize the size of the vector

    vector.resize(vector_size);  // Resize to hold the elements

    for (auto &element : vector) {
        *this >> element;  // Deserialize each element using operator>> for TType
    }

    return *this;
}
