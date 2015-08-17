
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int
cmp(const void *p,const void *q)
{
        return *(int *)p - *(int *)q;
}

int main()
{
	
	int arr[6000];
	int i,j,k,n=0;
	for(i=0;i<32;i++)
		for(j=0;j<21;j++)
			for(k=0;k<15;k++)
				if(pow(2,i)*pow(3,j)*pow(5,k)<2100000000.0)
					arr[n++]=pow(2,i)*pow(3,j)*pow(5,k);
	qsort(arr,n,sizeof(arr[0]),cmp);
	cout<<"The 1500'th ugly number is "<<arr[1499]<<"."<<endl;
	return 0;
}


