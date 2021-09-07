#pragma once

#include <string>
#include <stack>

#include "types.h"

class Calculator
{
public:
    Calculator();

    struct State
    {
        std::string           display;
        std::stack<Number>    numbers;
        std::stack<Operation> operations;
        Operation current_operation = NONE;
    };

    void pressKey(const char key);

    const State &state() const { return _state; }
protected:
    State _state;
};

