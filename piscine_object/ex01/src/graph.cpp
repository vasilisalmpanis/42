#include "Graph.hpp"

void Graph::addPoint(Vector2 point) {
	if (point.x > size.x)
		throw std::runtime_error("invalid point");
	if (point.y > size.y)
		throw std::runtime_error("invalid point");
	const std::vector<Vector2>::iterator it = std::find_if(
			points.begin(),
			points.end(),
			VectorFunctor(point)
	);
	if (it != points.end())
		throw std::runtime_error("Point already exists");
	points.push_back(point);
}

void Graph::plot(std::ostream &out) const {
	for (int i = size.y - 1; i >= 0; i--) {
		out << i << " ";
		for (int j = 0; j < size.x; j++) {
			if (hasPointAt(i, j)) {
				out << "X ";
			} else {
				out << ". ";
			}	
		}
		out << std::endl;
	}
	out << " ";
	for (int i = 0; i < size.x; i++)
		out << " " << i;
}

std::ostream& operator<<(std::ostream& os, const Graph& obj) {
	obj.plot(os);
	return os;
}
