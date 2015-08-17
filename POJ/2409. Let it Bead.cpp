/*
Description

"Let it Bead" company is located upstairs at 700 Cannery Row in Monterey, CA. As you can deduce from the company name, their business is beads. Their PR department found out that customers are interested in buying colored bracelets. However, over 90 percent of the target audience insists that the bracelets be unique. (Just imagine what happened if two women showed up at the same party wearing identical bracelets!) It's a good thing that bracelets can have different lengths and need not be made of beads of one color. Help the boss estimating maximum profit by calculating how many different bracelets can be produced. 

A bracelet is a ring-like sequence of s beads each of which can have one of c distinct colors. The ring is closed, i.e. has no beginning or end, and has no direction. Assume an unlimited supply of beads of each color. For different values of s and c, calculate the number of different bracelets that can be made.
Input

Every line of the input file defines a test case and contains two integers: the number of available colors c followed by the length of the bracelets s. Input is terminated by c=s=0. Otherwise, both are positive, and, due to technical difficulties in the bracelet-fabrication-machine, cs<=32, i.e. their product does not exceed 32.
Output

For each test case output on a single line the number of unique bracelets. The figure below shows the 8 different bracelets that can be made with 2 colors and 5 beads.
Sample Input

1 1
2 1
2 2
5 1
2 5
2 6
6 2
0 0
Sample Output

1
2
3
5
8
13
21

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
	int c, s;
	while (scanf("%d%d", &c, &s),s&&c) {
		int k;
		long long p[64]; p[0] = 1; // power of c
		for (k=0 ; k<s ; k++) p[k+1] = p[k] * c;
		// reflection part
		long long count = s&1 ? s * p[s/2 + 1] :
		                  (s/2) * (p[s/2] + p[s/2 + 1]);
		// rotation part
		for (k=1 ; k<=s ; k++) count += p[gcd(k, s)];
		count /= 2 * s;
		cout << count << '\n';
	}
	return 0;
}
