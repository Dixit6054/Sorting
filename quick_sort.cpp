#include<iostream>
#include <stdlib.h> 
using namespace std;

void swap(int*,int*);
void quick_sort(int*,int,int);
int piv(int*,int,int);

int main()
{
	int arr[] = {78,4,23,12,33,67,0,1,1,10};
	quick_sort(arr,0,9);
	for (int i=0 ; i<10;i++)
	cout << arr[i] << " ";
	return 0;
}
void quick_sort(int*arr,int start ,int end)
{
	if (start > end )return ;			//base condition
	int p = piv(arr,start,end);			//divide
	quick_sort(arr,start,p-1);			// conquer
	quick_sort(arr,p+1,end);
										//no combining step required
	
}

int piv(int* arr, int start, int end)		//i am taking the last element as the pivot
{
	int i,v,j = start;
	int pivot = arr[ start + rand() %(start-end+1) ];				//you want to put all stuff less than the pivot to one side
	for(i=start;i<=end;i++)		//start and end is the area in which you can work
	{
		if ( arr[i] < pivot )				//Now let me explain you. mycodeschool video makes a program for a caase when pivot is in last
		{									//this is for random pivot chocie
			swap(&arr[i],&arr[j]);
			j++; 
		}
		else if(arr[i] == pivot)
		{	
			swap(&arr[i],&arr[j]);
			v = j;
			j++;
		}
	
	}
	j--;
	swap(&arr[v],&arr[j]);
									//to get the pivot at the right place
	return j;
}

void swap(int* a ,int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
