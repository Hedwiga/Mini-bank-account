/*
 * Filename: bankaccount.h
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QMainWindow>
#include <QLinkedList>
#include "customer.h"
#define NUMBER_LEN 10
#define PIN_LEN 4
#define NAME_LEN 10
#define TYPES 3

class BankAccount : protected Customer
{
public:
    typedef struct
    {
        int receiver;
        double sum;
    } Transaction;
private:
    QLinkedList <Transaction> transactionList;
    int accNum;
    double balance;
    int PIN;
    int commission;
    double municipal;
protected:
    void setCommission(int percent);
public:
    enum Value {Number, Pin, Type, Name, Balance, Credit, Municipal, Values};
    BankAccount();
    BankAccount(int accNum, int PIN, QString name);
    using Customer::getName;
    using Customer::setName;
    virtual void recharge(double sum);
    virtual bool withdraw(double sum) = 0;
    bool transfer(double sum, int receiver);
    double getBalance() const;
    void setBalance(double sum);
    int getNum() const;
    void setNum(int accNum);
    int getPin() const;
    void setPin(int pin);
    void storeTransaction(double sum, int receiver);
    double getCommission() const;
    void setMunicipal(double sum);
    double getMunicipal() const;
    bool payBills();
    QLinkedList<Transaction> getTransactions() const;
};

#endif // BANKACCOUNT_H
