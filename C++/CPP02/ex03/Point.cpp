//
// Created by Vasileios Almpanis on 10/19/23.
//

#include "Point.h"

Point::Point() : _x(Fixed()), _y(Fixed()){

}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {

}

Point::~Point() {
	std::cout << "Destructor Called" << std::endl;
}

Point::Point(Point const &obj) : _x(obj._x), _y(obj._y){

}

Point &Point::operator=(Point const &obj) {
	if (this != &obj)
	{
		(Fixed) this->_x = obj._x;
		(Fixed) this->_y = obj._x;
	}
	return (*this);
}

Fixed Point::getX() const {
	return (_x);
}

Fixed Point::getY() const {
	return (_y);
}
