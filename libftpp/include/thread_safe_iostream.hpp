#ifndef THREAD_SAFE_IOSTREAM_HPP
#define THREAD_SAFE_IOSTREAM_HPP
#pragma once
#include <includes.hpp>

// Thread-safe I/O stream with prefixed lines

extern std::mutex mutex;

class ThreadSafeIOStream {
public:
    ThreadSafeIOStream(std::ostream &ostream = std::cout,
                       std::istream &istream = std::cin)
        : _ostream(ostream), _istream(istream) {}
    ThreadSafeIOStream(ThreadSafeIOStream &&) = delete;
    ThreadSafeIOStream(const ThreadSafeIOStream &) = delete;
    ThreadSafeIOStream &operator=(ThreadSafeIOStream &&) = delete;
    ThreadSafeIOStream &operator=(const ThreadSafeIOStream &) = delete;
    ~ThreadSafeIOStream() = default;

    template <class TType>
    ThreadSafeIOStream &operator<<(const TType &in);

    template <class TType>
    ThreadSafeIOStream &operator>>(TType &out);

    ThreadSafeIOStream &operator<<(std::ostream &(*manip)(std::ostream &));

public:
    // Overload of >> <<
    void setPrefix(const std::string &prefix);
    template <typename T>
    void prompt(const std::string &question, T &dest) {
        std::ostrstream buffer;

        buffer << _prefix << question;
        {
            std::lock_guard<std::mutex> lock(mutex);
            _ostream << buffer.str();
        }
        _istream >> dest;
    }

private:
    std::string _prefix;
    // change the deprecated ostringstream to something like a stringstream
    std::ostringstream _buffer;
    std::ostream &_ostream;
    std::istream &_istream;
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

/* Template <class TType>*/
#endif
