#include "human.h"
#include <QDebug>

Human::Human(QObject *parent) : QObject(parent)
{

}
int Human::age()
{
    return m_age;
}
void Human::setAge(int val)
{
    m_age = val;
}

char Human::sexSymbol()
{
    return m_sexSymbol;
}
void Human::setSexSymbol(char val)
{
    m_sexSymbol = val;
}


