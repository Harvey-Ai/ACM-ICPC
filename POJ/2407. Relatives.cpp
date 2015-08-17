/*
Description

Given n, a positive integer, how many positive integers less than n are relatively prime to n? Two integers a and b are relatively prime if there are no integers x > 1, y > 0, z > 0 such that a = xy and b = xz.
Input

There are several test cases. For each test case, standard input contains a line with n <= 1,000,000,000. A line containing 0 follows the last case.
Output

For each test case there should be single line of output answering the question posed above.
Sample Input

7
12
0
Sample Output

6
4
*/

#include <stdio.h>
__int64 euler_phi(int n)
{
	__int64 phi=n;
	int i,j;
	for(i=2,j=4;j<=n;i++,j+=i+i-1)
		if(!(n%i))
		{
			phi=phi/i*(i-1);
			while(!(n%i))	n/=i;
		}
	if(n>1)	phi=phi/n*(n-1);
	return phi;
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
		printf("%I64d\n",euler_phi(n));
	return 0;
}
