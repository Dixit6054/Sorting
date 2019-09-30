#include<iostream>
using namespace std;

struct pair
{
	int max;
	int min;
};

main()
{
	int a[10] = {12,13,14,1,11,16,61,41,31,0};
	int start=0,end=9;
	pair m;
	cout << maxmin(start,end,a);
}


struct pair maxmin ( int start, int end, int*a )
{
	if(start==end)
	{
		m.max=m.min=a[start];
		return m;
	}
	
	if ( start == end-1 )
	{
		if(a[start] > a[end])
		{
			m.max = a[start];
			m.min = a[end];
		}
		else
		{
			m.max = a[end];
			m.min = a[start];
		}
	}
	
	int mid=(start+end)/2;
	
	struct pair r = maxmin( mid+1, end, a);		
	struct pair l = maxmin( start, mid, a);
	 
	if(r.max > l.max)
	return m.max = r.max;
	else
	return m.max = l.max;
	
	if(r.min > l.min)
	return m.min = l.min;
	else
	return m.min = r.min; 
	 
}

