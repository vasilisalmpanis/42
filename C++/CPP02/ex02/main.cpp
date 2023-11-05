#include "Fixed.h"







int main() {
    Fixed a;
    Fixed b(5.05f);
    Fixed c(2.5f);

    // Test basic arithmetic operations
    Fixed result;
    
    result = a + b;
    std::cout << "a + b = " << result << std::endl;
    
    result = a - b;
    std::cout << "a - b = " << result << std::endl;
    
    result = b * c;
    std::cout << "b * c = " << result << std::endl;
    
    result = b / c;
    std::cout << "b / c = " << result << std::endl;

    // Test comparisons
    bool equal = (b == c);
    bool notEqual = (b != c);
    bool lessThan = (b < c);
    bool greaterThan = (b > c);

    std::cout << "b == c: " << equal << std::endl;
    std::cout << "b != c: " << notEqual << std::endl;
    std::cout << "b < c: " << lessThan << std::endl;
    std::cout << "b > c: " << greaterThan << std::endl;

    // Test increment and decrement
    a = Fixed(10.0f);
    std::cout << "a = " << a << std::endl;
    
	std::cout << "pre" << a++ << std::endl;
	std::cout << "post" << a << std::endl;
    Fixed preInc = ++a;
    std::cout << "Pre-increment a: " << preInc << std::endl;
    std::cout << "a after pre-increment: " << a << std::endl;

    Fixed postDec = a--;
    std::cout << "Post-decrement a: " << postDec << std::endl;
    std::cout << "a after post-decrement: " << a << std::endl;

    Fixed preDec = --a;
    std::cout << "Pre-decrement a: " << preDec << std::endl;
    std::cout << "a after pre-decrement: " << a << std::endl;

    return 0;
}
