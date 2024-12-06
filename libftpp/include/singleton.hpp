#pragma once

#include <stdexcept>
#include <utility>
template <typename TType> class Singleton {
public:
  static TType *instance();

  template <typename... Targs> static void instantiate(Targs &&...p_args);

  ~Singleton();
  Singleton(const Singleton &other) = delete;
  Singleton(Singleton &other) = delete;
  Singleton(const Singleton &&other) = delete;
  Singleton(Singleton &&other) = delete;

private:
  Singleton();
  Singleton(TType *value) : _value(value) {}

private:
  static Singleton *_instance;
  TType *_value;
};

template <typename TType>
Singleton<TType> *Singleton<TType>::_instance = nullptr;

template <typename TType> TType *Singleton<TType>::instance() {
  if (_instance == nullptr)
    throw std::runtime_error("There is not instance");
  return _instance->_value;
  // returns pointer to instance
  // or throws exception
}

template <typename TType> Singleton<TType>::~Singleton() {
  delete _value;
  delete _instance;
}

template <typename TType>
template <typename... Targs>
void Singleton<TType>::instantiate(Targs &&...p_args) {
  if (_instance != nullptr)
    throw std::runtime_error("Singleton already instanciated");
  TType *value = new TType(std::forward<Targs>(p_args)...);
  _instance = new Singleton(value);
}
