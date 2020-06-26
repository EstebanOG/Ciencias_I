#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {T dato; 
             nodo<T> * sig;};

template <class T>
class Lista{nodo<T> *cab;
			int tam;
	public: Lista(){cab=Null; tam=0;}
			bool lista_vacia();
			void insertar(T info,int pos);
			void insertar_final(T info);
			void insertar_inicio(T info);
			bool borrar(int pos);
			T buscar(int pos);
			bool cambiar(int pos, T infoNueva)	
};

template <class T>
bool Lista<T>::lista_vacia(){
	if(cab==NULL)
		return true;
	else
		return false;
}

template <class T>
void Lista<T>::insertar(T info, int pos){
	int p=1;
	if(pos>tam)
		insertar_final(info);
	else if (pos == 1)
		insertar_inicio(info);
	else{
		nodo<T> *nuevo, *Aux;
		nuevo = new nodo<T>;
		nuevo->dato = info;
		Aux = cab;
		p=1;
		while(p<pos-1 && Aux!=NULL){
			Aux = Aux->sig;
			p++;
		}
		nuevo->sig = Aux->sig;
		Aux->sig = nuevo;
		tam++;
	}
		
}
#endif
