/*
 * Filename: register.h
 */
#ifndef REGISTER_H
#define REGISTER_H
#include "login.h"
#include "iofunctions.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "bankaccount.h"
#include <QString>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:

    void on_reg_clicked();

    void on_cancel_clicked();

    void on_name_textChanged(const QString &arg1);

    void on_pin_textChanged(const QString &arg1);
    void typeChosen();

private:
    int accNum;
    bool nameIsCorrect;
    bool pinIsCorrect;
    bool typeIsChosen;

    int createAccount();
    TypeAccount defineAccountType();

    Ui::Register *ui;
};

#endif // REGISTER_H
bool checkName(QString name);
