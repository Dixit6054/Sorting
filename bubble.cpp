#include<iostream>
using namespace std;
void bubble(int*,int);
void swap(int*,int*);
main()
{	
	int n;
	cout << "enter the size of arrray" << endl;
	cin>>n;
	
	int *q = new int[n];
	
	cout << "Enter a arrary :";
	for(int w=0; w<n ; w++)
	cin>>q[w];
	
	
	cout << "Here is the sorted one :";
	bubble(q,n);
	for(int w=0; w<n ; w++)
	cout << q[w] << " ";
}

void bubble(int *a,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for (j=0; j < n-i-1 ; j++)
		{
			if( a[j] > a[j+1] )	
			swap(&a[j],&a[j+1]);
		}
	}
}

void swap(int*q, int* w)
{
	int t;
	t=*q;
	*q=*w;
	*w=t;
}
