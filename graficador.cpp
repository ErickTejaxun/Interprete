#include "graficador.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <QtWidgets>
#include <NodoAST.h>
graficador::graficador()
{
    this->contador = 0;
}

graficador::graficador(NodoAST *raiz)
{
    this->grafo = "";
    this->raiz = raiz;
    this->contador = 0;
}

QString graficador::graficar()
{
    grafo = "digraph G{";
    grafo += "node[shape=\"box\"];";
    grafo += "NodoAST0[label=\"" + escapar("[" +raiz->tipo +"," + QString::number(raiz->tipo_)+ "("+ QString::number(raiz->linea)+","+ QString::number(raiz->columna)+")"+"]"+raiz->valor)  + "\"];\n";
    this->contador = 1;
    recorrerAST("NodoAST0", raiz);
    grafo += "}";
    return grafo;
}

void graficador::recorrerAST(QString padre, NodoAST *hijo)
{
/*    for (NodoAST NodoAST: hijo->hijos )
    {
        QString nombreHijo = "NodoAST" +  QString::number(contador);//  this->contador;
        grafo += nombreHijo + "[label=\"" + escapar("[" +NodoAST.tipo +"]"+NodoAST.valor)  + "\"];\n";
        grafo += padre + "->" + nombreHijo + ";\n";
        contador++;
        recorrerAST(nombreHijo, &NodoAST);
    }
*/
    int x = 0;
    for (x = 0 ; x < hijo->hijos.count() ; x++)
    {
        NodoAST NodoAST = hijo->hijos[x];
        QString nombreHijo = "NodoAST" +  QString::number(contador);//  this->contador;
        grafo += nombreHijo + "[label=\"" + escapar("[" +NodoAST.tipo +"," + QString::number(NodoAST.tipo_)+ "("+ QString::number(NodoAST.linea)+","+ QString::number(NodoAST.columna)+")"+NodoAST.valor)  + "\"];\n";
        grafo += padre + "->" + nombreHijo + ";\n";
        contador++;
        recorrerAST(nombreHijo, &NodoAST);
    }
}

QString graficador::escapar(QString cadena)
{
    cadena = cadena.replace("\\", "\\\\");
    cadena = cadena.replace("\"", "\\\"");
    return cadena;
}

void graficador:: generarImagen()
{
    QFileInfo fi("temp");

    graficar();
    QString grafoDOT = this->grafo;
    //QString path = "C:\\Users\\erick\\Documents\\Graficas\\qt\\";
    QString path = fi.absolutePath() +"/";
    QFile qFile(path+"grafo.txt");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile); out << grafoDOT;
        qFile.close();
    }
    //"dot -Tjpg " + fileName + " -o " + fileName.Replace(".txt", ".jpg")
    QString cadenaComando = "dot -Tjpg " + path + "grafo.txt -o " + path+"grafo.jpg ";
    std::cout << cadenaComando.toStdString() << "\n" << endl;

    system(cadenaComando.toUtf8().constData());
/*    std::ofstream myfile;
    myfile.open ("grafo.txt",std::ios_base::app);
    myfile << grafoDOT.toStdString();
    myfile.close();
*/
}
