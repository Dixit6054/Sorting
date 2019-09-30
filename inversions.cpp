#include<iostream>
using namespace std;
void inversions(int*,int);
void merge(int*,int*,int*,int,int,int);
int sum =0;
main()
{
	int arr[10] = {2,4,6,9,1,2,12,56,76,98};
	inversions(arr,10);
	cout << sum ;
}

void inversions(int*arr,int n)
{
	if(n<2) return;			//base condition
	int nl = n/2;
	int nr = n-nl;
	
	int* al = new int[nl];		//nl elements ie. from 0 to nl-1
	int* ar = new int[nr];		// from nl to n-1
	
	for(int i=0; i<nl;i++)
	al[i] = arr[i];
	
	for(int i=nl; i<n;i++)
	ar[i-nl] = arr[i];
	
	inversions(al,nl);
	inversions(ar,nr);
	merge(al,ar,arr,nl,nr,n);
	
}
void merge(int* al,int* ar,int* arr,int nl,int nr,int n)
{
	int i=0,j=0,k=0; 
	while(i<nl && j<nr)
	{
		if(al[i] < ar[j] )
		{
			arr[k] = al[i];
		
			i++;
		}
		else 
		{ cout << "al[i]: " << al[i] << "   " << "ar[j]: " << ar[j] << endl;
		cout << "nl: " << nl << "   " << "i: " << i << endl;
			if(al[i] == ar[j])
			sum = sum + nl -1 -i ;
			else
			sum= sum + nl - i ;
			
			arr[k] = ar[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		arr[k] = al[i];
		i++;k++;
	}
	while(j<nr)
	{
		arr[k] = ar[j];
		j++;k++;
	}
	delete ar;
	delete al;
}

