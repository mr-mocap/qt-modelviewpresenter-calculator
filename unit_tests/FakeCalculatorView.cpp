#include "FakeCalculatorView.h"


FakeCalculatorView::FakeCalculatorView(CalculatorPresenter &presenter)
    :
    ICalculatorView(presenter)
{
}

void FakeCalculatorView::updateCurrentResult(const std::string_view view_of_result)
{
    _curentResult.assign(view_of_result.begin(), view_of_result.end());
}

void FakeCalculatorView::pressKey(char key)
{
    _presenter->pressKey(key);
}
