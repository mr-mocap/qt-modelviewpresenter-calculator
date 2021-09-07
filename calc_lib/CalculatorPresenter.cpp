#include "CalculatorPresenter.h"

using namespace std;

CalculatorPresenter::CalculatorPresenter(Calculator &model)
    :
    _model(model)
{
}

CalculatorPresenter::~CalculatorPresenter()
{
    _view = nullptr;
}

void CalculatorPresenter::setView(ICalculatorView *view)
{
    _view = view;

    // Update the view...
}

string_view CalculatorPresenter::display() const
{
    return model().state().display;
}

void CalculatorPresenter::pressKey(const char key)
{
    model().pressKey(key);
    if (view())
        view()->updateCurrentResult(model().state().display);
}
