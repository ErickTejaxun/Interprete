%{
#include "scanner.h"//se importa el header del analisis sintactico
#include "NodoAST.h"
#include "qdebug.h"
#include <iostream>
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern NodoAST *raiz; // Raiz del arbol

int yyerror(const char* mens)
{

    std::cout << mens <<" "<<yytext<< std::endl;
    return 0;
}
%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;
}

//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT> entero;
%token<TEXT> decimal;
%token<TEXT> caracter;
%token<TEXT> booleano;
%token<TEXT> cadena;
%token<TEXT> id;
%token<TEXT> pari;
%token<TEXT> pard;
%token<TEXT> suma;
%token<TEXT> menos;
%token<TEXT> multi;
%token<TEXT> division;
%token<TEXT> potencia;
%token<TEXT> puntocoma;




/*No terimanesl*/
%type<nodito> INICIO;//
%type<nodito> EXPA; // Aritmetica
%type<nodito> LEXPA; // lista de instrucciones

%left suma menos
%left multi division
%left potencia

%start INICIO
%%

INICIO : LEXPA { raiz = $$; }
;

LEXPA: LEXPA  EXPA puntocoma
        {
            $$=$1;
            NodoAST *nodo = new NodoAST(@2.first_line, @2.first_column,"operacion","operacion");
            nodo->add(*$2);
            $$->add(*nodo);
        }
        | EXPA puntocoma
        {
            $$ = new NodoAST(@1.first_line, @1.first_column,"lexp","lexp");
            NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"operacion","operacion");
            nodo->add(*$1);
            $$->add(*nodo);
        }
;

EXPA:
         EXPA suma EXPA {NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"suma",$2);  nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA menos EXPA {NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"resta",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA multi EXPA {NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"multi",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA division EXPA{NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"div",$2); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA potencia EXPA{ NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"potencia",$2); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
        |menos EXPA { $$ = new NodoAST(@1.first_line, @1.first_column,$1,$1); $$->add(*$2);}
        |entero { $$ = new NodoAST(@1.first_line, @1.first_column,"int",$1);}
        |caracter { $$ = new NodoAST(@1.first_line, @1.first_column,"char",$1);}
        |decimal { $$ = new NodoAST(@1.first_line, @1.first_column,"double",$1);}
        |booleano { $$ = new NodoAST(@1.first_line, @1.first_column,"bool",$1);}
        |cadena { $$ = new NodoAST(@1.first_line, @1.first_column,"string",$1);}
        |pari EXPA pard{$$=$2;}
;

%%
