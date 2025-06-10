#include "Graph.hpp"
#include "Vector2.hpp"
#include <exception>

int main(void) {
	try {
		Vector2 size = Vector2(6.0, 6.0);
		Graph graph = Graph(size);
		graph.addPoint(Vector2(0,0));
		graph.addPoint(Vector2(2,2));
		graph.addPoint(Vector2(4,2));
		graph.addPoint(Vector2(2,4));
		std::cout << graph << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
