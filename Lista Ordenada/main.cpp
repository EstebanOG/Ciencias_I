#include <iostream>
#include "lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct persona{string nombre;
				int codigo;
};

int main(int argc, char** argv) {
	int pos=1;
	persona per;
	per.codigo=9999;
	per.nombre="final";
	lista<persona> d = lista<persona>(per);
	
	//Método lista_vacia antes de llenar lista
	
	if(d.lista_vacia()){
		cout<<"La lista esta vacia"<<endl;
	}else{
		cout<<"La lista no esta vacia"<<endl;
	}
	
	//Método insertar
	per.codigo=1000;
	per.nombre="Juan";
	d.insertar(per,per.codigo);
	per.codigo=1100;
	per.nombre="Maria";
	d.insertar(per,per.codigo);
	per.codigo=1400;
	per.nombre="Ana";
	d.insertar(per,per.codigo);
	per.codigo=900;
	per.nombre="Karen";
	d.insertar(per,per.codigo);
	per.codigo=1300;
	per.nombre="Christian";
	d.insertar(per,per.codigo);
	
	//Muestra la lista
	while(pos<=d.get_tam()){
		d.recorrer(pos,&per);
		cout<< per.codigo<<" "<<per.nombre<<endl;
		pos++;
	}
	
	//Método lista_vacia después de llenar lista
	if(d.lista_vacia()){
		cout<<"La lista esta vacia"<<endl;
	}else{
		cout<<"La lista no esta vacia"<<endl;
	}
	
	//Borrar nodo
	if(d.borrar(1000)){
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
	if(d.pertenece(900)){
		cout<<"Si pertenece"<<endl;
	}else{
		cout<<"No pertenece"<<endl;
	}
	
	//Método cambiar
	per.codigo = 1800;
	per.nombre = "Esteban";
	d.cambiar(1400,per);
	
	pos = 1;
	//Muestra la lista
	while(pos<=d.get_tam()){
		d.recorrer(pos,&per);
		cout<< per.codigo<<" "<<per.nombre<<endl;
		pos++;
	}
	
	//Método buscar
	
	if(d.buscar(900,&per)){
		cout<<"encontrado : "<<per.codigo<<" "<<per.nombre<<endl;
	}else{
		cout<<"no encontrado"<<endl;
	}
	
	return 0;
}
