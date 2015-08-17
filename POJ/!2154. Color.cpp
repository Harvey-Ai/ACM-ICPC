/*
Description

Beads of N colors are connected together into a circular necklace of N beads (N<=1000000000). Your job is to calculate how many different kinds of the necklace can be produced. You should know that the necklace might not use up all the N colors, and the repetitions that are produced by rotation around the center of the circular necklace are all neglected. 

You only need to output the answer module a given number P. 
Input

The first line of the input is an integer X (X <= 3500) representing the number of test cases. The following X lines each contains two numbers N and P (1 <= N <= 1000000000, 1 <= P <= 30000), representing a test case.
Output

For each test case, output one line containing the answer.
Sample Input

5
1 30000
2 30000
3 30000
4 30000
5 30000
Sample Output

1
3
11
70
629
*/



#include <stdio.h>
#include <string.h>
int pc,c,s,count;
int mk[100005],primes[100005],fenjie[100005][2];
int gcd (int a, int b) 
{
	return b ? gcd(b,a%b) : a; 
}
void GenPrimes(int n)
{
	int i;
	__int64 j,k;
	memset(mk,0,n);
	pc=0;
	for(i=2,k=4;i<=n;i++,k+=i+i-1)
		if(!mk[i])
		{
			primes[pc++]=i;
			if(k<=n)
				for(j=k;j<=n;j+=i)
					mk[j]=1;
		}
}
int modn(int a,int p,int m)
{
    if (p == 0)
	{
		if(m!=1)
			return 1;
		else
			return 0;
	}
	int r = a % m;
	int k = 1;
    while (p > 1)
    {
        if ((p & 1)!=0)
            k = (k * r) % m;
        r = (r * r) % m;
        p /= 2;
    }
    return (r * k) % m;
}
void extgcd(int a,int b,int &d,int &x,int &y)
{
	if(!b)
	{	
		d=a;	x=1;	y=0;
	}
	else
	{
		extgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

void dfs(int p,int k,int t)
{
	if(k>=t)
		return;
	int i,tt;
	tt=p*fenjie[k][0];
	for(i=1;i<=fenjie[k][1];i++)
	{
		count+=modn(c,tt,s);
		count%=s;
		dfs(tt,k+1,t);
		tt*=fenjie[k][0];
	}
}
int main ()
{
	GenPrimes(100000);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int i,j,pp,temp,sum,x,y;
		scanf("%d%d",&c,&s);
		temp=c;
		for(i=0,j=0,sum=1;i<pc&&c>=primes[i];i++)
		{
			pp=1;
			if(c%primes[i]==0)
			{
				fenjie[j][1]=1;
				fenjie[j++][0]=primes[i];
				c/=primes[i];
				pp=2;
			}
			while(c%primes[i]==0)
			{
				fenjie[j-1][1]++;
				c/=primes[i];
				pp++;
			}
			sum*=pp;
		}
		if(c!=1)
		{
			fenjie[j][0]=c;
			fenjie[j++][1]=1;
			sum*=2;
		}
		c=temp;
		count=(modn(c,1,s)*(c-sum+1))%s;
		dfs(1,0,j);
		temp=count;
		count=-count;
		extgcd(s,-c,count,x,y);
		if(-y*temp/count<0)
			while(1);
		printf("%d\n",(-y*temp/count)%s);
	}
	return 0;
}
