#pragma once

template <class T, class U> // is the same as template <typename T, typename U>
void swap(T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T> // is the same as template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <class T> // is the same as template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
