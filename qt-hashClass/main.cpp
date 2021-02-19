#include <QCoreApplication>
#include <qhash.h>
#include <qdebug.h>
#include "HashKey.h"

QString getHostNameByIp(QHash<HashKey, QString>  reverseDNS, QString Ip);


int main()
{
    QString Ip1("192.168.0.1");
    QString Ip2("192.168.0.2");
    QString Ip3("192.168.0.3");
    QString Ip4("192.168.0.4");
    QHash<HashKey, QString>  reverseDNS;
    reverseDNS.emplace(HashKey(Ip1),"Host1");
    reverseDNS.emplace(HashKey(Ip2),"Host2");
    reverseDNS.emplace(HashKey(Ip3),"Host3");
    reverseDNS.emplace(HashKey(Ip4),"Host4");

    qDebug() << getHostNameByIp(reverseDNS, "192.168.0.1");
    qDebug() << getHostNameByIp(reverseDNS, "192.168.0.10");
    qDebug() << getHostNameByIp(reverseDNS, "192.168.0.3");

return 0;
}

QString getHostNameByIp(QHash<HashKey, QString>  reverseDNS, QString Ip)
{
    QString val;
    HashKey key (Ip);

    if(reverseDNS.contains(key))
        val = reverseDNS.value(key);
    else
        val = "not found";

    return val;
}
