#include "Entorno.h"
#include <qdebug.h> // Para imprimir en consola.
Entorno::Entorno(Entorno *ant)
{
    anterior = ant;
}

Simbolo Entorno:: getSimbolo(QString id)
{
  tablaSimbolo.insert(1,"A");
  tablaSimbolo.insert(2,"B");
  tablaSimbolo[3] = "C";

  foreach(int i, tablaSimbolo.keys()) qDebug() << tablaSimbolo[i];

  QtablaSimboloIterator<int, QString> iter(tablaSimbolo);

  while(iter.hasNext())
  {
      iter.next();
      qDebug() << iter.key() << " : " << iter.value();
  }
}

int Entorno:: addSimbolo(Simbolo sim)
{
  //tablaSimbolo.insert(sim.id,sim);

  foreach(int i, tablaSimbolo.keys()) qDebug() << tablaSimbolo[i];
  QtablaSimboloIterator<int, QString> iter(tablaSimbolo);
  while(iter.hasNext())
  {
      iter.next();
      qDebug() << iter.key() << " : " << iter.value();
  }
}
