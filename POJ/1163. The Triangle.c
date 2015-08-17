/*
Description

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right. 
Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
Output

Your program is to write to standard output. The highest sum is written as an integer.
Sample Input

5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
Sample Output

30

*/


#include <stdio.h>
#include <string.h>
#define max(a, b)	(a > b ? a : b)
int arr[105], dp[105], buf[105];
int main( void )
{
	int i, j, max, n;

	while(scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(i = 0;i < n;i++)
		{
			for(j = 0;j <= i;j++)
				scanf("%d", &arr[j]);

			buf[0] = dp[0] + arr[0];
			for(j = 1;j < i;j++)
				buf[j] = max(dp[j - 1],  dp[j]) + arr[j];
			buf[j] = dp[j - 1] + arr[j];

			for(j = 0;j <= i;j++)
				dp[j] = buf[j];
		}
		max = 0;
		for(i = 0;i < n;i++)
			if (max < dp[i])
				max = dp[i];
		printf("%d\n", max);
	}
	return 0;
}
