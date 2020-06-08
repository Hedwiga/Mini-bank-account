/*
 * Filename: bankvip.h
 */
#ifndef BANKVIP_H
#define BANKVIP_H
#include "bankaccount.h"
const double standart = 5;
const double high = 8;
class BankVIP : public BankAccount
{
    double credit;
    double percent;
    enum {Commission = 8};
public:
    enum {Limit = 5000};
    BankVIP();
    BankVIP(int accNum, int PIN, QString name, double credit);
    virtual bool withdraw(double sum);
    double getPercent(double sum) const;
    double getCredit() const;
    bool createCredit(double sum);
};

#endif // BANKVIP_H
