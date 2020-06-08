/*
 * Filename: municipal.cpp
 */
#include "municipal.h"
#include "ui_municipal.h"

Municipal::Municipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Municipal)
{
    ui->setupUi(this);
}

void Municipal::setValues(double curCommission, double curMunicipal)
{
    commission = curCommission / 100;
    municipal = curMunicipal;
    ui->check->setText(QString::number(municipal));
    ui->commission->setText(QString::number(commission * municipal));
    ui->total->setText(QString::number(commission * municipal + municipal));
}

Municipal::~Municipal()
{
    delete ui;
}

void Municipal::on_pay_clicked()
{
    accept();
}

void Municipal::on_cancel_clicked()
{
    reject();
}
