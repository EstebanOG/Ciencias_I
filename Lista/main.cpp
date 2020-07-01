#include <iostream>
#include "lista.h"
using namespace std;

struct persona{string nombre;
				int codigo;
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int pos = 1, info;
	char letra;
	
	lista<int> a;
	
	lista<float> b;
	lista<char> c;
	lista<persona> d;
	persona per;
	
	a.insertar_inicio(8);
	a.insertar_final(18);
	a.insertar(10,2);
	a.insertar(12,3);
	
	b.insertar_inicio(5.5);
	b.insertar_final(6.3);
	b.insertar(5.8,2);
	b.insertar(6.1,3);
	
	c.insertar_inicio('a');
	c.insertar_final('z');
	c.insertar('c',2);
	c.insertar('f',3);
	
	per.codigo = 1000;
	per.nombre = "Juan";
	d.insertar_inicio(per);
	per.codigo = 1500;
	per.nombre = "Pedro";
	d.insertar_final(per);
	per.codigo = 1100;
	per.nombre = "Maria";
	d.insertar(per,2);
	per.codigo = 1200;
	per.nombre = "Ana";
	d.insertar(per,3);
	
	a.cambiar(2,15);
	a.borrar(3);
	
	/*while(pos<=a.get_tam())
	{
		a.buscar(pos, &info);
		cout<< info<< " ";
		pos++;
	}
	
	while(pos<=c.get_tam())
	{
		c.buscar(pos, &letra);
		cout<< letra<< " ";
		pos++;
	}*/
	
	while(pos<=d.get_tam())
	{
		d.buscar(pos, &per);
		cout<< per.codigo<< " "<<per.nombre<<endl;
		pos++;
	}
	return 0;
}
