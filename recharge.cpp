/*
 * Filename: recharge.cpp
 */
#include "recharge.h"
#include "ui_recharge.h"

Recharge::Recharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recharge)
{
    ui->setupUi(this);
}

double Recharge::getSum() const
{
    return sum;
}

Recharge::~Recharge()
{
    delete ui;
}

void Recharge::on_sum_valueChanged(double newSum)
{
    sum = newSum;
}

void Recharge::on_recharge_clicked()
{
    accept();
}

void Recharge::on_cancel_clicked()
{
    reject();
}
