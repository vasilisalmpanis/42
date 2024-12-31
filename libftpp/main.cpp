#include <client.hpp>

int main(void)
{
	Client client;
	Message msg(1);
	msg << "hello world";
	client.connect("localhost", 8080);
	while (true) {
		client.update();
		client.send(msg);
	}
}
