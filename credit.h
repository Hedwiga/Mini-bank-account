/*
 * Filename: credit.h
 */
#ifndef CREDIT_H
#define CREDIT_H
#include <QDialog>

namespace Ui {
class Credit;
}

class Credit : public QDialog
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();
    double getSum();
private slots:
    void on_sum_valueChanged(double arg1);

    void on_getCredit_clicked();

    void on_cancel_clicked();

private:
    double sum;
    double percent;
    Ui::Credit *ui;
};

#endif // CREDIT_H
