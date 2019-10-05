#include<iostream>
using namespace std;

int binary_search(int* A, int start, int end, int key)
{
	
	if( A[start] >= key)
	{
	//	cout <<"q"<<A[start] <<" i"<< key<<"l";
		return start;
	}
	
	if(A[end] <= key)
	return end+1;
	
	int mid = (start+end)/2;
	if(mid==start)
	return end;
	
	if(A[mid] == key)
	return mid;
	else if(A[mid] > key)
	return	binary_search(A,start,mid,key);
	else
	return	binary_search(A,mid,end,key);
	
}

void insertion_sort(int* A, int n)
{
	int end = n-1;
	if(n==2)
	{
		if(A[0] > A[1])
		{
			int q = A[0];
			A[0] = A[1];
			A[1] = q;
		}
		return;
	}
	
	insertion_sort(A,n-1);
	
/*	for(int i=0; i<10; i++)
	{
		cout << A[i] <<" ";
	}cout <<endl;
	cout <<"end: "<<end<<" key: "<<A[end] <<" ";
*/	
	int shift = binary_search(A,0,end-1,A[end]);
	
	int t = A[end];
	
	for(int i=end-1; i >= shift ;i--)
	{
		A[i+1] = A[i];
	}
	A[shift] = t;
/*
	cout << "shift "<<shift << "\t\t";
	for(int i=0; i<10; i++)
	{
		cout << A[i] <<" ";
	}cout <<endl;
*/	
}
main()
{
	int A[10] = {1,2,3,4,5,6,2,8,9,0};
	insertion_sort(A,10);
	
	for(int i=0; i<10; i++)
	{
		cout << A[i] <<" ";
	}
}
