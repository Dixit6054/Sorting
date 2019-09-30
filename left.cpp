//finding the left most occurance
#include<iostream>
using namespace std;
int binary_search(int*,int,int,int,int*);
int search_right(int*,int);
int search_left(int*,int);
bool flag = 0;
main()
{
	int n,left;
	int* pleft = &left;
	cout<< "Enter the size of array: ";
	cin>>n;
	int* arr = new int[n];
	cout << "Please give me sorted array(accending): ";
	for(int i=0 ; i<n ; i++)
	cin>>arr[i];
	
	int key;
	cout << "Enter the element which you want to find: ";
	cin>>key;
	int r = binary_search(arr,key,0,n-1,pleft);
	if(left!=0)
	cout << left;
	else 
	cout << "Your element is not here";
	
}

int binary_search(int* arr, int key ,int nl , int nr , int* pleft)
{
	int mid = (nr+nl)/2;
	if(arr[mid] == key)
	{
		*pleft = mid+1;
		nr = mid-1;
	}
	else if (arr[mid] > key)
	nr = mid-1;
	else 							// if (arr[mid] < key) gets the default condition
	nl = mid +1;
	if(nl > nr)
	return -1 ;
	return binary_search(arr,key,nl,nr,pleft);
}

//these are some functions used if there is repition. they are linear
int search_right(int* arr,int key)
{	
int count=0;
	while(arr[key]==arr[key+1] )
	{
		count++;
		key++;
	}
	return count;
}


int search_left(int* arr,int key)
{	
int count=0;
	while(arr[key]==arr[key-1] )
	{
		count++;
		key--;
	}
	return count;
}



