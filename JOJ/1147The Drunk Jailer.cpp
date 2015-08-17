#include <iostream>
using namespace std;
int main()
{
	int prision[101];
	int n,N,i,j,l,sum;
	cin>>N;
	while(N--)
	{
		cin>>n;
		for(i=1;i<101;i+=2)
		{
			prision[i]=1;
			prision[i+1]=0;
		}
		for(j=3;j<=n;j++)
		{
			l=1;
			while(l*j<=n)
			{
				if(prision[l*j])
					prision[l*j]=0;
				else
					prision[l*j]=1;
				l++;
			}
		}
		sum=0;
		for(i=1;i<=n;i++)
			if(prision[i])
				sum++;
		cout<<sum<<endl;
	}
	return 0;
}

