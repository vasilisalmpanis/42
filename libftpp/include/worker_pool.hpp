#pragma once
#include <design_pattern.hpp>

/* Theory:
 * we use a vector of threads that we initialize with an
 * infinite loop that:
 * - waits till one or more jobs appear
 * - when one does main thread notifies one that is blocked in waiting
 * - the job is executed. When the main thread is ready to exit
 * - the destructor changes the finishing variable and so they can exit
 *   and joins them
 */
class WorkerPool {
public:
    class IJobs {
    public:
        static void execute();
        virtual ~IJobs() = 0;
    };

    WorkerPool(size_t number);
    /* If we relocate the mutex other threads
     * cannot possibly know about it so thread safety
     * goes flying out of the window */
    WorkerPool(WorkerPool &&) = delete;
    WorkerPool &operator=(WorkerPool &&) = delete;
    WorkerPool(const WorkerPool &) = delete;
    WorkerPool &operator=(const WorkerPool &) = delete;
    ~WorkerPool();

public:
    void addJob(std::function<void()> function);

private:
    std::mutex _mutex;
    std::vector<std::thread> _workers;
    std::queue<std::function<void()>> _jobs;
    std::condition_variable _condition;
    bool _shouldStop = false;
};

class Master : public WorkerPool::IJobs {
public:
    static void execute(){
        threadSafeCout << "Master Executing job on thread: "
                       << std::this_thread::get_id() << std::endl;
    }
};
