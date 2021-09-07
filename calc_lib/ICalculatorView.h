#ifndef ICALCULATORVIEW_H
#define ICALCULATORVIEW_H

#include <string_view>

class CalculatorPresenter;

class ICalculatorView
{
public:
    ICalculatorView(CalculatorPresenter &presenter) : _presenter(&presenter) { }
    virtual ~ICalculatorView() = default;

    virtual void updateCurrentResult(const std::string_view view_of_result) = 0;

    // General User-Input
    virtual void pressKey(char key) = 0;

    virtual std::string_view currentResult() const = 0;

protected:
    CalculatorPresenter *_presenter = nullptr;

    explicit ICalculatorView() = default;
};

#endif // ICALCULATORVIEW_H
