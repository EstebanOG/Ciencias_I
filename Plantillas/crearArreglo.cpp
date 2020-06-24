#include<iostream>
using namespace std;

int *CrearArregloEnteros(int tam=5)
{int *ar;
  ar = new int[tam];
  return ar;}


int main(){
	int *p,*q,i;
	p = CrearArregloEnteros();
	q = CrearArregloEnteros(3);
	for (i = 0; i < 5; i++)
		p[i] = i;
	for (i = 0; i < 3; i++)
		q[i] = i;
	for (i = 0; i < 5; i++)
		cout<<p[i];
	cout<<endl;
	for (i = 0; i < 3; i++)
		cout<<q[i];
	
	return 0;
}
