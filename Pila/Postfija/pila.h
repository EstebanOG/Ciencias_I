#ifndef PILA_H
#define PILA_H
#include <iostream>

using namespace std;

class Pila
{public:
    Pila (int max);
   	~Pila();
    void meter(int V);
    int sacar();
    int vacia();
 private:
    struct nodo
       {int clave; struct nodo *siguiente;};
   struct  nodo *cabeza, *z;
 };
 
Pila::Pila(int max)
{ cabeza = new nodo;  z=new nodo;
  cabeza->siguiente=z; z->siguiente =z;
}

Pila::~Pila()
{struct nodo *t=cabeza;
 while (t!=z)
       {cabeza=t;  t->siguiente;  delete cabeza;}
}

void Pila:: meter (int v)
{struct nodo *t=new nodo;
 t->clave = v;  t->siguiente=cabeza->siguiente;
cabeza->siguiente=t;
}

int Pila:: sacar()
{int x;
 struct nodo *t = cabeza->siguiente;
cabeza->siguiente = t->siguiente; x=t->clave;
delete t; return x;
}

int Pila::vacia()
{return cabeza->siguiente == z;}


#endif
