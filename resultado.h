#ifndef RESULTADO_H
#define RESULTADO_H
#include <qstring.h>

class Resultado
{
public:
    Resultado();
    Resultado(int l, int c, int t, QString v);
    int tipo;
    QString valor;
    int linea;
    int columna;
};

#endif // RESULTADO_H
