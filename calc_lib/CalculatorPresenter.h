#ifndef CALCULATORPRESENTER_H
#define CALCULATORPRESENTER_H

#include "Calculator.h"
#include "ICalculatorView.h"


class CalculatorPresenter
{
public:
    CalculatorPresenter(Calculator &model);
    ~CalculatorPresenter();

          Calculator &model()       { return _model; }
    const Calculator &model() const { return _model; }

    const ICalculatorView *view() const { return _view; }
          ICalculatorView *view()       { return _view; }

    void setView(ICalculatorView *view);

    std::string_view display() const;

    void pressKey(const char key);
protected:
    Calculator      &_model;
    ICalculatorView *_view = nullptr;
};

#endif // CALCULATORPRESENTER_H
