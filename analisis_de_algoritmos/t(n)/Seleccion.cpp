#include<iostream>
#include<Windows.h>
using namespace std;

//Prototipos
void llenarArray(int a[], int n);
void mostrarArray(int a[],int n);
void ordenarArray(int a[], int n);
void intercambiar(int a[], int min, int i);


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

int main(int argc, char** argv) {
	int n;
	cout<<"Digite N: ";
	cin>>n;
	int a[n];
	llenarArray(a,n);
	mostrarArray(a,n);
	
	StartCounter();
	ordenarArray(a,n);
	cout<<GetCounter();
	cout<<" ms"<<endl;
	
	mostrarArray(a,n);
	delete []a;
	return 0;	
}


void llenarArray(int a[],int n){
	int i;
	for(i=n-1;i>=0;i--){
		a[i]=n-i;
	}
}

void mostrarArray(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void ordenarArray(int a[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		intercambiar(a,min,i);
	}
}

void intercambiar(int a[],int min,int i){
	int aux;
	aux=a[min];
	a[min]=a[i];
    a[i]=aux ;
}
