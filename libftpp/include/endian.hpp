#pragma once
#include <arpa/inet.h>
#include <cstdint>
#include <endian.h>

template <typename T>
struct Endian;

template <>
struct Endian<uint16_t> {
    static uint16_t toNetwork(uint16_t value) { return htons(value); }
    static uint16_t toHost(uint16_t value) { return ntohs(value); }
};

template <>
struct Endian<uint32_t> {
    static uint32_t toNetwork(uint32_t value) { return htonl(value); }
    static uint32_t toHost(uint32_t value) { return ntohl(value); }
};

template <>
struct Endian<uint64_t> {
    static uint64_t toNetwork(uint64_t value) {
#if defined(htonll)
        return htonll(value);
#elif defined(htobe64)
        return htobe64(value);
#else
        uint32_t high = htonl(static_cast<uint32_t>(value >> 32));
        uint32_t low = htonl(static_cast<uint32_t>(value & 0xFFFFFFFF));
        return static_cast<uint_64t>(low << 32) | high;
#endif
    }
    static uint64_t toHost(uint32_t value) {
#if defined(htonll)
        return ntonll(value);
#elif defined(htobe64)
        return be64toh(value);
#else
        uint32_t high = htonl(static_cast<uint32_t>(value >> 32));
        uint32_t low = htonl(static_cast<uint32_t>(value & 0xFFFFFFFF));
        return static_cast<uint_64t>(low << 32) | high;
#endif
    }
};

template <>
struct Endian<int16_t> {
    static int16_t toNetwork(int16_t value) { return htons(value); }
    static int16_t toHost(int16_t value) { return ntohs(value); }
};

template <>
struct Endian<int32_t> {
    static int32_t toNetwork(int32_t value) { return htonl(value); }
    static int32_t toHost(int32_t value) { return ntohl(value); }
};

template <>
struct Endian<int64_t> {
    static int64_t toNetwork(int64_t value) {
        return static_cast<int64_t>(Endian<uint64_t>::toNetwork(value));
    }
    static int64_t toHost(int64_t value) {
        return static_cast<int64_t>(Endian<uint64_t>::toHost(value));
    }
};
