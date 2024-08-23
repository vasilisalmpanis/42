#pragma once
#include "includes.hpp"

class DataBuffer {
	public:
		DataBuffer();
		DataBuffer(DataBuffer &&) = default;
		DataBuffer(const DataBuffer &);
		DataBuffer &operator=(const DataBuffer &);
		~DataBuffer();
		template<typename T>
		DataBuffer &operator >> (T &data);
		template<typename T>
		DataBuffer &operator << (const T &data);
	private:
		std::vector<uint8_t> buffer;
};

template<typename T>
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

template<>
DataBuffer &DataBuffer::operator<<(const std::string &string) {
	size_t string_size = string.size();
	*this << string_size;
	buffer.insert(buffer.end(), string.begin(), string.end());
	return *this;
}

template<typename T>
DataBuffer &DataBuffer::operator>>(T &data) {
	size_t size = sizeof(T);
	if (size > buffer.size()) {
		throw std::out_of_range("Buffer underflow");
	}
	std::memcpy(&data, buffer.data(), size);
	buffer.erase(buffer.begin(), buffer.begin() + size);
	return *this;
}

template<>
DataBuffer &DataBuffer::operator>>(std::string &string) {
	size_t size;
	*this >> size;  // Deserialize the size first
	if (size > buffer.size()) {
		throw std::out_of_range("Buffer underflow");
	}
	string.assign(reinterpret_cast<const char *>(buffer.data()), size);
	buffer.erase(buffer.begin(), buffer.begin() + size);
	return *this;
}
