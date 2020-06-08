/*
 * Filename: bankvip.cpp
 */
#include "bankvip.h"

BankVIP::BankVIP() : BankAccount()
{
    percent = standart;
    credit = 0;
    setCommission(Commission);
}

BankVIP::BankVIP(int accNum, int PIN, QString name, double newCredit) :
    BankAccount(accNum, PIN, name)
{
    credit = newCredit;
    setCommission(Commission);
}

bool BankVIP::withdraw(double sum)
{
    sum = sum * getCommission() / 100 + sum;
    double currentBalance = getBalance();
    if( currentBalance - sum < 0)
        return false;
    else setBalance(currentBalance - sum);
    return true;
}

double BankVIP::getCredit() const
{
    return credit;
}

double BankVIP::getPercent(double sum) const
{
    if(sum > Limit)
        return high;
    return standart;
}

bool BankVIP::createCredit(double sum)
{
    if(credit)
        return false;
    percent = getPercent(sum);
    recharge(sum);
    return true;
}

