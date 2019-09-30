#include<iostream>
using namespace std;
void insertion(int *, int);
int main()
{
	int i,n;
	cout << "Enter the size of array you want: ";
	cin>>n;
	int *arr= new int[n];
	cout << "Enter the values: " << endl;
	for(i=0;i<n;i++)
	cin>>arr[i];
	//till this i have got an array
	insertion(arr,n);
	cout << "Here is your array: ";
	for(i=0;i<n;i++)
	cout << arr[i] << " ";
	return 0;
}

void insertion(int *arr, int n)
{
	int i,j,value;
	for(i=1;i<n;i++)
	{
		value = arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(value<arr[j])
			{
				arr[j+1] = arr[j];
				arr[j] = value;
			}
		}
	}
	
}
