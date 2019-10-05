#include<stdio.h>
using namespace std;
#include<iostream>

void selection(int* a,int n)
{	int i,j,z;

	int min;
	for(i=0; i < n-1 ; i++)			//last element will be sorted; n-1
	{
		min = 9999999;
		for(j=i; j < n ; j++)
		{
			if(min>a[j])
			{
				min = a[j];
				z=j;
			}
		}
				int q = min;
				min = a[i];
				a[i] = q;
				a[z] =  min;
	}
	
}




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
	selection(q,n);
	for(int w=0; w<n ; w++)
	cout << q[w] << " ";
}









