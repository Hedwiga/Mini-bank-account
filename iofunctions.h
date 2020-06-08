/*
 * Filename: iofunction.h
 */
#ifndef FIOFUNCTIONS_H
#define FIOFUNCTIONS_H
#include <QString>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include "bankaccount.h"
enum TypeAccount {None, Default, Special, VIP};
bool findClientInData(QString & clientInfo, const QString & accNum);
bool rechargeInData(const QString & accNum, double newBalance);
void changeBalance(QString &clientInfo, QString newBalance);
int getPosition(QString & clientInfo, const QString & accNum, QTextStream & in);
int writeClientToData(const QString & name, const QString & pin, TypeAccount type);
QString makeClient(int num, int pin, TypeAccount type, const QString & name,
                   double balance = 0, double credit = 0, double municipal = 0);
void refreshDataAboutClient(const QString & newInfo, const QString &oldInfo, QTextStream &in);
bool getLastNum(QString & last, QTextStream & in);
bool writeCurrent(const QString & info);
bool checkNum(const QString & num);
bool checkPin(const QString & pin);
QString getValue(const QString & info, BankAccount::Value val);
#endif // FIOFUNCTIONS_H
