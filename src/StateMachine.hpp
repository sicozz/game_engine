#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace GE
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
        std::stack<StateRef> m_states;
        StateRef m_newState;
        bool m_isAdding;
        bool m_isRemoving;
        bool m_isReplacing;
    public:
        StateMachine() {}
        ~StateMachine() {}
        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();
        void ProcessStateChanges();
        StateRef &GetActiveState();
    };
}