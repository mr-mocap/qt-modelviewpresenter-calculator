#ifndef CALCULATORPRESENTERTESTFIXTURE_H
#define CALCULATORPRESENTERTESTFIXTURE_H

#include <gmock/gmock.h>
#include "CalculatorPresenter.h"
#include "unit_test_types.h"

using namespace testing;
using namespace std;

class CalculatorPresenterTestFixture : public Test
{
public:

    CalculatorPresenter &presenter() { return _presenter; }


    void pressKeys(const std::string &keypresses)
    {
        for (const char key : keypresses)
            presenter().pressKey(key);
    }

private:
    Calculator          _calculator;
    CalculatorPresenter _presenter { _calculator };
};

/** Turn CalculatorPresenterTestFixture into a parameterized version.
 *
 */
class CalculatorPresenterParameterizedTestFixture : public CalculatorPresenterTestFixture,
                                                    public WithParamInterface<TestEntry> {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
public:
};

#endif // CALCULATORPRESENTERTESTFIXTURE_H
