#pragma once
#include "includes.hpp"

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
};

template <class TState>
StateMachine<TState>::StateMachine() {}

template <class TState>
StateMachine<TState>::~StateMachine() {}
