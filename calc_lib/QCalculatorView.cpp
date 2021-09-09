#include "QCalculatorView.h"
#include "QCalculatorPresenter.h"


void QCalculatorView::RegisterType()
{
    qmlRegisterType<QCalculatorView>("Qt.example.calculatorview", 1, 0, "CalculatorView");
}

QCalculatorView::QCalculatorView(QQuickItem *parent)
    :
    QQuickItem(parent),
    ICalculatorView()
{
}

void QCalculatorView::updateCurrentResult(const std::string_view new_value)
{
    // Are they different?
    if (new_value != _currentResult)
    {
        _currentResult.assign(new_value.data(), new_value.size());
        emit resultChanged();
    }
}

std::string_view QCalculatorView::currentResult() const
{
    return _currentResult;
}

void QCalculatorView::pressKey(const char key)
{
    if (_presenter)
        _presenter->pressKey(key);
}

void QCalculatorView::press(QString key)
{
    Q_ASSERT(key.size() == 1);

    pressKey(key.front().unicode());
}

void QCalculatorView::setQModel(QCalculatorPresenter *new_model)
{
    if (static_cast<CalculatorPresenter *>(new_model) != _presenter)
    {
        _presenter = new_model;
        _presenter->setView(this);
        emit modelChanged();
    }
}

QCalculatorPresenter *QCalculatorView::qmodel()
{
    return _presenter ? static_cast<QCalculatorPresenter *>(_presenter) : nullptr;
}

const QCalculatorPresenter *QCalculatorView::qmodel() const
{
    return _presenter ? static_cast<QCalculatorPresenter *>(_presenter) : nullptr;
}

QString QCalculatorView::qresult() const
{
    return QString::fromStdString(_currentResult);
}
