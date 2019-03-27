%option case-insensitive
%option yylineno
%{
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <NodoAST.h>
#include "qlist.h"

int yylex();
void yyerror(const char *s);
int linea=0; // Para contar lineas
int columna = 1; // para las columnas
int anterior = 0;
NodoAST *raiz;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

letra [a-zñA-ZÑ]+
numero [0-9]+
booleano ("verdadero"|"falso")
decimal [0-9]+"."[0-9]+
caracter "\'"("\\")?({letra}|{numero})"\'"
iden {letra}({letra}|{numero}|"_")*
cadena "\""[^"\""]*"\""
sinosi ("sino")[[:blank:]]("si")

%x COM COMM

%%
INITIAL
{
"//" {  BEGIN COM; }
"/*" {  BEGIN COMM; }
{numero}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return entero;}
{decimal}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return decimal;}
{caracter}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return caracter;}
{booleano}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return booleano;}
{cadena}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cadena;}
"("          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pari; }
")"          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pard; }
";"          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return puntocoma; }
"+"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return suma; }
"-"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menos; }
"*"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return multi; }
"/"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return division; }
"^"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return potencia; }
"\t"            {
                    strcpy(yylval.TEXT, yytext); columna=26;
                }
[[:blank:]]     { columna++; }
"\n"            {linea++; columna = 0; anterior = 0;}
.               {
                    columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);
/*                    errorT *nuevoE = new errorT("Lexico",yytext,linea, columna);
                    listaErrores->append(*nuevoE);
*/
                    std::cout <<yytext <<" Error Lexico en la linea "<< linea << " Columna:"<< columna<<  std::endl;
                }
}
<COMM>"*/" { BEGIN INITIAL; }
<COMM>"\n" {linea++;};
<COMM>.;
<COMM><<EOF>> { yyerror("unclosed comment"); }
<COM>"\n" { linea++; columna = 0; BEGIN INITIAL; };
<COM>.;
%%
