//
// Created by Vasileios Almpanis on 10/18/23.
//

#include "Fixed.h"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Fixed::Fixed(const int num) : _fixedPoint(num << this->_fractionalBits)  {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fixedPoint((int)roundf((num * (int)(1 << this->_fractionalBits))))  {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_fixedPoint = obj._fixedPoint;
	return (*this);
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

int Fixed::toInt() const {
	return ((int)(_fixedPoint >> this->_fractionalBits));
}

float Fixed::toFloat() const{
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}

std::ostream & operator << (std::ostream &out, const Fixed &obj){
	out << obj.toFloat();
	return out;
}
