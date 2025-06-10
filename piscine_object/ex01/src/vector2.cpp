#include "Vector2.hpp"

bool Vector2::operator==(const Vector2 &other) const 
{
	return this->x == other.x && this->y == other.y;
}
