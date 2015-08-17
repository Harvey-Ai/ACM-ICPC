/*
Description

Given four positive integers M, D, L, R, your task is to find the minimal non-negative integer x which satisfies L ≤ ( D × x mod M ) ≤ R, where mod is the remainder operation

Input

The first line contains one number N -- the number of test cases.(1 ≤ N ≤ 100)
Each of the following N lines contains four integers M, D, L, R ( 1≤ M, D, L, R ≤ 2,000,000,000)

Output

For each test case, print the minimal x. If there is no such x, print "-1" instead.

Sample Input

4
4 3 1 1
4 2 1 1
4 2 2 4
4 4 4 4
Sample Output

3
-1
1
-1
*/


#include <stdio.h>
__int64 gcd(__int64 a,__int64 b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	__int64 t,s,m,d,l,r;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64u %I64u %I64u %I64u",&m,&d,&l,&r); 
		if(m<=l||l>r)
		{
			printf("-1\n");
			continue;
		}
		t=d%m;
		if(r-l<=t)
		{
			s=t/gcd(m,t);
			for(j=0;j<s;l+=m,r+=m,j++)
				if(l%t==0||r%t==0)
					break;
			if(j<s)
			{
				if(l%t==0) printf("%I64u\n",l/t);
				else  printf("%I64u\n",r/t);
			}
			else
				printf("-1\n");
		}
		else
		{
			if(l%t) printf("%I64u\n",l/t);
			printf("%I64u\n",l/t+1);
		}
	}
	return 0;
}
