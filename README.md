# Organización de lenguajes y compiladores 1

El siguiente ejemplo está dirigido a los estudiantes del curso o bien a personas que quieran aprender sobre copiladores. 

El siguiente programa es un ejemplo de interprete de un lenguaje que simplemente consta de expresiones aritmeticas separadas por punto y coma de la siguiente manera
```python
5+10+20.05;
"hola" + " mundo " + 10;
6.66+6*20;
```
Hasta la fecha de publicación de esta (26/03/2019) se ha implmentado lo siguiente:

Análisis léxico,

Análisis Semantico

Generación de AST

Graficación del AST

Recorrido del AST 

Operación Suma implementada completamente. Las demás operaciones queda como tarea, pero esta guía es una vista general de como utilizar las herramientas para el analisis y un ejemplo del recorrido para la ejecución de un AST.

Cabe resaltar que para la práctica y proyecto necesitarán realizar dos recorridos, uno para guardar las variables globales y metodos y funciones y en la segunda pasada ya se ejecutan las instrucciones que indique el método principal.


## Instalación

El programa tiene todo lo necesario para funcionar. 

```bash
Instalar Bison
Instalar Jflex
Instalar QT
```

## Uso

```bash
Simplemente compilar y probar.

```

## Autor
Erick Roberto Tejaxún Xicón
erickteja@gmail.com
2019

## License
[MIT](https://choosealicense.com/licenses/mit/)
