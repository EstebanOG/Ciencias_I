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
class lista{nodo <T> *cab;
			int tam;
			
	public: lista(){cab=NULL; tam=0;}
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
{if(cab==NULL)
    return true;
 else
	return false;
}

template <class T>
void lista <T>::insertar(T info, int clave){	
	int p;
	if(lista_vacia()){
		nodo<T> *nuevo;
		nuevo = new nodo <T>;
		nuevo->clave=clave;
		nuevo->Dato=info;
		nuevo->sig=NULL;
		cab = nuevo;
		tam++;
	}else{
		nodo <T> *nuevo, *Aux,*temp;
 		nuevo = new nodo <T>;
		nuevo->clave=clave;
		nuevo->Dato=info;
		Aux=cab;
		temp=cab;
		p=1;
		while((clave>Aux->clave)&&(p<tam)){
			Aux=Aux->sig;
			p++;
		}
		if((clave>Aux->clave)&&(Aux->sig==NULL)){
			Aux->sig = nuevo;
			nuevo->sig=NULL;
		}else{
			if((clave<Aux->clave)&&(p==1)){
				cab=nuevo;
				nuevo->sig=Aux;
			}else{
				for(int i=1;i<p-1;i++){
					temp=temp->sig;
				}
				temp->sig=nuevo;
				nuevo->sig=Aux;	
			}
		}
		tam++;
	}
}

template <class T>
bool lista<T>::borrar(int clave){ 
	
	int p2=1;
	nodo <T> *temp,*Aux=NULL;
	temp=cab;
	Aux=cab;
	while((temp->clave!=clave)&&(p2<tam)){
		temp=temp->sig;
		p2++;
	}
	
	if(temp->clave==clave){
		if(p2==1){
			cab=temp->sig;
			delete temp;
		}else{
			for(int i=1;i<p2-1;i++){
				Aux=Aux->sig;
			}
			Aux->sig=temp->sig;
			delete temp;
		}
		tam--;
		return true;
	}else{
		return false;
	}
}

template <class T>
bool lista<T>::buscar(int clave, T *infoRet)
{   
	int p2=1;
	nodo <T> *temp;
	temp=cab;
	while((temp->clave!=clave)&&(p2<tam)){
		temp=temp->sig;
		p2++;
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
 	nodo <T> *aux=cab;
  	int p = 1;
	while((aux->clave!=clave)&&(p<tam)){
		aux=aux->sig;
		p++;
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
	int p=1;
	while(p<pos){
		aux=aux->sig;
		p++;
	}
	*infoRet = aux->Dato;
}

template <class T>
bool lista<T>::pertenece(int clave){
	int p2=1;
	nodo <T> *temp;
	temp=cab;
	while((temp->clave!=clave)&&(p2<tam)){
		temp=temp->sig;
		p2++;
	}
	if(temp->clave==clave){
		return true;
	}else{
		return false;
	}
}

#endif

