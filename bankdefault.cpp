/*
 * Filename: bankdefault.cpp
 */
#include "bankdefault.h"

BankDefault::BankDefault() : BankAccount()
{
    setCommission(Commission);
}
BankDefault::BankDefault(int accNum, int PIN, QString name) : BankAccount(accNum, PIN, name)
{
    setCommission(Commission);
}

bool BankDefault::withdraw(double sum)
{
    sum = sum * getCommission() / 100 + sum;
    double currentBalance = getBalance();
    if( currentBalance - sum < 0)
        return false;
    else setBalance(currentBalance - sum);
    return true;
}

