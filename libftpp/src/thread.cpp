#include "thread_safe_iostream.hpp"
#include <stdexcept>
#include <thread.hpp>
#include <thread>

Thread::Thread(const std::string &name, std::function<void()> functToExecute) {
    _lamda = functToExecute;
    _name = name;
    _running = false;
}
void Thread::start() {
    if (_running)
        throw std::runtime_error("Thread already started");
    _running = true;
    _thread = std::thread([this]() {
		    threadSafeCout.setPrefix(this->_name);
		    this->_lamda();
	});
}
void Thread::stop() {
	if (!_running)
		throw std::runtime_error("Thread is not running");
	_running = false;
	if (_thread.joinable())
		_thread.join();
}
