/*
Description

Let {x} = 0.a1a2a3... be the binary representation of the fractional part of a rational number z. Suppose that {x} is periodic then, we can write

{x} = 0.a1a2...ar(ar+1ar+2...ar+s)w

for some integers r and s with r ≥ 0 and s > 0. Also, (ar+1ar+2...ar+s)wdenotes a nonterminating and repeating binary subsequence of {x}.

The subsequence x1 = a1a2 ... aris called the preperiod of {x} and x2 = ar+1ar+2 ... ar+s is the period of {x}.

Suppose that |x1| and |x2| are chosen as small as possible then x1 is called the least preperiod and x2 is called the least period of {x}.

For example, x = 1/10 = 0.0001100110011(00110011)w and 0001100110011 is a preperiod and 00110011 is a period of 1/10.

However, we can write 1/10 also as 1/10 = 0.0(0011)w and 0 is the least preperiod and 0011 is the least period of 1/10.

The least period of 1/10 starts at the 2nd bit to the right of the binary point and the the length of the least period is 4.

Write a program that finds the position of the first bit of the least period and the length of the least period where the preperiod is also the minimum of a positive rational number less than 1.

Input

Each line is test case. It represents a rational number p/q where p and q are integers, p ≥ 0 and q > 0.

Output

Each line corresponds to a single test case. It represents a pair where the first number is the position of the first bit of the least period and the the second number is the length of the least period of the rational number.

Sample Input

1/10 
1/5 
101/120 
121/1472
Sample Output

Case #1: 2,4 
Case #2: 1,4 
Case #3: 4,4 
Case #4: 7,11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int pc;
int mk[100005],primes[1000005],an[100005];
void GenPrimes(int n)
{
	long long i,j,k;
	memset(mk,0,sizeof(mk));
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
long long euler_phi(long long n)
{ 
	long long i,phi=n;
	for(i=0;primes[i]*primes[i]<=n&&i<pc;i++)
		if(!(n%primes[i]))
		{
			phi=phi/primes[i]*(primes[i]-1);
			while(!(n%primes[i]))	n/=primes[i];
		}
	if(n>1)	phi=phi/n*(n-1);
	return phi;
}
long long gcd(long long x, long long y)
{
	if (!x || !y) return x>y?x:y;//存在0，则返回较大数
	for (long long t; t=x%y; x=y, y=t);
	return y;
}
long long modn(long long a,long long p,long long m)
{
    if (p == 0) return 1;
	long long r = a % m;
	long long k = 1;
    while (p > 1)
    {
        if ((p & 1)!=0)
            k = (k * r) % m;
        r = (r * r) % m;
        p /= 2;
    }
    return (r * k) % m;
}
int main()
{
	GenPrimes(100000);
	int l,cnt;
	long long i,t,temp,p,q,oula;
	l=1;
	while(scanf("%lld",&p)!=EOF)
	{
		getchar();
		scanf("%lld",&q);
		temp=gcd(p,q);
		p/=temp;q/=temp;
		cnt=0;
		while(q%2==0)	
		{
			cnt++;
			q/=2;
		}
		oula=euler_phi(q);
		for(i=1,t=0;i*i<=oula;i++)
			if(oula%i==0)
			{
				an[t++]=i;
				an[t++]=oula/i;
			}
		an[t++]=oula;
		sort(an,an+t);
		for(i=0;i<t;i++)
		{
			temp=modn(2,an[i],q);
			if(temp==1)
				break;
		}
		printf("Case #%d: %d,%d\n",l++,cnt+1,an[i]);
	}
	return 0;
}
