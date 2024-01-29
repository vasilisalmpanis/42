#include "Span.hpp"

Span::Span(unsigned int N): _N(N), _size(0), _array(new int[N]) {}

Span::Span(const Span &other): _N(other._N), _size(other._size), _array(new int[other._N]) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _N = other._N;
        _size = other._size;
        delete [] _array;
        _array = new int[_N];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return *this;
}

Span::~Span(void) {
    delete [] _array;
}

// Public methods

void Span::addNumber(int number) {
    if (_size == _N)
        throw FullArrayException();
    _array[_size++] = number;
}

int Span::shortestSpan(void) {
    if (_size < 2)
        throw NotEnoughNumbersException();
    int min = findMin();
    int secondMin = findSecondMin();
    return secondMin - min;
}

int Span::longestSpan(void) {
    if (_size < 2)
        throw NotEnoughNumbersException();
    int min = findMin();
    int max = findMax();
    return max - min;
}


int Span::findMin(void) const {
    if (_size < 2)
        throw NotEnoughNumbersException();
    int min = _array[0];
    for (unsigned int i = 1; i < _size; i++)
        if (_array[i] < min)
            min = _array[i];
    return min;
}

int Span::findSecondMin(void) const
{
    if (_size < 2)
        throw NotEnoughNumbersException();
    int min = findMin();
    int secondMin = _array[0];
    for (unsigned int i = 1; i < _size; i++)
        if (_array[i] < secondMin && _array[i] != min)
            secondMin = _array[i];
    return secondMin;
}

int Span::findMax(void) const {
    if (_size < 2)
        throw NotEnoughNumbersException();
    int max = _array[0];
    for (unsigned int i = 1; i < _size; i++)
        if (_array[i] > max)
            max = _array[i];
    return max;
}



// Exceptions

const char *Span::FullArrayException::what() const throw() {
    return "Array is full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to find span";
}

const char *Span::NoSpanToFindException::what() const throw() {
    return "No span to find";
}