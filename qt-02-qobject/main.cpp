#include <QCoreApplication>
#include <QDebug>
#include "human.h"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    Human* prnt = qobject_cast<Human*>(parent);
    qDebug()<< prnt->objectName() <<", sex="<<prnt->sexSymbol()<<", age="<<prnt->age();

    const auto& children = parent->children();
    for(qsizetype i = 0; i < children.count();++ i)
    {
       Human* obj = qobject_cast<Human*>(children[i]);
       qDebug()<<"|-children:" << obj->objectName() <<", sex="<<obj->sexSymbol()<<", age="<<obj->age();
       if(children[i]->children().count() >0)
       {
           printTreeInfo(children[i]);
       }
    }
    qDebug()<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent;

    // TODO: create here required hierarchy
     parent = new Human;

     parent->setObjectName("Lucas Grey");
     parent->setAge(54);
     parent->setSexSymbol('M');

     Human *maryGrey = new Human(parent);
     maryGrey->setObjectName("Mary Grey");
     maryGrey->setAge(28);
     maryGrey->setSexSymbol('F');

     Human *freadSmyth = new Human(maryGrey);
     freadSmyth->setObjectName("Fread Smyth");
     freadSmyth->setAge(5);
     freadSmyth->setSexSymbol('M');

     Human *janeSmyth = new Human(maryGrey);
     janeSmyth->setObjectName("Jane Smyth");
     janeSmyth->setAge(4);
     janeSmyth->setSexSymbol('F');
     // //
     Human *jasonGrey = new Human(parent);
     jasonGrey->setObjectName("Jason Grey");
     jasonGrey->setAge(30);
     jasonGrey->setSexSymbol('M');

     Human *seanGrey = new Human(jasonGrey);
     seanGrey->setObjectName("Sean Grey");
     seanGrey->setAge(10);
     seanGrey->setSexSymbol('F');

     Human *jesicaGrey = new Human(jasonGrey);
     jesicaGrey->setObjectName("Jesica Grey");
     jesicaGrey->setAge(8);
     jesicaGrey->setSexSymbol('M');

     Human *hannahGrey = new Human(jasonGrey);
     hannahGrey->setObjectName("Hannah Grey");
     hannahGrey->setAge(7);
     hannahGrey->setSexSymbol('F');

	// TODO: dump tree info using standard Qt method
	
    printTreeInfo(parent);

    // TODO: delete here what need only

    delete parent;

    return a.exec();
}
