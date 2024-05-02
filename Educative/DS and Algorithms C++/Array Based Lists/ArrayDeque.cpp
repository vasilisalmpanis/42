#include <string.h>
#include <algorithm>

template <typename T>
class ArrayDeque {
    public:
        ArrayDeque();
        ~ArrayDeque();
        ArrayDeque(const ArrayDeque<T>& other);
        ArrayDeque<T>& operator=(const ArrayDeque<T>& other);
        T get(int i);
        T set(int i, T x);
        bool add(int i, T x);
        T remove(int i);
        void resize();
        int size();
        void clear() {
            count = 0;
            j = 0;
            if (capacity > 1) {
                delete[] a;
                capacity = 1;
                a = new T[capacity];
            }
        }
    private:
        int count;
        int j;
        int capacity;
        T* a;
};

template <typename T>
ArrayDeque< T > ::ArrayDeque()
{
    capacity = 1;
    a = new T[capacity];
    count = 0;
    j = 0;
}

template <typename T>
void ArrayDeque< T > ::resize()
{
    T * b = new T[std::max(1, 2 * capacity)];
    for (int k = 0; k < count; k++)
        b[k] = a[(j + k) % capacity];
    a = b;
    j = 0;
}

template <typename T>
ArrayDeque< T > ::~ArrayDeque()
{
    delete[] a;
}

template <typename T>
ArrayDeque< T > ::ArrayDeque(const ArrayDeque< T > &other)
{
    this = &other;
}

template <typename T>
ArrayDeque<T> &ArrayDeque< T > ::operator=(const ArrayDeque< T > &other)
{
    if (this != &other)
    {
        delete[] a;
        a = new T[other.capacity];
        for (int i = 0; i < other.capacity; i++)
        {
            a[i] = other.a[i];
        }
        count = other.count;
        j = other.j;
        capacity = other.capacity;
    }
    return *this;
}

template <typename T>
T ArrayDeque< T > ::get(int i)
{
    return a[(j + i) % capacity];
}

template <typename T>
T ArrayDeque< T > ::set(int i, T x)
{
    T y = a[(j + i) % capacity];
    a[(j + i) % capacity] = x;
    return y;
} 

template <typename T>
bool ArrayDeque< T > ::add(int i, T x)
{
    if (count + 1 > capacity) resize();
    if (i < count / 2)
    {
        j = (j == 0) ? capacity - 1 : j - 1;
        for (int k = 0; k <= i - 1; k++)
            a[(j + k) % capacity] = a[(j + k + 1) % capacity];
    }
    else
    {
        for (int k = count; k > i; k--)
            a[(j + k) % capacity] = a[(j + k - 1) % capacity];
    }
    a[(j + i) % capacity] = x;
    count++;
    return true;
}

template <typename T>
T ArrayDeque< T > ::remove(int i)
{
    T x = a[(j + i) % capacity];
    if (i < count / 2)
    {
        for (int k = i; k > 0; k--)
            a[(j + k) % capacity] = a[(j + k - 1) % capacity];
        j = (j + 1) % capacity;
    }
    else
    {
        for (int k = i; k < count - 1; k++)
            a[(j + k) % capacity] = a[(j + k + 1) % capacity];
    }
    if (3 * count < capacity) resize();
    return x;
}

template <typename T>
int ArrayDeque< T > ::size()
{
    return count;
}


#include <cmath>

#include <cassert>

#include <ctime>

#include <cstdlib>

#include <iostream>

using namespace std;

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000
#endif

const unsigned RA = 0x0001; // random access
const unsigned FM = 0x0002; // front modifications
template < class List >
    void listTests(List & ell, int n, unsigned flags) {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(5);

        ell.clear();

        clock_t start, stop;
        cout << "Adding " << n << " elements...";
        cout.flush();
        start = clock();
        for (int i = 0; i < n; i++)
            ell.add(ell.size(), i);
        stop = clock();
        cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

        if (flags & RA) {
            cout << "Reading " << n << " elements...";
            cout.flush();
            start = clock();
            for (int i = 0; i < n; i++)
                assert(ell.get(i) == i);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

            cout << "Setting " << n << " elements...";
            cout.flush();
            start = clock();
            for (int i = 0; i < n; i++)
                ell.set(i, 2 * i);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;
        } else {
            cout << "Reading 2log(" << n << ") elements...";
            cout.flush();
            start = clock();
            for (int i = 1; i < n; i *= 2) {
                assert(ell.get(i) == i);
                assert(ell.get(n - i - 1) == n - i - 1);
            }
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

            cout << "Setting 2log(" << n << ") elements...";
            cout.flush();
            start = clock();
            for (int i = 1; i < n; i *= 2) {
                ell.set(i, 2 * i);
                ell.set(n - i - 1, 2 * (n - i - 1));
            }
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

        }

        if (flags & FM) {
            cout << "Adding " << n << " elements at front...";
            cout.flush();
            start = clock();
            for (int i = 0; i < n; i++)
                ell.add(0, i);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

            cout << "Removing " << n << " elements at front...";
            cout.flush();
            start = clock();
            for (int i = 0; i < n; i++)
                ell.remove(0);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;
        } else {
            cout << "Adding log(" << n << ") elements at front...";
            cout.flush();
            start = clock();
            for (int i = 1; i < n; i *= 2)
                ell.add(0, i);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;

            cout << "Removing log(" << n << ") elements at front...";
            cout.flush();
            start = clock();
            for (int i = 1; i < n; i *= 2)
                ell.remove(0);
            stop = clock();
            cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;
        }

        cout << "Removing " << n << " elements...";
        cout.flush();
        start = clock();
        for (int i = 0; i < n; i++)
            ell.remove(ell.size() - 1);
        stop = clock();
        cout << "done (" << ((double)(stop - start)) / CLOCKS_PER_SEC << "s)" << endl;
    }

#include <iostream>
int main(int argc, char ** argv) {
    int n = 1000000;
    std::cout << std::endl << "ArrayDeque<int>:" << std::endl;
    ArrayDeque < int > ad;
    listTests(ad, n, RA | FM);

    return 0;
}