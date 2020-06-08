/*
 * Filename: transfer.cpp
 */
#include "transfer.h"
#include "ui_transfer.h"

Transfer::Transfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
    numIsCorrect = false;
    receiver = 0;
}

Transfer::~Transfer()
{
    delete ui;
}

int Transfer::getReceiver() const
{
    return receiver;
}

double Transfer::getTotal() const
{
    return total;
}

double Transfer::getSum() const
{
    return sum;
}

void Transfer::setCommission(int curCommission)
{
    commission = curCommission;
    ui->commission->setText(QString::number(commission));
}

void Transfer::on_cancel_clicked()
{
    reject();
}

void Transfer::on_transfer_clicked()
{
    if(numIsCorrect)
    {
        accept();
        return;
    }
    QMessageBox::warning(this, "Error", "Incorrect receiver");
}

void Transfer::on_sum_valueChanged(double newSum)
{
    sum = newSum;
    total = newSum * commission / 100 + newSum;
    ui->total->setText(QString::number(total));
}

void Transfer::on_to_textChanged(const QString &num)
{
    numIsCorrect = checkNum(num);
    if(numIsCorrect)
        receiver = num.toInt();
}
