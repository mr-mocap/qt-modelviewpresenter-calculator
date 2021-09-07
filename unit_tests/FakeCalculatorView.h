#ifndef FAKECALCULATORVIEW_H
#define FAKECALCULATORVIEW_H

#include <gmock/gmock.h>
#include "CalculatorPresenter.h"
#include "ICalculatorView.h"

#include <memory>

using namespace std;

class FakeCalculatorView : public ICalculatorView
{
public:
    FakeCalculatorView(CalculatorPresenter &presenter);
    ~FakeCalculatorView() = default;

    void updateCurrentResult(const std::string_view view_of_result) override;

    void pressKey(char key) override;

    std::string_view currentResult() const override
    {
        return _curentResult;
    }
private:
    string _curentResult = "0"s;
};

#endif // FAKECALCULATORVIEW_H
