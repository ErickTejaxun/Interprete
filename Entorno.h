#ifndef NODOAST_H
#define NODOAST_H
#include "QString"
#include "qlist.h"
#include <QHash>

class Entorno
{
public:
    QHash<int, QString> tablaSimbolo;
    Entorno * anterior;
    Entorno( Entorno * anterior); // Constructor
    Simbolo getSimbolo(QString id);
    int addSimbolo(Simbolo sim);
};

#endif // NODOAST_H
