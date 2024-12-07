#ifndef THREAD_SAFE_IOSTREAM_HPP
#define THREAD_SAFE_IOSTREAM_HPP
#pragma once
#include <includes.hpp>

// thread-safe I/O stream with prefixed lines
//
extern std::mutex mutex;

class ThreadSafeIOStream {
public:
    ThreadSafeIOStream() = default;
    ThreadSafeIOStream(ThreadSafeIOStream &&) = default;
    ThreadSafeIOStream(const ThreadSafeIOStream &) = delete;
    ThreadSafeIOStream &operator=(ThreadSafeIOStream &&) = default;
    ThreadSafeIOStream &operator=(const ThreadSafeIOStream &) = delete;
    ~ThreadSafeIOStream() = default;

    template <class TType>
    ThreadSafeIOStream &operator<<(const TType &in);

    template <class TType>
    ThreadSafeIOStream &operator>>(TType &out);

    ThreadSafeIOStream &operator<<(std::ostream &(*manip)(std::ostream &));

public:
    // overload of >> <<
    void setPrefix(const std::string &prefix);
    template <typename T>
    void prompt(const std::string &question, T &dest) {
        std::ostrstream buffer;

        buffer << _prefix << question;
        {
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << buffer.str();
        }
        std::cin >> dest;
    }

private:
    std::string _prefix;
    std::ostringstream _buffer;
};

template <class TType>
ThreadSafeIOStream &ThreadSafeIOStream::operator<<(const TType &in) {

    std::lock_guard<std::mutex> lock(mutex);
    if (_buffer.str().empty())
        _buffer << _prefix << in;
    else
        _buffer << in;
    return *this;
}

template <class TType>
ThreadSafeIOStream &ThreadSafeIOStream::operator>>(TType &out) {
    std::lock_guard<std::mutex> lock(mutex);

    _buffer >> out;
    return *this;
}

extern thread_local ThreadSafeIOStream threadSafeCout;

/*template <class TType>*/
#endif
