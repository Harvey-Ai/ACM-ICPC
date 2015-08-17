/*
Description

Beads of red, blue or green colors are connected together into a circular necklace of n beads ( n < 24 ). If the repetitions that are produced by rotation around the center of the circular necklace or reflection to the axis of symmetry are all neglected, how many different forms of the necklace are there? 


Input

The input has several lines, and each line contains the input data n. 
-1 denotes the end of the input file. 
Output

The output should contain the output data: Number of different forms, in each line correspondent to the input data.
Sample Input

4
5
-1
Sample Output

21
39
*/


/*
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
		int i,j,pp,temp,sum,res,x,y;
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
		res=(-y*temp/count)%s;
		if(res<0)
			res+=s;
		printf("%d\n",res);
	}
	return 0;
}
*/
#include <iostream>
using namespace std;
int gcd (int a, int b) { return b ? gcd(b,a%b) : a; }
int main (void)
{
	int c, s, k;
	__int64 p[64]; p[0] = 1; // power of c
	c=3;
	for (k=0 ; k<30 ; k++) p[k+1] = p[k] * c;
	while (scanf("%d", &s),s!=-1) {
		if(s==0)
		{
			printf("0\n");
			continue;
		}
		// reflection part
		__int64 count = s&1 ? s * p[s/2 + 1] :
			(s/2) * (p[s/2] + p[s/2 + 1]);
		// rotation part
		for (k=1 ; k<=s ; k++)
			count += p[gcd(k, s)];
		count /= 2*s;
		printf("%I64d\n",count);
	}
	return 0;
}
