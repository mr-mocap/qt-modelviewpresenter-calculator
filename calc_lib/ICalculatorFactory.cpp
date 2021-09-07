#include "ICalculatorFactory.h"

using namespace std;

ICalculatorFactory::~ICalculatorFactory()
{
}

unique_ptr<Calculator> ICalculatorFactory::createModel()
{
    return make_unique<Calculator>();
}

unique_ptr<QCalculatorView> ICalculatorFactory::createView()
{
#if 0
    return make_unique<CalculatorView>();
#else
    return nullptr;
#endif
}

unique_ptr<CalculatorPresenter> ICalculatorFactory::createPresenter()
{
#if 0
    return make_unique<CalculatorPresenter>();
#else
    return nullptr;
#endif
}
