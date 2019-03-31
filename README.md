# Organizaci�n de lenguajes y compiladores 1

## versión qt
![Alt text](version.PNG?raw=true "version QT")

El siguiente ejemplo est� dirigido a los estudiantes del curso o bien a personas que quieran aprender sobre copiladores. 

El siguiente programa es un ejemplo de interprete de un lenguaje que simplemente consta de expresiones aritmeticas separadas por punto y coma de la siguiente manera
```python
5+10+20.05;
"hola" + " mundo " + 10;
6.66+6*20;
```
Hasta la fecha de publicaci�n de esta (26/03/2019) se ha implmentado lo siguiente:

An�lisis l�xico,

An�lisis Semantico

Generaci�n de AST

Graficaci�n del AST

Recorrido del AST 

Operaci�n Suma implementada completamente. Las dem�s operaciones queda como tarea, pero esta gu�a es una vista general de como utilizar las herramientas para el analisis y un ejemplo del recorrido para la ejecuci�n de un AST.

Cabe resaltar que para la pr�ctica y proyecto necesitar�n realizar dos recorridos, uno para guardar las variables globales y metodos y funciones y en la segunda pasada ya se ejecutan las instrucciones que indique el m�todo principal.


## Instalaci�n

El programa tiene todo lo necesario para funcionar. 

```bash
Instalar Bison 3.1 (agregarlo a variables de entorno en Windows)
Instalar flex 2.6.4 (agregarlo a variables de entorno en Windows)
Instalar QT
```

## Uso

```bash
Simplemente compilar y probar.

```

## Autor
Erick Roberto Tejax�n Xic�n
erickteja@gmail.com
2019

## License
[MIT](https://choosealicense.com/licenses/mit/)
