/*
 * Filename: login.cpp
 */
#include "login.h"
#include "ui_login.h"
#include "account.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

bool Login::readClient(QString number, QString password)
{
    QString clientInfo;
    bool result = false;
    bool clientExist = findClientInData(clientInfo, number);
    bool correctPassword = checkCorrectPIN(clientInfo, password);
    if(clientExist)
    {
        if(correctPassword)  
            result = writeCurrent(clientInfo);
        else
            QMessageBox::warning(this,"Warning", "Incorrect password");
    }
    else
         QMessageBox::warning(this,"Warning", "Client doesn't exist");
    return result;
}

bool Login::checkCorrectPIN(QString clientInfo, QString pin)
{
    QString currentPIN = getValue(clientInfo, BankAccount::Pin);
    return currentPIN == pin;
}

void Login::on_number_textChanged(const QString &arg1)
{
    numIsCorrect = checkNum(arg1);
}

void Login::on_pin_textChanged(const QString &arg1)
{
    pinIsCorrect = checkPin(arg1);
}

void Login::on_logIn_clicked()
{
    if(!numIsCorrect || !pinIsCorrect)
    {
        QMessageBox::information(this,"Failure", "Fields are filled incorrectly");
        return;
    }
    QString pin = ui->pin->text();
    QString number = ui->number->text();


    if(readClient(number, pin))
    {
        QMessageBox::information(this, "Logged in", "Welcome!");
        Account * accountDialog = new Account;
        accountDialog->setModal(true);
        accountDialog->exec();
    }
    else
        QMessageBox::information(this,"Failure", "Impossible to log in");
    return;
}

void Login::on_cancel_clicked()
{
    close();
}
