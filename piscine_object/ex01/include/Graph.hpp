#pragma once
#include "Vector2.hpp"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

class Graph {
public:
	Graph(Vector2 size): size(size) {};
	void addPoint(Vector2 point);
	void plot(std::ostream &out) const;
	friend std::ostream& operator<<(std::ostream& os, const Graph& obj);
private:
		Vector2 size;
		std::vector<Vector2> points;

		bool hasPointAt(int x, int y) const {
			const Vector2 target(static_cast<float>(x), static_cast<float>(y));
			for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it) {
				if (*it == target) {
					return true;
				}
			}
			return false;
		}
		
};
