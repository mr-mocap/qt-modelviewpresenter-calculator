#ifndef QCALCULATORPRESENTER_H
#define QCALCULATORPRESENTER_H

#include <QObject>
#include "CalculatorPresenter.h"


class QCalculatorPresenter : public QObject,
                             public CalculatorPresenter
{
    Q_OBJECT
public:
    explicit QCalculatorPresenter(QObject *parent = nullptr);

    static void RegisterType();

signals:

protected:
    Calculator _calculator;
};

#endif // QCALCULATORPRESENTER_H
