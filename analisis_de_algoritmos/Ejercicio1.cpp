#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int N,i,j, *a;
	cin>>N;
	for(i=0;i<N;i++)
	{
		a = new int [N];
		for(j=0;j<N;j++)
		{
			a[j]=j*i;
			cout<<a[j];
		}
		delete []a;
	}
	return 0;
}
