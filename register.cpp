/*
 * Filename: register.cpp
 */
#include "register.h"
#include "ui_register.h"
#include <algorithm>
#include "bankaccount.h"
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    nameIsCorrect = pinIsCorrect = typeIsChosen = 0;
    QCheckBox * typeAccount[TYPES] = {ui->def, ui->vip, ui->special };
    for(int i = 0; i < TYPES; ++i)
        connect(typeAccount[i], SIGNAL(toggled(bool)), this, SLOT(typeChosen()));
}

Register::~Register()
{
    delete ui;
}

void Register::on_reg_clicked()
{
    if(!nameIsCorrect || !pinIsCorrect || !typeIsChosen)
    {
        QMessageBox::information(this,"Failure", "Fields are filled incorrectly");
        return;
    }
    accNum = createAccount();
    if(accNum) {
        QString msg = "Registration is successful.\n Your account number:" + QString::number(accNum);
        QMessageBox::information(this,"Success", msg);
    }
    else
        QMessageBox::information(this,"Failure", "Registration is failed");
    close();

}

void Register::on_cancel_clicked()
{
    close();
}

bool checkName(QString name)
{
    if(name.isEmpty() || name.length() > NAME_LEN)
        return false;
    for(int i = 0; i < name.length(); ++i)
        if(!name.at(i).isLetterOrNumber())
            return false;
    return true;
}

void Register::on_name_textChanged(const QString &arg1)
{
    nameIsCorrect = checkName(arg1);
}

void Register::on_pin_textChanged(const QString &arg1)
{
    pinIsCorrect = checkPin(arg1);
}

void Register::typeChosen()
{
    typeIsChosen = true;
}

int Register::createAccount()
{
    TypeAccount typeAccount = defineAccountType();
    if(!typeAccount)
        return false;
    QString pin = ui->pin->text();
    QString name = ui->name->text();
    return writeClientToData(name, pin, typeAccount);
}

TypeAccount Register::defineAccountType()
{
    TypeAccount type = None;
    QCheckBox * typeAccount[TYPES] = {ui->def, ui->special, ui->vip};
    for(int i = 0 ; i < TYPES; ++i)
        if(typeAccount[i]->checkState())
        {
            switch(i + 1)
            {
            case Default:
                type = Default;
                break;
            case Special:
                type = Special;
                break;
            case VIP:
                type = VIP;
                break;
            }
        }
    return type;

}




