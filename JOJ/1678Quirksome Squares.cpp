#include <iostream>
#include <math.h>
using namespace std;
long arr[4][1000];
int main()
{
	long temp,dig,n,s1,s2,i,j,l,k;
	dig=2;
	while(dig<=8)
	{
		i=0;k=0;l=dig/2-1;
		j=pow(10,dig);
		temp=pow(10,dig/2);
		while(i<j)
		{
			s1=i%temp;
			s2=i/temp;
			if((s1+s2)*(s1+s2)==i)
				arr[l][k++]=i;
			i++;
		}
		arr[l][k]=-1;
		dig+=2;
	}
	while(cin>>n)
	{
		j=0;i=n/2-1;
		while(arr[i][j]!=-1)
		{
			cout.width(n);
			cout.fill('0');
			cout<<arr[i][j]<<endl;
			j++;
		}
	}
	
	return 0;
}




#include <iostream>
using namespace std;
long arr[4][50]={{0,1,81,-1},{0,1,2025,3025,9801,-1},{0,1,88209,494209,998001,-1},
{0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001,-1}};
int main()
{
	int i,n,dig;
	while(cin>>n)
	{
		i=0;dig=n/2-1;
		while(arr[dig][i]!=-1)
		{
			cout.width(n);
			cout.fill('0');
			cout<<arr[dig][i]<<endl;
			i++;
		}
	}
	return 0;
}

