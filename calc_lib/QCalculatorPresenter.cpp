#include "QCalculatorPresenter.h"
#include <QtQml>


QCalculatorPresenter::QCalculatorPresenter(QObject *parent)
    :
    QObject(parent),
    CalculatorPresenter(_calculator)
{
}

void QCalculatorPresenter::RegisterType()
{
    qmlRegisterType<QCalculatorPresenter>("Qt.example.calculatorpresenter", 1, 0, "CalculatorPresenter");
}
