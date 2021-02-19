#include "bankaccount.h"
#include <qdebug.h>

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals

    connect(this, SIGNAL(balanceChanged(long)),
     parentBank, SLOT(updateTotalBalance()));
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // TODO: add here signal emition
    emit  balanceChanged(m_balance);
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    long bal = balance();
    bal += amount;
    setBalance(bal);
}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    long bal = balance();
    bal -= amount;
    setBalance(bal);
}
