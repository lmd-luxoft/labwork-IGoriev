#ifndef HASHKEY_H
#define HASHKEY_H
#include <qstring.h>

class HashKey
{
public:
    explicit HashKey(QString clientIp = "")
    {
        ip = clientIp;
    }
    QString getIp()const
    {
        return ip;
    }

private:
   QString ip;
};

inline bool operator ==(const HashKey &op1, const HashKey &op2)
{
return op1.getIp() == op2.getIp();
}

inline int qHash(const HashKey &obj)
{
    if(obj.getIp().isEmpty())
        return 0;

    return obj.getIp().toInt()%10;
}

#endif // HASHKEY_H
