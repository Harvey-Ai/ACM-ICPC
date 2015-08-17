/*
Description

Given a positive integer X, an X-factor chain of length m is a sequence of integers,

1 = X0, X1, X2, …, Xm = X

satisfying

Xi < Xi+1 and Xi | Xi+1 where a | b means a perfectly divides into b.

Now we are interested in the maximum length of X-factor chains and the number of chains of such length.

Input

The input consists of several test cases. Each contains a positive integer X (X ≤ 220).

Output

For each test case, output the maximum length and the number of such X-factors chains.

Sample Input

2
3
4
10
100
Sample Output

1 1
1 1
2 1
2 2
4 6
*/

#include <stdio.h>
#include <string.h>
int pc;
int mk[2010],primes[2010];
void GenPrimes(int n)
{
	int i,j,k;
	memset(mk,0,n+1);
	pc=0;
	for(i=2,k=4;i<=n;i++,k+=i+i-1)
		if(!mk[i])
		{
			primes[pc++]=i;
			if(k<=n)
				for(j=k;j<=n;j+=i)
					mk[j]=true;
		}
}
int main()
{
	GenPrimes(1200);
	int i,n;
	__int64 jiecheng[21];
	jiecheng[0]=1;
	for(i=1;i<21;i++)
		jiecheng[i]=jiecheng[i-1]*i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			printf("0 0\n");
			continue;
		}
		int sum;
		__int64 res;
		int cnt[1200]={0};
		sum=0;
		for(i=0;i<pc&&n!=1;i++)
		{
			while(n%primes[i]==0)
			{
				n/=primes[i];
				cnt[i]++;
			} 
			sum+=cnt[i];
		}
		if(n!=1)
			sum++;
		res=jiecheng[sum];
		for(i=0;i<pc;i++)
			if(cnt[i])
				res/=jiecheng[cnt[i]];
		printf("%d %I64d\n",sum,res);
	}
	return 0;
}
