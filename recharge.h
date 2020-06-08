/*
 * Filename: recharge.h
 */
#ifndef RECHARGE_H
#define RECHARGE_H
#include <QDialog>

namespace Ui {
class Recharge;
}

class Recharge : public QDialog
{
    Q_OBJECT

public:
    explicit Recharge(QWidget *parent = nullptr);
    double getSum() const;
    ~Recharge();

private slots:
    void on_sum_valueChanged(double arg1);

    void on_recharge_clicked();

    void on_cancel_clicked();

private:
    double sum;
    Ui::Recharge *ui;
};

#endif // RECHARGE_H
