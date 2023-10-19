//
// Created by Vasileios Almpanis on 10/18/23.
//

#ifndef Fixed_HPP
#define Fixed_HPP
#include <iostream>

class Fixed {
private:
	int	_fixedPoint;
	static const int _fractionalBits;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &bj);
	Fixed &operator= (const Fixed &obj);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif
