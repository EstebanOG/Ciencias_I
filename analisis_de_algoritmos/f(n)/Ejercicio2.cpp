#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int N, i, j, **a;
	cin>>N;
	a = new int *[N];
	for(i=0;i<N;i++)
	{
		a[i]= new int[N];
		for(j=0;j<N;j++)
			a[i][j] = j*i;
	}
	cout<<"N: "<<sizeof(N)<<endl;
	cout<<"i: "<<sizeof(i)<<endl;
	cout<<"j: "<<sizeof(j)<<endl;
	cout<<"**a: "<<sizeof(**a)<<endl;
	cout<<"a: "<<sizeof(a)<<endl;
	cout<<"a[i]: "<<sizeof(a[0])<<endl;
	cout<<"a[i][j]: "<<sizeof(a[0][0])<<endl;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cout<<a[i][j];
			delete a[i];
	}
	delete []a;
	return 0;
}
