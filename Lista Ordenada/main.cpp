#include <iostream>
#include "lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct persona{string nombre;
				int codigo;
};

int main(int argc, char** argv) {
	int pos=1;
	lista<persona> d;
	
	//Metodo lista_vacia antes de llenar lista
	if(d.lista_vacia()){
		cout<<"La lista esta vacia"<<endl;
	}else{
		cout<<"La lista no esta vacia"<<endl;
	}
	
	persona per;
	per.codigo=1000;
	per.nombre="Juan";
	d.insertar(per,1);
	per.codigo=1100;
	per.nombre="Maria";
	d.insertar(per,3);
	per.codigo=1200;
	per.nombre="Ana";
	d.insertar(per,2);
	per.codigo=900;
	per.nombre="Karen";
	d.insertar(per,8);
	per.codigo=1300;
	per.nombre="Christian";
	d.insertar(per,4);
	
	//Muestra la lista
	while(pos<=d.get_tam()){
		d.recorrer(pos,&per);
		cout<< per.codigo<<" "<<per.nombre<<endl;
		pos++;
	}
	
	//Metodo lista_vacia después de llenar lista
	if(d.lista_vacia()){
		cout<<"La lista esta vacia"<<endl;
	}else{
		cout<<"La lista no esta vacia"<<endl;
	}
	
	//Borrar nodo
	if(d.borrar(2)){
		cout<<"borrado"<<endl;
	}else{
		cout<<"No encontrado"<<endl;
	}
	
	//Se reinicia pos
	pos = 1;
	
	//Muestra la lista
	while(pos<=d.get_tam()){
		d.recorrer(pos,&per);
		cout<< per.codigo<<" "<<per.nombre<<endl;
		pos++;
	}
	
	//Método pertenece
	if(d.pertenece(8)){
		cout<<"Si pertenece"<<endl;
	}else{
		cout<<"No pertenece"<<endl;
	}
	
	//Método cambiar
	per.codigo = 1800;
	per.nombre = "Esteban";
	d.cambiar(3,per);
	
	pos = 1;
	//Muestra la lista
	while(pos<=d.get_tam()){
		d.recorrer(pos,&per);
		cout<< per.codigo<<" "<<per.nombre<<endl;
		pos++;
	}
	
	//Método buscar
	d.buscar(2,&per);
	cout<<per.codigo<<" "<<per.nombre<<endl;
	
	return 0;
}
