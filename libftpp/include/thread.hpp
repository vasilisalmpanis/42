#pragma once

class Thread {
public:
	Thread() = default;
	Thread(Thread &&) = default;
	Thread(const Thread &) = default;
	Thread &operator=(Thread &&) = default;
	Thread &operator=(const Thread &) = default;
	~Thread() = default;

private:
	
};
