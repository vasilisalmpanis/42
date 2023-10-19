//
// Created by Vasileios Almpanis on 10/18/23.
//

#ifndef Fixed_HPP
#define Fixed_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_fixedPoint;
	static const int	_fractionalBits;
public:
	bool	operator>(Fixed const &other) const;
	bool	operator< (Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<= (Fixed const &other) const;
	bool	operator== (Fixed const &other) const;
	bool	operator!= (Fixed const &other) const;
	Fixed	operator* (Fixed const &other) const;
	Fixed	operator/ (Fixed const &other) const;
	Fixed	operator+ (Fixed const &other) const;
	Fixed	operator- (Fixed const &other) const;
	Fixed	operator++ (int number);
	Fixed	operator++ (void);
	Fixed	operator-- (int number);
	Fixed	operator-- (void);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);

	Fixed();
	~Fixed();
	Fixed(Fixed const &bj);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator= (const Fixed &obj);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) 	const;
	int		toInt( void ) const;
	// friend std::ostream &operator << (std::ostream &out , const Fixed &obj);
};

std::ostream & operator << (std::ostream &out, const Fixed &obj);

#endif