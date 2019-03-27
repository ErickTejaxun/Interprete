#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <NodoAST.h>   //Nuestra clase nodo
#include <qdebug.h>
#include <parser.h>  // Nuestro parser
#include <scanner.h>  // Nuestro scanner
#include <graficador.h> // Graficador
#include <primerrecorrido.h>

extern int yyparse(); //
extern NodoAST * raiz;
extern NodoAST *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botonAnalizar_clicked()
{
    QString programa = ui->txtInput->toPlainText();
    YY_BUFFER_STATE buffer = yy_scan_string(programa.toUtf8().constData());
    /*Limpiamos los contadores
    ya que son variables globales*/
    linea = 0;
    columna = 0;
    yylineno = 0;

    if(yyparse()==0) // Si nos da un número negativo, signifca error.
    {
        /*Instanciamos un graficador y graficamos*/
        graficador *graf = new graficador(raiz);
        graf->generarImagen();
        /*Instanciamos nuestro interprete y le enviamos nuestro arbol para ejecutarse.*/
        primerRecorrido * interprete = new primerRecorrido();
        interprete->recorrer(raiz);
        ui->txtOutput->setText(interprete->resultado);
    }

}
