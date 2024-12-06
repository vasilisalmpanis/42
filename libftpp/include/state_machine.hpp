#pragma once
#include "includes.hpp"
#include "observer.hpp"
#include <stdexcept>
#include <unordered_map>
#include <vector>

template <class TState>
class StateMachine {
public:
    StateMachine();
    StateMachine(StateMachine &&) = default;
    StateMachine(const StateMachine &) = default;
    StateMachine &operator=(StateMachine &&) = default;
    StateMachine &operator=(const StateMachine &) = default;
    ~StateMachine();

    /* add specific possible state to the object */
    void addState(const TState &state);

    /* Specifies what to execute uppon a specific transition */
    void addTransition(const TState &startState, const TState &finalState,
                       const std::function<void()> &lambda);

    /* Specifies what to
       execute when the StateMachine is in a specific state. */
    void addAction(const TState &state, const std::function<void()> &lambda);

    /*  Executes the
        transition to a specific state. */
    void transitionTo(const TState &state);

    /* Executes the action registred for the current state. */
    void update();

    /* Handle state transitions cleanly and efficiently. If a transition
       or an update isn’t set up by the user, the StateMachine must
       throw an exception. */

private:
    std::unordered_map<TState, std::vector<Observer<TState>>> _states;
    TState _current_state;
    bool _has_state;
};

template <class TState>
StateMachine<TState>::StateMachine() {}

template <class TState>
StateMachine<TState>::~StateMachine() {}

template <class TState>
void StateMachine<TState>::addState(const TState &state) {
    if (_states.find(state) != _states.end()) {
        throw std::invalid_argument("This state is already registered");
    }
    // vector 0 is for actions
    // vector 1 is for transitions
    _states[state] = std::vector<Observer<TState>>(2);
    if (!_has_state) {
        _has_state = true;
        _current_state = state;
    }
}

template <class TState>
void StateMachine<TState>::addTransition(const TState &startState,
                                         const TState &finalState,
                                         const std::function<void()> &lambda) {
    if (_states.find(startState) == _states.end())
        throw std::invalid_argument("State not registered");
    _states[startState][1].subscribe(finalState, lambda);
}

template <class TState>
void StateMachine<TState>::addAction(const TState &state,
                                     const std::function<void()> &lambda) {
    if (_states.find(state) == _states.end())
        throw std::invalid_argument("State not registered");
    _states[state][0].subscribe(state, lambda);
}

template <class TState>
void StateMachine<TState>::transitionTo(const TState &state) {
    /* executes the transition to a specific state */
    if (_current_state == state)
        return;
    if (_states.find(state) == _states.end())
        throw std::invalid_argument("Invalid State to transition to");
    if (!_states[_current_state][1].has_event(state)) {
        _current_state = state;
        throw std::invalid_argument("Invalid transition");
    }
    _states[_current_state][1].notify(state);
    _current_state = state;
}
template <class TState>
void StateMachine<TState>::update() {
    /* Executes the action registred for the current state. */
    if (!_has_state)
        throw std::invalid_argument("No current state registered");

    _states[_current_state][0].notify(_current_state);
    return;
}
