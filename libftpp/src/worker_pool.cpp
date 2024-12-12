#include <worker_pool.hpp>

WorkerPool::WorkerPool(size_t number) {
    for (size_t i = 0; i < number; i++) {
        _workers.emplace_back([this]() {
            while (true) {
                std::function<void()> job;
                {
                    std::unique_lock<std::mutex> lock(this->_mutex);
                    this->_condition.wait(lock, [this]() {
                        return this->_shouldStop || !_jobs.empty();
                    });

                    if (_shouldStop || _jobs.empty())
                        return;

                    /* Move the first job and remove it
                     * from the queue.
                     */
                    job = std::move(_jobs.front());
                    _jobs.pop();
                }

                /* Execute */
                job();
            }
        });
    }
}

void WorkerPool::addJob(std::function<void()> function) {
    {
        std::lock_guard<std::mutex> lock(this->_mutex);
        _jobs.emplace(function);
    }
    _condition.notify_one();
}

WorkerPool::~WorkerPool() {
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _shouldStop = true;
    }

    /* The notifying thread does not need to hold the lock */
    _condition.notify_all();
    for (std::thread &worker : _workers) {
	    if (worker.joinable())
		    worker.join();
    }
}
