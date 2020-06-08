/*
 * Filename: withdraw.cpp
 */
#include "withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::setCommission(double curCommission)
{
    commission = curCommission;
    ui->commission->setText(QString::number(commission));
}

double Withdraw::getTotal() const
{
    return total;
}

double Withdraw::getSum() const
{
    return sum;
}

void Withdraw::on_withdraw_clicked()
{
    accept();
}

void Withdraw::on_cancel_clicked()
{
    reject();
}

void Withdraw::on_sum_valueChanged(double newSum)
{
    sum = newSum;
    total = newSum * commission / 100 + newSum;
    ui->total->setText(QString::number(total));
}
