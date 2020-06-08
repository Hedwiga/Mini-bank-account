/*
 * Filename: municipal.h
 */
#ifndef MUNICIPAL_H
#define MUNICIPAL_H
#include <QDialog>

namespace Ui {
class Municipal;
}

class Municipal : public QDialog
{
    Q_OBJECT

public:
    explicit Municipal(QWidget *parent = nullptr);
    void setValues(double curCommission, double curMunicipal);
    ~Municipal();

private slots:
    void on_pay_clicked();

    void on_cancel_clicked();

private:
    double commission;
    double municipal;


    Ui::Municipal *ui;
};

#endif // MUNICIPAL_H
