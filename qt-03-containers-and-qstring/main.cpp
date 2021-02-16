#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name

    QListIterator<QString> it(names), itRes(names);
    QString res = "longest: %1";
    if(it.hasNext())
    {
        while(it.hasNext())
        {
            if(it.peekNext().size()> itRes.peekNext().size())
            {
                itRes = it;
            }
            it.next();
        }
        qDebug() << res.arg(itRes.peekNext());
    }

    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name
    QList<QString> ::const_iterator i = names.cbegin();
    QList<QString> ::const_iterator resIt = i;
    QString shortest = "shortest: ";
    for(; i != names.cend(); ++i)
    {
        if(i->length() < resIt->length())
        {
            resIt = i;
        }
    }
    shortest.prepend("The ");
    shortest.append(*resIt);
    qDebug() << shortest;

    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string
    QStringList strList;
    QStringList strRes;
    QString filtered;
    foreach(QString name, names)
    {
       strList.append(name);
    }
    strRes = strList.filter("lynn");
    filtered = strRes.join(", ");
    qDebug() << filtered;

    // print all names in reverse order
    // TODO: 1. Using QStack
    QStack<QString> stack;
    foreach(QString name, names)
    {
        stack.push(name);
    }
    strRes.clear();
    while(!stack.isEmpty())
    {
        strRes.append(stack.pop());
    }
    qDebug() << strRes;
    // TODO: 2. Using other QList
    qDebug() <<" Using other QList:";
    strRes.clear();
    QList<QString> other;
    QList<QString>::const_reverse_iterator rIt = names.crbegin();
    while(rIt != names.crend())
    {
        other.append(*rIt++);
    }
    foreach(QString name, other)
    {
        strRes.append(name);
    }
    qDebug() << strRes;
    // TODO: 3. Without other containers
    rIt = names.crbegin();
    while(rIt != names.crend())
    {
        qDebug() <<*rIt++;
    }

    return a.exec();
}
