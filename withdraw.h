/*
 * Filename: withdraw.h
 */
#ifndef WITHDRAW_H
#define WITHDRAW_H
#include <QDialog>

namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();
    void setCommission(double curCommission);
    double getTotal() const;
    double getSum() const;

private slots:
    void on_withdraw_clicked();

    void on_cancel_clicked();

    void on_sum_valueChanged(double sum);

private:
    double total;
    double sum;
    double commission;
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
