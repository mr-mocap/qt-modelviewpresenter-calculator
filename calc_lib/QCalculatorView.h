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
    Q_PROPERTY(QString               result READ qresult WRITE setQResult NOTIFY resultChanged)
public:
    explicit QCalculatorView(QQuickItem *parent = nullptr);
    ~QCalculatorView() = default;

    static void RegisterType();

          QCalculatorPresenter *qmodel();
    const QCalculatorPresenter *qmodel() const;

    void setQModel(QCalculatorPresenter *new_model);

    QString qresult() const;
    void    setQResult(QString result);

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
    QString     _currentResultQt;

    void updateBothNormalAndQtResult(const std::string_view new_value);
    void updateBothNormalAndQtResult(QString new_value);
};

#endif // QCALCULATORVIEW_H
