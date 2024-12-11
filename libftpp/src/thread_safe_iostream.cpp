#include <mutex>
#include <ostream>
#include <thread_safe_iostream.hpp>

/*thread_local ThreadSafeIOStream threadSafeCout;*/
std::mutex mutex;
thread_local ThreadSafeIOStream threadSafeCout;

void ThreadSafeIOStream::setPrefix(const std::string &prefix) {
    _prefix = prefix;
    if (_prefix.empty() || _prefix.back() != ' ')
        _prefix += ": ";
}

ThreadSafeIOStream &
ThreadSafeIOStream::operator<<(std::ostream &(*manip)(std::ostream &)) {
    if (manip == static_cast<std::ostream &(*)(std::ostream &)>(std::endl) ||
        manip == static_cast<std::ostream &(*)(std::ostream &)>(std::flush)) {
        std::lock_guard<std::mutex> lock(mutex);
        if (manip ==
            static_cast<std::ostream &(*)(std::ostream &)>(std::endl)) {
            _buffer << "\n";
            _ostream << _buffer.str();
        } else if (manip ==
                   static_cast<std::ostream &(*)(std::ostream &)>(std::flush)) {
            _ostream << _buffer.str() << manip;
        }
        _buffer.str("");
    }
    return *this;
}
