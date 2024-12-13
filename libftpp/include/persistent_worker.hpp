#pragma once

class PersistentWorker {
public:
	PersistentWorker();
	PersistentWorker(PersistentWorker &&) = default;
	PersistentWorker(const PersistentWorker &) = default;
	PersistentWorker &operator=(PersistentWorker &&) = default;
	PersistentWorker &operator=(const PersistentWorker &) = default;
	~PersistentWorker();

private:
	
};

PersistentWorker::PersistentWorker() {
}

PersistentWorker::~PersistentWorker() {
}
