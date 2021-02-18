#include <QCoreApplication>
#include "bankaccount.h"
#include <QDebug>
//#include <qstring.h>
#include <qvariant.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // don't change type of account, use it as QObject*
    QObject *account = new BankAccount;

    // TODO: set holder name
    account->setProperty(
     "holderName", QString("John Doe")
    );
     // TODO: print it to qDebug()

    qDebug() <<
     account->property("holderName").toString();



    // TODO: get balance from property to qDebug()

    qDebug() << account->property("balance").toLongLong();

    account->setProperty(
     "balance", QVariant::fromValue(200L)
    );
    qDebug() << account->property("balance").toLongLong();

    return a.exec();
}
