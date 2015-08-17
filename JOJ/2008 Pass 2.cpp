#include <iostream>
#include <math.h>
using namespace std;
long arr[20];
int main()
{
	long i,j,k,n,temp,rel;
	bool flag;
	arr[1]=5;
	for(i=2;i<=11;i++)
		arr[i]=arr[i-1]*9+pow(10,i-1);

	while(scanf("%d",&n)!=EOF)
	{
		i=1;
		while(n>arr[i])
			i++;
		temp=0;rel=0;j=i-1;flag=0;
		while((n-temp)>10)
		{
			i=0;
			while(temp<n)
			{
				i++;
				if(i==3)
					k=pow(10,j);
				else
					k=arr[j];
				if((temp+k)<=n)
				{
					temp+=k;
					rel+=pow(10,j);
					if(i==2)
						flag=1;
				}
				else
					break;
			}
			if(i>3)
				flag=0;
			j--;
		}
		if(flag)
			k=1;
		else
			k=2;
		while(temp!=n)
		{
			temp++;
			rel+=k;
		}
		cout<<rel<<endl;
	}
	return 0;
}

		
