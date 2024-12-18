#pragma once
#include <includes.hpp>

class PersistentWorker {
public:
    class Task {
    public:
        std::string getName() const { return _name; }
        std::function<void()> getTask() const { return _lambda; }
	Task(std::string name, std::function<void()> lambda) : _lambda(lambda), _name(name) {}
	~Task() {}

    private:
        std::function<void()> _lambda;
        std::string _name;
    };

public:
    PersistentWorker();
    PersistentWorker(PersistentWorker &&) = delete;
    PersistentWorker(const PersistentWorker &) = delete;
    PersistentWorker &operator=(PersistentWorker &&) = delete;
    PersistentWorker &operator=(const PersistentWorker &) = delete;
    ~PersistentWorker();
    void addTask(const std::string &name,
                 const std::function<void()> &jobToExecute);
    void removeTask(const std::string &name);
    void work();

private:
    std::vector<Task> _persistentWorkers;
    std::thread _worker;
    std::mutex _mutex;
};
