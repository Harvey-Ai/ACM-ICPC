#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k,max,sum,temp;
	while(cin>>i>>j)
	{
		if(i>j)
		{
			temp=i;
			i=j;
			j=temp;
		}
		max=1;
		for(n=i;n<=j;n++)
		{
			k=n;sum=1;
			while(k!=1)
			{
				if(k%2)
					k=k*3+1;
				else
					k/=2;
				sum++;
			}
			if(sum>max)
				max=sum;
		}
		cout<<max<<endl;
	}
	return 0;
}