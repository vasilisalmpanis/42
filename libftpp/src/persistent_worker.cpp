#include <chrono>
#include <persistent_worker.hpp>
#include <thread>


PersistentWorker::PersistentWorker() {
	_worker = std::thread(&PersistentWorker::work, this);
}

PersistentWorker::~PersistentWorker() {
	if (_worker.joinable())
		_worker.join();
}

void PersistentWorker::work() {
	while (true) {
		for (auto &task : this->_persistentWorkers) {
			auto job = task.getTask();
			job();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
