/*
 * Filename: credit.cpp
 */
#include "credit.h"
#include "ui_credit.h"
#include "login.h"
#include "bankvip.h"
Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

double Credit::getSum()
{
    return sum;
}

void Credit::on_sum_valueChanged(double newSum)
{
    if(sum < BankVIP::Limit)
        percent = standart;
    else
        percent = high;
    ui->percent->setText(QString::number(percent));
    sum = newSum;
}

void Credit::on_getCredit_clicked()
{
    accept();
}

void Credit::on_cancel_clicked()
{
    reject();
}
