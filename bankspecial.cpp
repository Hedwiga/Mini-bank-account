/*
 * Filename: bankspecial.cpp
 */
#include "bankspecial.h"

BankSpecial::BankSpecial(int accNum, int PIN, QString name) : BankAccount(accNum, PIN, name)
{
    setCommission(0);
}

bool BankSpecial::withdraw(double sum)
{
    double currentBalance = getBalance();
    if( currentBalance - sum < 0)
        return false;
    else setBalance(currentBalance - sum);
    return true;
}
