#ifndef CALCULATORVIEWTESTFIXTURE_H
#define CALCULATORVIEWTESTFIXTURE_H

#include <gmock/gmock.h>
#include "CalculatorPresenter.h"
#include "unit_test_types.h"
#include "FakeCalculatorView.h"
#include <memory>

using namespace testing;
using namespace std;

class CalculatorViewTestFixture : public Test
{
public:
    CalculatorViewTestFixture()
        :
    _presenter(_model)
    {
    }

    void pressKeys(const std::string &keypresses)
    {
        for (const char key : keypresses)
            view()->pressKey(key);
    }

    ICalculatorView *view() { return _view.get(); }

protected:

    void SetUp() override {
        _view = make_unique<FakeCalculatorView>(_presenter);
        _presenter.setView(view());
    }

    void TearDown() override {
        _view.reset();
    }

private:
    Calculator                     _model;
    CalculatorPresenter            _presenter;
    unique_ptr<FakeCalculatorView> _view;
};


/** Turn CalculatorViewTestFixture into a parameterized version.
 *
 */
class CalculatorViewParameterizedTestFixture : public CalculatorViewTestFixture,
                                               public WithParamInterface<TestEntry> {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
public:
};

#endif // CALCULATORVIEWTESTFIXTURE_H
