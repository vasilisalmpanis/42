#pragma once
#include <functional>
#include <map>
#include <vector>

template <class TEvent>
class Observer {
public:
    Observer() = default;
    ~Observer() = default;
    Observer(const Observer &other) = delete;
    Observer &operator=(const Observer &other) = delete;

    void subscribe(const TEvent &event, const std::function<void()> &lambda) {
        /* reference to vector to insert subscriber */
        auto &vector = events[event];
        vector.push_back(lambda);
    }
    void notify(const TEvent &event) {
        auto it = events.find(event);

        /* if no observer return gracefully */
        if (it == events.end())
            return;
        for (auto callback : it->second)
            callback(); /* run all observer callbacks */
    }

    bool has_event(const TEvent &event) {
        if (events.find(event) == events.end())
            return false;
        return true;
    }

private:
    /* allow multiple subscibers to the same event with vector */
    std::map<TEvent, std::vector<std::function<void()>>> events;
};
