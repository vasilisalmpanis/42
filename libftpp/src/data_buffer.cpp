#include "../include/data_buffer.hpp"

DataBuffer::DataBuffer() {
}

DataBuffer::~DataBuffer() {
}

DataBuffer::DataBuffer(const DataBuffer &other)
{
	*this = other;
}

DataBuffer &DataBuffer::operator= (const DataBuffer &other)
{
	if (this != &other) {
		buffer = other.buffer;
	}
	return *this;
}

