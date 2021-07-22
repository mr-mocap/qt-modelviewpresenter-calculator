#include "Calculator.h"

#include <cctype>
#include <functional>
#include <tuple>
#include <map>
#include <array>
#include <cassert>

using namespace std;

namespace
{
    map<Operation, int> OperationLevel = { {Operation::EQUALS, 0}, {Operation::PLUS, 1}, {Operation::MINUS, 1}, {Operation::MULTIPLY, 2}, {Operation::DIVIDE, 2} };

    void PerformOperation(Calculator::State& calculator_state);
    void PerformOperation(stack<Number>& numbers, stack<Operation>& operations);
    bool IsOperationPrecedentLessThanOrEqual(const Operation left, const Operation right);

    using OperationDelegate = function<void(stack<Number> &, stack<Operation> &)>;

    inline auto AsNumber(const string &input) -> Number
    {
        return stoi(input);
    }

    auto TopTwoNumbersRemoved(stack<Number> &numbers) -> tuple<Number, Number>
    {
        Number right = numbers.top();

        numbers.pop();

        Number left = numbers.top();

        numbers.pop();
        return { left, right };
    }

    void Add(stack<Number> &numbers, stack<Operation> &)
    {
        auto top_two = TopTwoNumbersRemoved(numbers);

        numbers.push(get<0>(top_two) + get<1>(top_two));
    }

    void Subtract(stack<Number> &numbers, stack<Operation> &)
    {
        auto top_two = TopTwoNumbersRemoved(numbers);

        numbers.push(get<0>(top_two) - get<1>(top_two));
    }

    void Multiply(stack<Number> &numbers, stack<Operation> &)
    {
        auto top_two = TopTwoNumbersRemoved(numbers);

        numbers.push(get<0>(top_two) * get<1>(top_two));
    }

    void Divide(stack<Number> &numbers, stack<Operation> &)
    {
        auto top_two = TopTwoNumbersRemoved(numbers);

        numbers.push(get<0>(top_two) / get<1>(top_two));
    }

    void Equals(stack<Number> &numbers, stack<Operation> &operations)
    {
        while (!operations.empty())
        {
            PerformOperation(numbers, operations);
        }
    }

    // Map Operation to function via constant-time array lookup
    std::array<OperationDelegate, Operation::LAST> Operations =
    {
        nullptr,
        Add,
        Subtract,
        Multiply,
        Divide,
        Equals
    };

    constexpr auto WeAreInputtingANumber(Calculator::State &calculator_state) -> bool
    {
        return calculator_state.current_operation == NONE;
    }

    void DisplayTopOfNumberStack(Calculator::State &calculator_state)
    {
        calculator_state.display = to_string( calculator_state.numbers.top() );
    }

    void StoreDisplayOnNumberStack(Calculator::State &calculator_state)
    {
        calculator_state.numbers.push( AsNumber(calculator_state.display) );
    }

    void DuplicateTopOfNumberStack(Calculator::State &calculator_state)
    {
        calculator_state.numbers.push( calculator_state.numbers.top() );
    }

    void ClearCurrentOperation(Calculator::State &calculator_state)
    {
        calculator_state.display.clear();
        calculator_state.current_operation = NONE;
    }

    void PushOperation(Calculator::State &calculator_state, const Operation operation)
    {
        if (WeAreInputtingANumber(calculator_state))
        {
            StoreDisplayOnNumberStack(calculator_state);

            // If we are about to put a lower-priority operation on the stack,
            // we can perform the operation of the, higher priority, current top
            // of stack as an optimization.
            if (!calculator_state.operations.empty() && IsOperationPrecedentLessThanOrEqual(operation, calculator_state.operations.top()))
            {
                PerformOperation(calculator_state);
            }
            // We can proceed normally now

            calculator_state.operations.push(operation);
            if (operation == EQUALS)
                ClearCurrentOperation(calculator_state);
            else
                calculator_state.current_operation = operation;
        }
        else
        {
            // We currently have another operation in effect.

            if (operation == EQUALS)
            {
                // Duplicate the top item on the stack and perform the operation...
                DuplicateTopOfNumberStack(calculator_state);

                calculator_state.operations.push(operation);
                ClearCurrentOperation(calculator_state);
            }
            else
            {
                // Let's reset it to THIS operation.
                calculator_state.current_operation = operation;
            }
        }
    }

    void PerformOperation(stack<Number> &numbers, stack<Operation> &operations)
    {
        Operation operation = operations.top();

        operations.pop();
        Operations[operation](numbers, operations);
    }

    void PerformOperation(Calculator::State &calculator_state)
    {
        // Transform the call into the other, simpler and possibly recursive, call.
        PerformOperation(calculator_state.numbers, calculator_state.operations);
    }

    void InsertDigitIntoDisplay(Calculator::State &calculator_state, const char digit)
    {
        calculator_state.display.push_back(digit);
    }

    bool IsOperationPrecedentLessThanOrEqual(const Operation left, const Operation right)
    {
        return (OperationLevel[left] == OperationLevel[right]) ||
               (OperationLevel[left] < OperationLevel[right]);
    }
}

void Calculator::pressKey(const char key)
{
    if (isdigit(key))
    {
        if (!WeAreInputtingANumber(_state))
        {
            // First time pressing a digit after an operator.
            // Clear the display and prepare for showing a new number.
            ClearCurrentOperation(_state);

            // Now we ARE inputting a number...
        }

        assert(WeAreInputtingANumber(_state));

        InsertDigitIntoDisplay(_state, key);
    }
    else if (key == '+')
    {
        PushOperation(_state, PLUS);
    }
    else if (key == '-')
    {
        PushOperation(_state, MINUS);
    }
    else if (key == '*')
    {
        PushOperation(_state, MULTIPLY);
    }
    else if (key == '/')
    {
        PushOperation(_state, DIVIDE);
    }
    else if (key == '=')
    {
        PushOperation(_state, EQUALS);
        PerformOperation(_state);
        DisplayTopOfNumberStack(_state);
    }
}
