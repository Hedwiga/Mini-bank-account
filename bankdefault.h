/*
 * Filename: bankdefault.h
 */
#ifndef BANKDEFAULT_H
#define BANKDEFAULT_H
#include "bankaccount.h"

class BankDefault : public BankAccount
{
private:
    enum {Commission = 10};
public:
    BankDefault();
    BankDefault(int accNum, int PIN, QString name);
    virtual bool withdraw(double sum);
};

#endif // BANKDEFAULT_H
