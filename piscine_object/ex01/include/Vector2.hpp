#pragma once

class Graph;

class Vector2 {
public:
	Vector2(float x, float y) : x(x), y(y) {};
	bool cmp(float x, float y) const;
	bool operator==(const Vector2 &other) const;
private:
		float x;
		float y;
	friend class Graph;
};

struct VectorFunctor {
	VectorFunctor(Vector2 point) : point(point) {};
	bool operator()(Vector2 &point) {
		return point == this->point;
	}
	private:
		Vector2 point;
};
