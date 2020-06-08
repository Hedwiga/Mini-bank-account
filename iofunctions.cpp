/*
 * Filename: iofunctions.cpp
 */
#include "iofunctions.h"
bool findClientInData(QString &clientInfo, const QString &accNum)
{
    bool clientExist = false;
    QFile data("data.txt");
    if(!data.open(QIODevice::ReadOnly | QIODevice::Text))
        return clientExist;
    QTextStream in(&data);
    int pos = getPosition(clientInfo, accNum, in);
    if(pos >= 0)
        clientExist = true;
    data.close();
    return clientExist;
}

bool rechargeInData(const QString &accNum, double sum)
{
    bool result = false;
    QFile data("data.txt");
    if(!data.open(QIODevice::ReadWrite | QIODevice::Text))
        return result;
    QTextStream in(&data);
    QString oldInfo;
    if(!findClientInData(oldInfo, accNum))
        return result;
    QString newInfo = oldInfo;
    changeBalance(newInfo, QString::number(sum));
    refreshDataAboutClient(newInfo, oldInfo, in);
    data.close();
    return true;
}
void changeBalance(QString &clientInfo, QString newBalance)
{
    QString oldBalance = getValue(clientInfo, BankAccount::Balance);
    int posOfBalance = clientInfo.indexOf(oldBalance, 15);
    clientInfo.replace(posOfBalance, newBalance.length(), newBalance);
}
// Returns -1, if no such position
int getPosition(QString & clientInfo, const QString & accNum, QTextStream & in)
{
    int pos = -1;
    while(!in.atEnd())
    {
        pos = in.pos();
        clientInfo = in.readLine();
        QString curNum = getValue(clientInfo, BankAccount::Number);
        if(curNum == accNum)
            return pos;
    }
    return -1;
}
void refreshDataAboutClient(const QString & newInfo, const QString &oldInfo, QTextStream &in)
{
    QString allInfo = in.readAll();
    allInfo.replace(oldInfo, newInfo);
    in.seek(0);
    in << allInfo;
}


int writeClientToData(const QString &name, const QString &pin, TypeAccount type)
{

    int result = 0;
    QString number;
    QFile data("data.txt");
    if(!data.open(QIODevice::ReadWrite | QIODevice::Text))
        return result;

    QTextStream out(&data);
    if(!getLastNum(number, out))
        return result;

    if(!std::next_permutation(number.begin(), number.end() ))
        return result;

    result = number.toInt();
    QString newClient = makeClient(result, pin.toInt(), type, name);
    out.seek(data.size());
    out << newClient;
    data.close();
    return result;
}

bool writeCurrent(const QString & info)
{
    QFile current("current.txt");
    if(!current.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&current);
    out << info;
    current.close();
    return true;
}
bool getLastNum(QString & last, QTextStream & in)
{
    in.seek(0);
    QString temp = in.readLine();
    while(!in.atEnd())
        temp = in.readLine();
    last = getValue(temp, BankAccount::Number);
    return !temp.isEmpty();
}

bool checkNum(const QString & num)
{
    if(num.isEmpty() || num.length() != NUMBER_LEN)
        return false;
    for(int i = 0; i < num.length(); ++i)
        if(!num.at(i).isNumber())
            return false;
    return true;
}

bool checkPin(const QString & pin)
{
    if(pin.isEmpty() || pin.length() != PIN_LEN)
        return false;
    for(int i = 0; i < pin.length(); ++i)
        if(!pin.at(i).isNumber())
            return false;
    return true;
}

QString getValue(const QString &info, BankAccount::Value val)
{
    return info.section(' ', val, val);
}

QString makeClient(int num, int pin, TypeAccount type, const QString &name,
                   double balance, double credit, double municipal)
{
    QString newClient = '\n' + QString::number(num) + ' ' + QString::number(pin)
            + ' ' + QString::number(type) + ' ' + name + ' ' +
            QString::number(balance) + ' ' + QString::number(credit) + ' '
            + QString::number(municipal);
    return newClient;
}
