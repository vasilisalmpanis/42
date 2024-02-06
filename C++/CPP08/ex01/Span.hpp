#pragma once
#include <vector>
#include <exception>
#include <iostream>

class Span {
		unsigned int	_N;
		unsigned int	_size;
		int 			*_array;
		int 			findMin(void) const;
		int 			findMax(void) const;
		int 			findSecondMin(void) const;
	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span(void);
		Span &operator=(const Span &rhs);

		// Public methods

		void 			addNumber(int number);
		void 			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int 			shortestSpan(void);
		int 			longestSpan(void);

		// Exceptions
		class FullArrayException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoSpanToFindException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
