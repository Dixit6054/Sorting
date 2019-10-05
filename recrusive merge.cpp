#include<iostream>
using namespace std;
void mainmerge(int*,int);
void innermerge(int* A, int* L, int*R, int nl, int nr, int i, int j, int k);
void merge(int* A, int* L, int*R, int nl, int nr);
main()
{
	int n=10;
	int arr[10]={4,5,7,4,1,4,9,67,55,10};
	mainmerge(arr,n);

	for(int i=0 ; i<n ; i++)
	cout << arr[i]<< " ";
	
}
/*a wrap around innermerge*/
void merge(int* A, int* L, int*R, int nl, int nr)
{
	int i=0, j=0, k=0;
	innermerge(A, L, R, nl, nr, i, j,k);
	
}
void innermerge(int* A, int* L, int*R, int nl, int nr, int i, int j, int k)
{
	if(i<nl && j<nr)
	{
		if(L[i] <= R[j])
		{
		A[k] = L[i];
		i++;
		k++;
		}
		else
		{
		A[k] = R[j];
		j++;
		k++;
		}	
	}
	else if(i<nl)
	{
		A[k] = L[i];i++;
		k++;
	}
	else if(j<nr)
	{
		A[k] = R[j];
		j++;
		k++;	
	}
	else//base condition
	return;
	innermerge( A,  L,R, nl, nr, i, j, k);	/*see here we are only using the upper part os recrusion ie. inreturn no operation performed*/
	//nothing here, which you will see in each case of linked list;
	/*what i could have done is used reference of i,j,k in function so as to avoid making new ints rather make new int*s and deference it;
	
	the point i am explaining is pointers wont let you do work in back trace of recrusion; as it'll  have the lastest value only;
	
		*/
}
void mainmerge(int* A, int n )
{
	if(n<2) return;					//base condition 
	int nl = n/2;
	int nr = n - nl;
	int* L = new int[nl]; 
	int* R = new int[nr]; 
	
	for(int i=0;i<nl;i++)			
	L[i] = A[i];
	
	for(int i=nl;i<n;i++)
	R[i-nl] = A[i];
	
	mainmerge(L,nl); 
	mainmerge(R,nr);
	
	merge(A,L,R,nl,nr);
}
