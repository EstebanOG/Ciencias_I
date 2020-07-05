#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {
			int clave;
			T Dato;
             nodo<T> * sig;};


template <class T>
class lista{nodo <T> *cab, *z;
			int tam;
			
	public: lista(T Infomax){cab=new nodo<T>; z=new nodo <T>;
					cab->sig=z;
					z->clave=9999;
					z->Dato=Infomax;
					z->sig=z;
					tam=0;}
			bool lista_vacia();
			void insertar(T info, int clave);
			bool borrar(int clave);
			bool buscar (int clave, T *infoRet);
			bool cambiar(int clave, T infoNueva);	
			bool pertenece(int clave);
			void recorrer(int pos,T *infoRet);
			int get_tam(){
				return tam;
			}
			
			
			
};

template <class T>
bool lista<T>::lista_vacia()
{if(cab->sig==z)
    return true;
 else
	return false;
}

template <class T>
void lista <T>::insertar(T info, int clave){	
	nodo<T> *ant,*pos,*nuevo;
	nuevo=new nodo<T>;
	nuevo->clave=clave;
	nuevo->Dato=info;
	ant=cab;
	pos=cab->sig;
	while(nuevo->clave>pos->clave){
		ant=pos;
		pos=ant->sig;
	}
	ant->sig=nuevo;
	nuevo->sig=pos;
	tam++;
}

template <class T>
bool lista<T>::borrar(int clave){ 
	nodo<T> *ant,*pos;
	ant=cab;
	pos=cab->sig;
	while(clave>pos->clave){
		ant=pos;
		pos=ant->sig;
	}
	ant->sig=pos->sig;
	if(pos->clave==clave){
		delete pos;
		tam--;
		return true;
	}else{
		return false;
	}
}

template <class T>
bool lista<T>::buscar(int clave, T *infoRet)
{   
	nodo <T> *temp;
	temp=cab->sig;
	while(temp->clave<clave){
		temp=temp->sig;
	}
	if(temp->clave==clave){
		*infoRet = temp->Dato;
		return true;
	}else{
		return false;
	}
}

template <class T>
bool lista<T>::cambiar(int clave, T infoNueva){
 	nodo <T> *aux=cab->sig;
	while(aux->clave<clave){
		aux=aux->sig;
	}
	if(aux->clave==clave){
		aux->Dato= infoNueva;
		return true;
	}else{
		return false;
	}
}	

template <class T>
void lista<T>::recorrer(int pos,T *infoRet){
	nodo <T> *aux=cab;
	aux=aux->sig;
	int p=1;
	while(p<pos){
		aux=aux->sig;
		p++;
	}
	*infoRet = aux->Dato;
}

template <class T>
bool lista<T>::pertenece(int clave){
	nodo <T> *temp;
	temp=cab->sig;
	while(temp->clave<clave){
		temp=temp->sig;
	}
	if(temp->clave==clave){
		return true;
	}else{
		return false;
	}
}

#endif

