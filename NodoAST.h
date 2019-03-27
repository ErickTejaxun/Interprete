#ifndef NODOAST_H
#define NODOAST_H
#include "QString"
#include "qlist.h"

class NodoAST
{
public:
    NodoAST(); // Constructor
    NodoAST(int l, int c, QString t, QString v);    
    void add(NodoAST n);
    QString tipo;
    QString valor;
    int linea;
    int columna;
    int tipo_; // Este nos servirá para la ejecución, ya que aquí no hay swicht(QString); vamos a hacer un Swicht(int);
    QList<NodoAST> hijos;
    int getTipo();
};

#endif // NODOAST_H
