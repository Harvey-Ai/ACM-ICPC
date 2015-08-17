#include <iostream>
using namespace std;
int main()
{
	int k,i,p,sum,n,num[14];
	for(k=1;k<=13;k++)
	{
		n=1,p=k;i=k+1;sum=2*k;
		while(sum>k)
		{
			if(p>=k)
			{
				sum--;
				p=(p-1+i)%sum;
			}
			else
			{
				sum=2*k;
				if(i%(k+1))
				{
					n++;
					i=(k+1)*n;
				}
				else
					i=(k+1)*n+1;
				p=(i-1)%sum;
			}
		}
		num[k]=i;
	}
	while(cin>>k,k)
		cout<<num[k]<<endl;
	return 0;
}
