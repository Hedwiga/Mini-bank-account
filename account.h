/*
 * Filename: account.h
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDialog>
#include "QStringList"
#include "bankaccount.h"
#include "bankdefault.h"
#include "bankspecial.h"
#include "municipal.h"
#include "credit.h"
#include "recharge.h"
#include "register.h"
#include "transfer.h"
#include "withdraw.h"
#include "bankvip.h"

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr);

    ~Account();

private slots:
    void on_municipal_clicked();

    void on_transfer_clicked();

    void on_withdraw_clicked();

    void on_recharge_clicked();

    void on_credit_clicked();

    void on_transactions_clicked();

    void on_quit_clicked();
protected:
    BankAccount * basic;
private:
    QString clientInfo;
    TypeAccount type;
    QString typeStr;
    bool readCurrentClient();
    void defineType();
    void setBaseInfo();
    void createDefault();
    void createSpecial();
    void createVIP();
    void writeInfo() const;
    Ui::Account *ui;
};

#endif // ACCOUNT_H
