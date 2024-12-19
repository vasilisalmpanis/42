#include <persistent_worker.hpp>

PersistentWorker::PersistentWorker() {
	_running = true;
    _worker = std::thread(&PersistentWorker::work, this);
}

PersistentWorker::~PersistentWorker() { 
	_running = false;
	_worker.join();
}

void PersistentWorker::addTask(const std::string &name,
                               const std::function<void()> &jobToExecute) {
    for (auto &task : _persistentWorkers) {
        if (task.getName() == name)
            throw std::runtime_error("Task already exists");
    }
    _persistentWorkers.push_back(Task(name, jobToExecute));
}
void PersistentWorker::removeTask(const std::string &name) {
    for (std::vector<Task>::iterator it = _persistentWorkers.begin();
         it != _persistentWorkers.end(); it++)
        if ((*it).getName() == name)
            _persistentWorkers.erase(it);
}

void PersistentWorker::work() {
    while (_running) {
        for (auto &task : this->_persistentWorkers) {
            task.getTask()();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
