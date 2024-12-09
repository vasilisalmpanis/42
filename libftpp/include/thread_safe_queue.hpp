#pragma once
#include <includes.hpp>

template <class TType>
class ThreadSafeQueue {
public:
    ThreadSafeQueue();
    ThreadSafeQueue(ThreadSafeQueue &&) = default;
    ThreadSafeQueue(const ThreadSafeQueue &) = default;
    ThreadSafeQueue &operator=(ThreadSafeQueue &&) = default;
    ThreadSafeQueue &operator=(const ThreadSafeQueue &) = default;
    ~ThreadSafeQueue();

public:
    void push_back(const TType &newElement);
    void push_front(const TType &newElement);
    TType pop_back();
    TType pop_front();

    bool is_empty();

private:
    std::mutex _mutex;
    std::deque<TType> _deque;
};

template <class TType>
ThreadSafeQueue<TType>::ThreadSafeQueue() {}

template <class TType>
ThreadSafeQueue<TType>::~ThreadSafeQueue() {}

template <class TType>
void ThreadSafeQueue<TType>::push_back(const TType &newElement) {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_back(newElement);
}

template <class TType>
void ThreadSafeQueue<TType>::push_front(const TType &newElement) {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_front(newElement);
}

template <class TType>
TType ThreadSafeQueue<TType>::pop_back() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (is_empty())
        throw std::runtime_error("Queue is empty");
    TType back = _deque.back();
    _deque.pop_back();
    return back;
}

template <class TType>
TType ThreadSafeQueue<TType>::pop_front() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (is_empty())
        throw std::runtime_error("Queue is empty");
    TType front = _deque.front();
    _deque.pop_front();
    return front;
}

template <class TType>
bool ThreadSafeQueue<TType>::is_empty() {
    return _deque.empty();
}
