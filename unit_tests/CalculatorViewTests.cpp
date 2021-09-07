#include "CalculatorViewTestFixture.h"


TEST_F(CalculatorViewTestFixture, NewlyConstructedObjectDisplaysZero)
{
    EXPECT_THAT(view()->currentResult(), StrEq("0"));
}

TEST_P(CalculatorViewParameterizedTestFixture, InputtingTestDataAndCheckingDisplayAfterward)
{
    pressKeys(GetParam().input_keys);

    EXPECT_THAT(view()->currentResult(), StrEq(GetParam().expected_display));
}

INSTANTIATE_TEST_SUITE_P(InputDigitsOnly, CalculatorViewParameterizedTestFixture, ValuesIn(
   (const TestEntry []){
                         {"1", "1"},
                         {"2", "2"},
                         {"23", "23"},
                         {"234", "234"}
}));

INSTANTIATE_TEST_SUITE_P(InputDigitsAndAnOperator, CalculatorViewParameterizedTestFixture, ValuesIn(
   (const TestEntry []){
                         {"1+", "1"},
                         {"2+", "2"},
                         {"23+", "23"}
}));
