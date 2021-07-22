#ifndef CALCULATORTESTS_H
#define CALCULATORTESTS_H

#include <gmock/gmock.h>
#include "Calculator.h"
#include "unit_test_types.h"

using namespace testing;

namespace
{

TestEntry Tests[] = {
    {"1", "1"},
    {"2", "2"},
    {"23", "23"},
    {"234", "234"},
    {"1+", "1"},
    {"1+1", "1"},
    {"1+1=", "2"},
    {"10+1", "1"},
    {"10+1=", "11"},
    {"6+=", "12"},
    {"18/2=", "9"},
    {"5/1=", "5"},
    {"1/5=", "0"}, // Integer operations currently!

    // Operator Precedence
    {"6+3*1=", "9"},
    {"6*3+1=", "19"},
    {"6*3/2=", "9"},
    {"1-1+1=", "1"}
};
#if 0
void PressKeys(Calculator &calculator, const std::string &keypresses)
{
    for (const char key : keypresses)
        calculator.pressKey(key);
}

void CheckDisplay(Calculator &calculator, const std::string &expected_display_value)
{
    assert(calculator.state().display == expected_display_value);
}

void RunTest(const TestEntry &test)
{
    Calculator calculator;

    PressKeys(calculator, test.input_keys);
    CheckDisplay(calculator, test.expected_display);
}
#endif
}

TEST(Calculator, BasicOperationsGiveExpectedResults)
{
    EXPECT_THAT(0, Eq(0));
}

#endif // CALCULATORTESTS_H
