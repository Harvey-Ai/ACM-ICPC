/*
Description

Longge is good at mathematics and he likes to think about hard mathematical problems which will be solved by some graceful algorithms. Now a problem comes: Given an integer N(1 < N < 2^31),you are to calculate ∑gcd(i, N) 1<=i <=N. 

"Oh, I know, I know!" Longge shouts! But do you know? Please solve it. 
Input

Input contain several test case. 
A number N per line. 
Output

For each N, output ,∑gcd(i, N) 1<=i <=N, a line
Sample Input

2
6
Sample Output

3
15
*/


#include <stdio.h>
#include <string.h>
__int64 pc,t;
__int64 res,nn;
__int64 primes[100005],mk[100005],jie[10000];
__int64 fen[10000];
__int64 euler_phi(__int64 n)
{
	__int64 i,j,phi=n;
	for(i=2,j=4;j<=n;i++,j+=i+i-1)
		if(!(n%i))
		{
			phi=phi/i*(i-1);
			while(!(n%i))	n/=i;
		}
	if(n>1)	phi=phi/n*(n-1);
	return phi;
}
void GenPrimes(__int64 n)
{
	__int64 i,j,k;
	for(i=0;i<n;i++)
		mk[i]=0;
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
void dfs(__int64 m,__int64 k)
{
	if(k>=t)
		return;
	__int64 i;
	__int64 temp=m;
	for(i=0;i<jie[k];i++)
	{
		dfs(temp,k+1);
		temp*=fen[k];
		res+=euler_phi(nn/temp)*temp;
	}
	dfs(temp,k+1);
}
int main()
{
	GenPrimes(100000);
	while(scanf("%I64d",&nn)!=EOF)
	{
		int i,cnt;
		__int64 temp;
		temp=nn;
		t=0;
		res=euler_phi(nn);
		for(i=0;i<pc&&nn>=primes[i];i++)
		{
			cnt=0;
			while(nn%primes[i]==0)
			{
				nn/=primes[i];
				cnt++;
			}
			if(cnt)
			{
				jie[t]=cnt;
				fen[t++]=primes[i];
			}
		}
		if(nn!=1)
		{
			jie[t]=1;
			fen[t++]=nn;
		}
		nn=temp;
		dfs(1,0);
		printf("%I64d\n",res);
	}
	return 0;
}
