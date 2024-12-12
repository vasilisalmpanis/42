#include "worker_pool.hpp"
#include <functional>
#include <iostream>
#include "thread_safe_iostream.hpp"

int main() {
    WorkerPool pool(4);

    void (*job)() = []() {
        threadSafeCout << "Executing job on thread: " << std::this_thread::get_id() << std::endl;
    };

    for (int i = 0; i < 1000; ++i) {
        pool.addJob(job);
        pool.addJob(Master::execute);
    }

    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for jobs to finish

    return 0;
}
