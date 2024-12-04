#pragma once
#include <functional>
#include <map>


template<class TEvent>
class Observer {
public:
	Observer();
	~Observer();
	Observer(const Observer &other);
	Observer &operator = (const Observer &other);
	void subscribe(const TEvent& event, const std::function<void()>& lambda);
	void notify(const TEvent& event);
private:
	std::map<TEvent, std::function<void()> &> events;
};
