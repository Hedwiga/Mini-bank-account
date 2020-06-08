/*
 * Filename: login.h
 */
#ifndef LOGIN_H
#define LOGIN_H
#include "iofunctions.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include "bankaccount.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:

    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_number_textChanged(const QString &arg1);

    void on_pin_textChanged(const QString &arg1);

    void on_logIn_clicked();

    void on_cancel_clicked();

private:
    bool numIsCorrect;
    bool pinIsCorrect;
    bool readClient(QString number, QString pin);
    bool checkCorrectPIN(QString clientInfo, QString pin);
    Ui::Login *ui;
};


#endif // LOGIN_H
