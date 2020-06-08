#include <iostream>
#include<Windows.h>
using namespace std;

//Prototipos
void llenarArray(int a[], int n);
void mostrarArray(int a[],int n);
void mergeLists(int *,int, int , int );


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

void merge_sort(int a[], int first, int last){
    int middle;
    if (first < last){
        middle=(first+last)/2;
        merge_sort(a,first,middle);
        merge_sort(a,middle+1,last);
        mergeLists(a,first,last,middle);
    }
}

void mergeLists(int a[], int first, int last, int middle)
{
    int i, j, k; 
    int n1 = middle - first + 1; 
    int n2 =  last - middle; 

    int L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = a[first + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[middle + 1+ j]; 
  

    i = 0;
    j = 0; 
    k = first;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
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
	merge_sort(a,0,n-1);
	cout<<GetCounter();
	cout<<" ms"<<endl;
	mostrarArray(a,n);
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

