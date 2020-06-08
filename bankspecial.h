/*
 * Filename: bankspecial.h
 */
#ifndef SPECIAL_H
#define SPECIAL_H
#include "bankaccount.h"

class BankSpecial : public BankAccount
{
private:
    enum {Extra = 5};
public:
    BankSpecial() : BankAccount() {}
    BankSpecial(int accNum, int PIN, QString name);
    virtual bool withdraw(double sum);

};

#endif // SPECIAL_H
