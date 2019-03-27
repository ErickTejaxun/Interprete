#include "NodoAST.h"
#include <qdebug.h> // Para imprimir en consola.
NodoAST::NodoAST()
{
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;
    hijos =  QList<NodoAST>();
}

NodoAST:: NodoAST(int l, int c, QString t, QString v)
{
    linea = l;
    columna = c;
    tipo = t;
    valor = v;
    tipo_ = getTipo();
    hijos = QList<NodoAST>();
}

void NodoAST::add(NodoAST nd)
{
    this->hijos.append(nd);
}

int NodoAST::getTipo()
{
    if(this->tipo=="int"){return 1;}
    if(this->tipo=="string"){return 2;}
    if(this->tipo=="bool"){return 3;}
    if(this->tipo=="char"){return 4;}
    if(this->tipo=="double"){return 5;}
    if(this->tipo=="suma"){return 6;}
    if(this->tipo=="resta"){return 7;}
    if(this->tipo=="multi"){return 8;}
    if(this->tipo=="div"){return 9;}
    if(this->tipo=="potencia"){return 10;}
    if(this->tipo=="operacion"){return 11;}
    if(this->tipo=="lexp"){return 12;}
    return 0;
}
