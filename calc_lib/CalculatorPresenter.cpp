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

    _updateView();
}

string_view CalculatorPresenter::display() const
{
    return model().state().display;
}

void CalculatorPresenter::pressKey(const char key)
{
    model().pressKey(key);
    _updateView();
}

void CalculatorPresenter::_updateView()
{
    if (view())
        view()->updateCurrentResult(model().state().display);
}
