/*
 * Filename: bankaccount.cpp
 */
#include "bankaccount.h"
#include "iofunctions.h"
#include <QFile>
#include <QTextStream>

BankAccount::BankAccount() : Customer()
{
    accNum = 0;
    balance = 0;
    PIN = 0;
    commission = 0;
    municipal = 0;
}

BankAccount::BankAccount(int newNumber, int newPIN, QString newName) : Customer(newName)
{
    accNum = newNumber;
    balance = 0;
    PIN = newPIN;
    commission = 0;
    municipal = 0;
}
bool BankAccount::transfer(double sum, int receiver)
{
    QString receiverInfo;
    QString clientInfo;
    findClientInData(clientInfo, QString::number(accNum));
    bool receiverExist = findClientInData(receiverInfo, QString::number(receiver));
    QString oldBalance = getValue(receiverInfo, BankAccount::Balance);
    double newBalance = oldBalance.toDouble() + sum;

    if(!receiverExist)
        return false;
    if(!rechargeInData(QString::number(receiver), newBalance))
        return false;
    storeTransaction(sum, receiver);

    return true;

}

void BankAccount::recharge(double sum)
{
    balance += sum;
}

bool BankAccount::withdraw(double sum)
{
    if(balance - sum < 0)
        return false;
    else
        balance -= sum;
    return true;
}
double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::setBalance(double sum)
{
    balance = sum;
}

int BankAccount::getNum() const
{
    return accNum;
}

void BankAccount::setNum(int number)
{
    accNum = number;
}

int BankAccount::getPin() const
{
    return PIN;
}

void BankAccount::setPin(int newPin)
{
    PIN = newPin;
}

void BankAccount::storeTransaction(double newSum, int newReceiver)
{
    Transaction newTransaction;
    newTransaction.sum = newSum;
    newTransaction.receiver = newReceiver;
    transactionList << newTransaction;

}
void BankAccount::setCommission(int percent)
{
    commission = percent;
}

double BankAccount::getCommission() const
{
    return commission;
}

void BankAccount::setMunicipal(double sum)
{
    municipal = sum;
}

double BankAccount::getMunicipal() const
{
    return municipal;
}

bool BankAccount::payBills()
{
    if(this->withdraw(municipal))
    {
        municipal = 0;
        return true;
    }
    return false;
}

QLinkedList<BankAccount::Transaction> BankAccount::getTransactions() const
{
    return transactionList;
}
