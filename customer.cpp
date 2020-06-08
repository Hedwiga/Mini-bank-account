/*
 * Filename: customer.cpp
 */
#include "customer.h"

Customer::Customer()
{
    name = "No name";
}

Customer::Customer(QString newName)
{
    name = newName;
}
QString Customer::getName() const
{
    return name;
}

void Customer::setName(QString newName)
{
    name = newName;
}
