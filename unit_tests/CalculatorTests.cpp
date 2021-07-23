#ifndef CALCULATORTESTS_H
#define CALCULATORTESTS_H

#include <gmock/gmock.h>
#include "Calculator.h"
#include "unit_test_types.h"

using namespace testing;

class CalculatorTest : public testing::TestWithParam<TestEntry> {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
};

namespace
{
TestEntry TestValues[] = {
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

void PressKeys(Calculator &calculator, const std::string &keypresses)
{
    for (const char key : keypresses)
        calculator.pressKey(key);
}

}

TEST_P(CalculatorTest, BasicInputGivesExpectedResults)
{
    Calculator calculator;

    PressKeys(calculator, GetParam().input_keys);

    EXPECT_THAT(calculator.state().display, Eq(GetParam().expected_display));
}

INSTANTIATE_TEST_SUITE_P(BasicInputTest, CalculatorTest, testing::ValuesIn(TestValues));

#endif // CALCULATORTESTS_H
