#include <iostream>
using namespace std;
template <class T, class S>
struct nodo {T clave;
             S descrip; 
             nodo<T,S> * sig;
};

int main(){
	nodo<int,char> *p = new nodo <int, char>, *q = new nodo <int, char>;
	p->clave = 2;
	p->descrip = 's';
	p->sig = q;
	q->clave = 3;
	q->descrip ='F';
	q->sig = NULL;
	
	return 0;
}
