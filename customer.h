/*
 * Filename: customer.h
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
protected:
     QString name;
public:
    Customer();
    Customer(QString name);
    virtual QString getName() const;
    virtual void setName(QString name);
};

#endif // CUSTOMER_H
