#include "Point.h"

int main( void ) {
	Point a;
	Point b(10, 30);
	Point c(20, 0);
	Point point(10.5f, 15.5f);
	if (bsp(a, b, c, point))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
return 0;
}