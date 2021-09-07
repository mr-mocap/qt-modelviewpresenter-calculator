#ifndef ICALCULATORFACTORY_H
#define ICALCULATORFACTORY_H

#include "Calculator.h"
#include "QCalculatorView.h"
#include "CalculatorPresenter.h"
#include <memory>

class ICalculatorFactory
{
public:
    virtual ~ICalculatorFactory() = 0;

    std::unique_ptr<Calculator>          createModel();
    std::unique_ptr<QCalculatorView>      createView();
    std::unique_ptr<CalculatorPresenter> createPresenter();
};

#endif // ICALCULATORFACTORY_H
