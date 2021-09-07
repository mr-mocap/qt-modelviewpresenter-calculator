#include "CalculatorPresenterTestFixture.h"


TEST_F(CalculatorPresenterTestFixture, NewlyConstructedObjectDisplaysZero)
{
    EXPECT_THAT(presenter().display(), StrEq("0"));
}

TEST_P(CalculatorPresenterParameterizedTestFixture, InputtingTestDataAndCheckingDisplayAfterward)
{
    pressKeys(GetParam().input_keys);

    EXPECT_THAT(presenter().display(), StrEq(GetParam().expected_display));
}

INSTANTIATE_TEST_SUITE_P(InputDigitsOnly, CalculatorPresenterParameterizedTestFixture, ValuesIn(
   (const TestEntry []){
                         {"1", "1"},
                         {"2", "2"},
                         {"23", "23"},
                         {"234", "234"}
}));

INSTANTIATE_TEST_SUITE_P(InputDigitsAndAnOperator, CalculatorPresenterParameterizedTestFixture, ValuesIn(
   (const TestEntry []){
                         {"1+", "1"},
                         {"2+", "2"},
                         {"23+", "23"}
}));
