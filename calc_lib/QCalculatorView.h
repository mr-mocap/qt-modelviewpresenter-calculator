#ifndef QCALCULATORVIEW_H
#define QCALCULATORVIEW_H

#include <QQuickItem>
#include "ICalculatorView.h"
#include <string>

class QCalculatorPresenter;

class QCalculatorView : public QQuickItem, public ICalculatorView
{
    Q_OBJECT

    Q_PROPERTY(QCalculatorPresenter *model  READ qmodel  WRITE setQModel  NOTIFY modelChanged)
    Q_PROPERTY(QString               result READ qresult                  NOTIFY resultChanged)
public:
    explicit QCalculatorView(QQuickItem *parent = nullptr);
    ~QCalculatorView() = default;

    static void RegisterType();

          QCalculatorPresenter *qmodel();
    const QCalculatorPresenter *qmodel() const;

    void setQModel(QCalculatorPresenter *new_model);

    QString qresult() const;

    void updateCurrentResult(const std::string_view view_of_result) override;

    std::string_view currentResult() const override;

    void pressKey(const char key) override;

signals:
    void modelChanged();
    void resultChanged();

public slots:
    void press(QString key);

protected:
    std::string _currentResult;
};

#endif // QCALCULATORVIEW_H
