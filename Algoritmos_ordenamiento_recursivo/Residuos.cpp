#include <iostream>
#include<Windows.h>
using namespace std;

//Prototipos
void cambioresiduos(int a[], int izq,int der,int b);
unsigned bits (int a, int k, int j);
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

unsigned bits (int a,int k, int j){
	return (a>>k)&~(~0<<j);
}

void cambioresiduos(int a[], int izq, int der, int b){ 
	int i,j,temp=0;
	if (der>izq && b>0){
		i= izq; j=der;
 		while(j!=i){
			while(!bits(a[i],b,1) && i<j)i++;
 			while(bits(a[j],b,1) && j>i)j--;
 			temp = a[i];
			a[i] = a[j];
			a[j] = temp;	
 		}
 		if (!bits(a[i],b,1)) j++;
 		cambioresiduos(a, izq, j-1, b-1);
 		cambioresiduos(a, j, der, b-1);
 	}
}



int main(int argc, char *argv[]) {
	int n;
	cout<<"Digite N: ";
	cin>>n;
	int a[n];
	llenarArray(a,n);
	mostrarArray(a,n);
	StartCounter();
	cambioresiduos(a,0,n-1,5);
	cout<<GetCounter();
	cout<<" ms"<<endl;
	mostrarArray(a,n);
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
