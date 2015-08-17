/*
Description

The Farey Sequence Fn for any integer n with n >= 2 is the set of irreducible rational numbers a/b with 0 < a < b <= n and gcd(a,b) = 1 arranged in increasing order. The first few are 
F2 = {1/2} 
F3 = {1/3, 1/2, 2/3} 
F4 = {1/4, 1/3, 1/2, 2/3, 3/4} 
F5 = {1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5} 

You task is to calculate the number of terms in the Farey sequence Fn.
Input

There are several test cases. Each test case has only one line, which contains a positive integer n (2 <= n <= 106). There are no blank lines between cases. A line with a single 0 terminates the input.
Output

For each test case, you should output one line, which contains N(n) ---- the number of terms in the Farey sequence Fn. 
Sample Input

2
3
4
5
0
Sample Output

1
3
5
9
*/

#include <stdio.h>
__int64 ph[1000005];
void all_phi(int n,__int64 phi[])
{
	int i,j;
	phi[1]=1;
	for(i=2;i<=n;i++)
		if(!phi[i])
			for(j=i;j<=n;j+=i)
			{
				if(!phi[j])	phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
}

int main()
{
	all_phi(1000000,ph);
	ph[1]=0;
	int i,n;
	for(i=2;i<=1e6;i++)
		ph[i]+=ph[i-1];
	while(scanf("%d",&n),n)
		printf("%I64d\n",ph[n]);
	return 0;
}
