#include "primerrecorrido.h"

enum Choice
{
    INT =1 ,
    STRING = 2,
    BOOL = 3,
    CHAR = 4,
    DOUBLE = 5,
    SUMA = 6,
    RESTA = 7,
    MULTI = 8,
    DIV = 9,
    POTENCIA = 10,
    OPERACION = 11,
    LOPERACION = 12,
};

/*

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
*/

primerRecorrido::primerRecorrido()
{
    resultado = "";
}

Resultado primerRecorrido:: recorrer( NodoAST *raiz)
{
    Resultado r = Resultado();
    r.linea = raiz->linea;          // Nos servirán para una posible reporte de error de tipos.
    r.columna = raiz->columna;
    switch(raiz->tipo_)
    {
        case INT:
            {
                r.tipo = INT;
                r.valor = raiz->valor;
            }
            break;
        case DOUBLE:
            {
                r.tipo = DOUBLE;
                r.valor = raiz->valor;
            }
            break;
        case STRING:
            {
                r.tipo = STRING;
                r.valor = raiz->valor;
            }
            break;
        case CHAR:
            {
                r.tipo = CHAR;
                r.valor = raiz->valor;
            }
            break;
        case LOPERACION:
            {
                /*Como aquí hay una lista de operaciones, hacemos un for*/
                r.tipo = LOPERACION;
                for (int x= 0; x< raiz->hijos.size(); x++)
                {
                    NodoAST nodo = raiz->hijos.at(x);
                    recorrer(&nodo);
                }
            }
            break;
        case OPERACION:
            {
                NodoAST op = raiz->hijos.at(0);
                r.valor = STRING;
                r.valor = recorrer(&op).valor;
                resultado+= r.valor +"\n";
            }
            break;
        case SUMA:
            {
                NodoAST iz = raiz->hijos.at(0);
                Resultado op1 = recorrer(&iz);
                NodoAST der = raiz->hijos.at(1);
                Resultado op2 = recorrer(&der);
                switch (op1.tipo)
                {
                    case INT:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = INT;
                                        int result = op1.valor.toInt() +op2.valor.toInt();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case CHAR:
                                    {
                                        r.tipo = CHAR;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                            }
                        }
                        break;
                        case DOUBLE:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                    {
                                        r.tipo = INT;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case DOUBLE:
                                    {
                                        r.tipo = DOUBLE;
                                        double result = op1.valor.toDouble() + op2.valor.toDouble();
                                        r.valor = QString::number(result);
                                    }
                                    break;
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                case CHAR:
                                    {
                                        r.tipo = CHAR;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                break;
                            }
                        }
                        break;
                    case STRING:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                case DOUBLE:
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                break;
                            }
                        }
                        break;
                    case CHAR:
                        {
                            switch (op2.tipo)
                            {
                                case INT:
                                case DOUBLE:
                                case STRING:
                                    {
                                        r.tipo = STRING;
                                        r.valor = op1.valor + op2.valor;
                                    }
                                    break;
                                default:
                                    {
                                        /*Aqui debe ir el código para reportar el error de tipos*/
                                    }
                                break;
                            }
                        }
                        break;
                }
            }
            break;
    }
    return r;
}


