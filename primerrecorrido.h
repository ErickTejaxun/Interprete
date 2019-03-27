#ifndef PRIMERRECORRIDO_H
#define PRIMERRECORRIDO_H
#include <qstring.h>
#include <resultado.h>
#include <NodoAST.h>
class primerRecorrido
{
public:
    primerRecorrido();
    Resultado recorrer( NodoAST *raiz);
    QString resultado;
};

#endif // PRIMERRECORRIDO_H
