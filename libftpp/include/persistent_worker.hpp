#pragma once
#include "thread.hpp"
#include <functional>
#include <includes.hpp>
#include <string>
#include <thread>

class PersistentWorker {
public:
	class Task {
		public:
			std::string getName() const;
			std::function<void()> getTask() const;
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
	void addTask(const std::string& name, const std::function<void()>& jobToExecute);
	void removeTask(const std::string& name);
	void work();
private:
	std::vector<Task> _persistentWorkers;
	std::thread	_worker;
	std::mutex	_mutex;
};
