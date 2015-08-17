#include <iostream>
#include <math.h>
using namespace std;
int prime[100000][2];
int main()
{
	int dig1,dig2;
	long i,k,s,t,p,temp,n;

	for(i=1;i<=99999;i++) 
		prime[i][0]=1; 

  	for(i=2;i<=49999;i++) 
		prime[i*2][0]=0;

	prime[0][0]=1;prime[1][0]=2;prime[0][1]=0;prime[1][1]=2;
	p=2;k=2;i=2;
	while(p*p<=99999) 
	{
		p++; 
		while(prime[p][0]==0) 
			p++;
		n=p*p;
		while(i<n)
		{
			if(prime[i][0])
			{
				prime[k][0]=i;prime[k][1]=0;
				while(prime[k][0])
				{
					prime[k][1]+=prime[k][0]%10;
					prime[k][0]/=10;
				}
				prime[k][0]=i;
				k++;
			}
			i++;
		}
		t=p*p; 
		s=2*p; 
		while(t<=99999) 
		{ 
			prime[t][0]=0;  
			t+=s; 
		} 
	}
	while(scanf("%ld",&n),n)
	{
		k=n+1;
		while(1)
		{
			dig1=dig2=0;
			temp=k;
			while(temp)
			{
				dig1+=temp%10;
				temp/=10;
			}
			temp=k;t=sqrt(k);
			for(i=1;prime[i][0]<=t;i++)
			{
				while(temp%prime[i][0]==0)
				{
					temp/=prime[i][0];
					dig2+=prime[i][1];
				}
				if(temp==1)
					break;
				if(dig2>dig1)
					break;
			}
			if(temp==k)
			{
				k++;
				continue;
			}
			if(temp!=1)
				while(temp)
				{
					dig2+=temp%10;
					temp/=10;
				}
			if(dig1==dig2)
			{
				printf("%ld\n",k);
				break;
			}
			else
				k++;
		}
	}
	return 0;
} 

