#pragma once
#include <includes.hpp>
#include <message.hpp>


class Client {
public:
	Client();
	Client(Client &&) = default;
	Client(const Client &) = default;
	Client &operator=(Client &&) = default;
	Client &operator=(const Client &) = default;
	~Client();

public:
	void connect(const std::string& address, const size_t& port);
	void disconnect();
	void defineAction(const Message::Type& messageType,const std::function<void(const Message& msg)>& action);
	void send(const Message& message);
	void update();
private:
	std::string	_address;
	int		_fd;
	size_t		_port;
	std::unordered_map<Message::Type , std::function<void(Message &)>> _actions;
	std::unordered_map<Message::Type, std::function<void(Message &)>> actions_;
	
};

