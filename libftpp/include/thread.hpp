#pragma once
#include <design_pattern.hpp>
#include <includes.hpp>

class Thread {
public:
    Thread(const std::string &name, std::function<void()> functToExecute);
    Thread(Thread &&) = default;
    Thread(const Thread &) = delete;
    Thread &operator=(Thread &&) = default;
    Thread &operator=(const Thread &) = delete;
    ~Thread() = default;

public:
    void start();
    void stop();

private:
    std::function<void()> _lamda;
    std::thread _thread;
    std::string _name;
    bool _running;
};
