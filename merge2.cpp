#include<iostream>
using namespace std;
void join(int*al,int*ar,int*arr,int nl,int nr, int n)
{
	int i=0,j=0,k=0;	
	while(i<nl && j<nr)
	{
		if(al[i] <= ar[j])
		{
			arr[k] = al[i];
			i++;
		}
		else
		{
			arr[k] = ar[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		arr[k] = al[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		arr[k] = ar[j];
		j++;
		k++;
	}
	delete ar;
	delete al;	
}
void merge(int arr[] , int n)
{
	if(n==1)		// base condition
	return;
	int nl = n/2;
	int nr = n - nl;
	int * al = new int[nl];
	int * ar = new int[nr];
	for(int i=0;i<nl;i++)						// there are gonna be nl elements filled
	al[i] = arr[i];
	for(int i=nl;i<n;i++)
	ar[i-nl] = arr[i];
	merge(al,nl);
	merge(ar,nr);
	join(al,ar,arr,nl,nr,n);
	
}


main()
{
	int n;
	cout << "Get me array size: ";
	cin>>n;
	int* arr = new int[n];
	cout << "Now the elements: ";
	for(int i=0 ; i<n ; i++)
	cin>>arr[i];
	merge(arr,n);
	for(int i=0 ; i<n ; i++)
	cout << arr[i] << " ";
}

