#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "NodoAST.h"
#include <fstream>
#include <iostream>
class graficador
{
public:
    graficador();
    graficador(NodoAST *raiz);
    NodoAST *raiz;
    int contador;
    QString grafo;
    QString graficar();
    void recorrerAST(QString padre, NodoAST *hijo);
    QString escapar(QString cadena);
    void generarImagen();

};

#endif // GRAFICADOR_H
