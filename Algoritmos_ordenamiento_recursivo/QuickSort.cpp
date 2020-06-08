#include <iostream>
#include<Windows.h>
using namespace std;

//Prototipos
void ordenRapido(int a[], int izq,int der);
void llenarArray(int a[], int n);
void mostrarArray(int a[],int n);


double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/(PCFreq/1000);
}


int main(int argc, char *argv[]) {
	int n;
	cout<<"Digite N: ";
	cin>>n;
	int a[n];
	llenarArray(a,n);
	mostrarArray(a,n);
	StartCounter();
	ordenRapido(a,0,n-1);
	cout<<GetCounter();
	cout<<" ms"<<endl;
	mostrarArray(a,n);
}

void ordenRapido(int a[], int izq, int der){
	int i,j,v;
	int cont=1;
	int temp=0;
	if(der>izq){
		v=a[der];
		i=izq-1;
		j=der;
		while(cont){
			while(a[++i]<v);
			while(a[--j]>v);
			if(i>=j){
				cont=0;
			}else{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;	
			}	
		}
		temp=a[i];
		a[i]=a[der];
		a[der]=temp;
		
		ordenRapido(a,izq,i-1);
		ordenRapido(a,i+1,der);
	}
}

void llenarArray(int a[],int n){
	int i;
	for(i=n-1;i>=0;i--){
		
		if(i!=n/2){
			a[i]=n-i;
		}else{
			a[i]=1;
		}
	}
	a[n-1]=n/2;
}

void mostrarArray(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}


