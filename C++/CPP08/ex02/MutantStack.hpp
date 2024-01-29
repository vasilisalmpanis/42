#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(MutantStack const &obj) : std::stack<T>(obj) {};
        MutantStack &operator=(MutantStack const &obj) { std::stack<T>::operator=(obj); return *this; };
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        // using iterator =  typename std::stack<T>::container_type::iterator;
        // using const_iterator =  typename std::stack<T>::container_type::const_iterator;
        // using reverse_iterator =  typename std::stack<T>::container_type::reverse_iterator;
        // C++11 Version. Alias declarations for iterator types.
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        virtual ~MutantStack() {};
};