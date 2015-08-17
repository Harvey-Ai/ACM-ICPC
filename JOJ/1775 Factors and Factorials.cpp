#include <iostream>
using namespace std;
int main()
{
	int n,i,j,p,t,s,max;
	int sieve[10000],count[10000][2]; 
	for(i=2;i<10000;i++)
		sieve[i]=1;
	for(i=2;i<5000;i++)
		sieve[i*2]=0;
	p=1;
	while(p*p<10000)
	{
		p++; 
		while(sieve[p]==0) 
			p++; 
		t=p*p;
		s=p*2;
		while(t<10000) 
		{ 
			sieve[t]=0;  
			t+=s;
		} 
	} 
	j=0;
	for(i=2;i<=10000;i++) 	 
		if(sieve[i]!=0)
		{
			count[j++][0]=i; 
			count[j-1][1]=0;
		}

	while(cin>>n,n)
	{
		max=0;
		for(i=2;i<=n;i++)
		{
			j=0;t=i;
			while(t!=1)
			{
				if(t%count[j][0]==0)
				{
					count[j][1]++;
					t/=count[j][0];
					if(j>max)
						max=j;
					j=-1;
				}
				j++;
			}
		}
		cout.width(3);
		cout<<n<<"!"<<" =";
		cout.width(3);
		cout<<count[0][1];
		count[0][1]=0;
		for(i=1;i<=max;i++)
		{
			if(i%15==0)
				cout<<endl<<"      ";
			cout.width(3);
			cout<<count[i][1];
			count[i][1]=0;
		}
		cout<<endl;
	}
	return 0;
}

