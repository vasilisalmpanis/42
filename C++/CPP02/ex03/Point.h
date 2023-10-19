//
// Created by Vasileios Almpanis on 10/19/23.
//

#ifndef Point_HPP
#define Point_HPP
#include "Fixed.h"


class Point {
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(const float x, const float y);
	~Point();
	Point(Point const &obj);
	Point &operator=(const Point &obj);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
