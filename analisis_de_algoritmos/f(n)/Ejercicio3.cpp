#include <iostream>

using namespace std;
struct nodo{
	int x,y;
	nodo *sig;
};
int main(int argc, char** argv) {
	int N, i, j;
	nodo *cab = NULL, *Aux;
	cin>> N;
	for(i=0;i<N;i++)
	{
		Aux = new nodo;
		Aux ->x = i;
		Aux ->y = N-i;
		Aux->sig = cab;
		cab = Aux;
	}
	cout<<"N: "<<sizeof(N)<<endl;
	cout<<"i: "<<sizeof(i)<<endl;
	cout<<"j: "<<sizeof(j)<<endl;
	cout<<"cab: "<<sizeof(cab)<<endl;
	cout<<"Aux: "<<sizeof(Aux)<<endl;
	cout<<"Aux ->x: "<<sizeof(Aux ->x)<<endl;	
	cout<<"Aux ->y: "<<sizeof(Aux ->y)<<endl;
	cout<<"Aux ->sig: "<<sizeof(Aux ->sig)<<endl;		
	Aux = cab;
	while(Aux!=NULL)
	{
		cout<< Aux ->x << Aux->y<<endl;
		Aux=Aux -> sig;
	}
	for(Aux=cab ->sig;Aux!=NULL;Aux = Aux -> sig)
	{
		delete cab;
		cab = Aux;
	}
	return 0;
}
