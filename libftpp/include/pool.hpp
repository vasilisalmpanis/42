#pragma once
#include "includes.hpp"

/*
 * thoughts of doing it with vector of TType * but subject requires pre
 * allocated memory so I used placement new.
 * */
template <typename TType>
class Pool {
public:
    // Forward declaration of Object class with TType
    Pool(void);
    ~Pool(void);
    class Object {
    public:
        Object(Pool *address, TType *pointer, size_t index)
            : pool(address), ptr(pointer), index(index) {}
        ~Object() {
            if (pool && ptr)
                pool->release(index);
        };
        Object(Object &other) = delete;
        Object(const Object &other) = delete;
        Object &operator=(Object &other) = delete;
        Object &operator=(const Object &other) = delete;
        TType *operator->() { return ptr; }

    private:
        Pool *pool;
        TType *ptr;
        size_t index;
    };

    // Method to acquire an object
    template <typename... TArgs>
    Object acquire(TArgs &&...p_args);
    void resize(const size_t &numberOfObjectStored);

private:
    void release(size_t index);

    std::vector<TType> resources;
    std::stack<size_t> availableIndexes;
};

template <typename TType>
Pool<TType>::Pool(void) {}

template <typename TType>
Pool<TType>::~Pool(void) {}

template <typename TType>
template <typename... TArgs>
typename Pool<TType>::Object Pool<TType>::acquire(TArgs &&...p_args) {
    if (availableIndexes.empty())
        resize(resources.size() + 1);
    size_t index = availableIndexes.top();
    availableIndexes.pop();

    new (&resources[index])
        TType(std::forward<decltype(TArgs(p_args))>(p_args)...);
    return Object(this, &resources[index], index);
}

template <typename TType>
void Pool<TType>::release(size_t index) {
    if (index > resources.size() - 1)
        return;
    resources[index].~TType();
    availableIndexes.push(index);
}

template <typename TType>
void Pool<TType>::resize(const size_t &numberOfObjectStored) {
    size_t oldsize = resources.size();
    resources.resize(numberOfObjectStored);
    // add positions that can be indexed to get object to stack
    for (int index = oldsize; index < numberOfObjectStored; index++) {
        availableIndexes.push(index);
    }
}
