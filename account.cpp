/*
 * Filename: account.cpp
 */
#include "account.h"
#include "ui_account.h"
#include "bankaccount.h"

Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);
    if(!readCurrentClient())
    {
        QMessageBox::warning(this, "Failure", "Cannot reach data");
        close();
    }
    defineType();

    switch(type)
    {
    case Default:
        createDefault();
        break;
    case Special:
        createSpecial();
        break;
    case VIP:
        createVIP();
        break;
    default:
        QMessageBox::warning(this, "Failure", "Undefined type");
        close();
    }
    setBaseInfo();
    writeInfo();
}

Account::~Account()
{
    delete ui;
}


bool Account::readCurrentClient()
{
    QFile current("current.txt");
    if(!current.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warning", "Cannot reach data");
        return false;
    }

    QTextStream in(&current);
    clientInfo = in.readLine();
    return true;
}

void Account::defineType()
{
    typeStr = clientInfo.section(' ', BankAccount::Type, BankAccount::Type);
    if(typeStr == "1")
    {
        typeStr = "Default";
        type = Default;
    }
    else if(typeStr == "2")
    {
        typeStr = "Special";
        type = Special;
    }
    else if(typeStr == "3")
    {
        typeStr = "VIP";
        type = VIP;
    }
    else
        type = None;
}

void Account::createDefault()
{
    BankDefault * bankDefault = new BankDefault;
    basic = bankDefault;
}

void Account::createSpecial()
{
    BankSpecial * bankSpecial = new BankSpecial;
    basic = bankSpecial;
}

void Account::createVIP()
{
    BankVIP * bankVIP = new BankVIP;
    basic = bankVIP;
    QString credit = clientInfo.section(' ', BankAccount::Credit, BankAccount::Credit);
    bankVIP->createCredit(credit.toDouble());
    ui->creditLine->setText(credit);
    ui->credit->setEnabled(true);
}

void Account::writeInfo() const
{
    ui->name->setText(basic->getName());
    ui->type->setText(typeStr);
    ui->number->setText(QString::number(basic->getNum()));
    ui->balance->setText(QString::number(basic->getBalance()));
}

void Account::setBaseInfo()
{
    QString number = clientInfo.section(' ', BankAccount::Number, BankAccount::Number);
    QString pin = clientInfo.section(' ', BankAccount::Pin, BankAccount::Pin);
    QString name = clientInfo.section(' ', BankAccount::Name, BankAccount::Name);
    QString balance = clientInfo.section(' ', BankAccount::Balance, BankAccount::Balance);
    QString municipal = clientInfo.section(' ', BankAccount::Municipal, BankAccount::Municipal);
    basic->setName(name);
    basic->setBalance(balance.toDouble());
    basic->setNum(number.toInt());
    basic->setPin(pin.toInt());
    basic->setMunicipal(municipal.toDouble());
}


void Account::on_municipal_clicked()
{
    Municipal municipalDialog;
    int commission = basic->getCommission();
    double municipal = basic->getMunicipal();
    municipalDialog.setValues(commission, municipal);
    municipalDialog.setModal(true);
    municipalDialog.exec();
    if(!municipalDialog.result())
        return;
    if(!basic->payBills())
        QMessageBox::warning(this, "Error", "Not enough money");
    else
        QMessageBox::information(this, "Success", "Municipal is paid");
    writeInfo();

}

void Account::on_transfer_clicked()
{
    Transfer transferDialog;

    int commission = basic->getCommission();
    transferDialog.setCommission(commission);
    transferDialog.setModal(true);
    transferDialog.exec();
    if(!transferDialog.result())
        return;
    int receiver = transferDialog.getReceiver();
    double sum = transferDialog.getSum();
    if(!basic->withdraw(sum))
    {
        QMessageBox::warning(this, "Error", "Not enough money");
        return;
    }
    if(!basic->transfer(sum, receiver))
    {
        QMessageBox::warning(this, "Error", "Can't transfer money");
        double total = transferDialog.getTotal();
        basic->recharge(total);
        return;
    }
    else
        QMessageBox::information(this, "Success", "Transfer is successful");

    writeInfo();

}

void Account::on_withdraw_clicked()
{
    Withdraw withdrawDialog;
    int commission = basic->getCommission();
    withdrawDialog.setCommission(commission);
    withdrawDialog.setModal(true);
    withdrawDialog.exec();
    if(!withdrawDialog.result())
        return;
    double sum = withdrawDialog.getSum();
    if(!basic->withdraw(sum))
        QMessageBox::warning(this, "Error", "Not enough money");
    else
        QMessageBox::information(this, "Success", "Withdraw is successful");
    writeInfo();
}

void Account::on_recharge_clicked()
{
    Recharge rechargeDialog;
    rechargeDialog.setModal(true);
    rechargeDialog.exec();
    if(!rechargeDialog.result())
        return;
    double sum = rechargeDialog.getSum();
    basic->recharge(sum);
    QMessageBox::information(this, "Success", "Recharge is successful");
    writeInfo();
}

void Account::on_credit_clicked()
{
    Credit creditDialog;
    creditDialog.setModal(true);
    creditDialog.exec();
    if(!creditDialog.result())
        return;
    double credit = creditDialog.getSum();
    ui->creditLine->setText(QString::number(credit));
    basic->recharge(credit);
    QMessageBox::information(this, "Success", "Credit is created");
    writeInfo();
}

void Account::on_transactions_clicked()
{
    QLinkedList<BankAccount::Transaction> history = basic->getTransactions();
    QString list = "Receiver and sum:\n";
    BankAccount::Transaction temp;
    while(!history.isEmpty())
    {
        temp = history.takeFirst();
        list += QString::number(temp.receiver) + ' ' + QString::number(temp.sum) + '\n';
    }
    QMessageBox::information(this, "Transactions", list);
}

void Account::on_quit_clicked()
{
    QFile data("data.txt");
    if(!data.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::information(this, "Failure", "Data is not saved");
        close();
    }

    QTextStream out(&data);
    int num = basic->getNum();
    int pin = basic->getPin();
    QString name = basic->getName();
    double balance = basic->getBalance();
    double credit = ui->creditLine->text().toDouble();
    double municipal = basic->getMunicipal();
    QString newInfo = makeClient(num, pin, type, name,
                            balance, credit, municipal);
    refreshDataAboutClient(newInfo, clientInfo, out);
    QFile current("current.txt");
    current.open(QIODevice::WriteOnly | QIODevice::Text);
    current.close();
    data.close();
    close();
}
