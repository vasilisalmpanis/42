#include <iostream>
#include <algorithm>


template < class T >
class ArrayQueue {
    public:
        ArrayQueue(int capacity);
        ~ArrayQueue();
        ArrayQueue(const ArrayQueue<T>& other);
        ArrayQueue<T>& operator=(const ArrayQueue<T>& other);
        void add(T x);
        T remove();
        void resize();

    private:
        int n;
        int j;
        int capacity;
        T* a;
};


template < class T >
ArrayQueue<T> ::ArrayQueue(int capacity) {
    this->capacity = capacity;
    a = new T[capacity];
    n = 0;
    j = 0;
}

template < class T >
ArrayQueue<T> ::~ArrayQueue() {
    delete[] a;
}

template < class T >
ArrayQueue< T > ::ArrayQueue(const ArrayQueue< T > &other)
{
    this = &other;
}

template <class T>
ArrayQueue<T>& ArrayQueue<T> ::operator=(const ArrayQueue<T>& other)
{
    if (this != &other)
    {
        delete[] a;
        a = new T[other.capacity];
        for (int i = 0; i < other.capacity; i++)
        {
            a[i] = other.a[i];
        }
        n = other.n;
        j = other.j;
        capacity = other.capacity;
    }
    return *this;
}

template < class T >
void ArrayQueue< T > ::add(T x)
{
    if (n + 1 > capacity) resize();
    a[(j + n) % capacity] = x;
    n++;
}

template < class T >
T ArrayQueue< T > ::remove()
{
    if (n == 0) return 0;
    T x = a[j];
    j = (j + 1) % capacity;
    n--;
    if (capacity >= 3 * n) resize();
    return x;
}

template < class T >
void ArrayQueue< T > ::resize()
{
    T *b = new T[std::max(1, 2 * n)];
    for (int k = 0; k < n; k++)
    {
        b[k] = a[(j + k) % capacity];
    }
    a = b;
    j = 0;
    capacity = std::max(1, 2 * n);
}


int main() {
  ArrayQueue<int> buffer(10);

  for (int i = 0; i < 15; i++) {
    buffer.add(i); // Add elements to the buffer
  }

  for (int i = 0; i < 16; i++) {
    std::cout << buffer.remove() << " "; // Remove and print elements from the buffer
  }

  return 0;
}