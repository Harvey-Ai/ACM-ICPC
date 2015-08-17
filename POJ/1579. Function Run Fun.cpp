/*
Description

We all love recursion! Don't we? 

Consider a three-parameter recursive function w(a, b, c): 

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns: 
1 

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns: 
w(20, 20, 20) 

if a < b and b < c, then w(a, b, c) returns: 
w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c) 

otherwise it returns: 
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) 

This is an easy function to implement. The problem is, if implemented directly, for moderate values of a, b and c (for example, a = 15, b = 15, c = 15), the program takes hours to run because of the massive recursion. 
Input

The input for your program will be a series of integer triples, one per line, until the end-of-file flag of -1 -1 -1. Using the above technique, you are to calculate w(a, b, c) efficiently and print the result.
Output

Print the value for w(a,b,c) for each triple.
Sample Input

1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
Sample Output

w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1
*/


#include <stdio.h>

long long w[21][21][21];
int main()
{
	int i, j, k, a, b, c;

	w[0][0][0] =1;

	for(i = 0;i <= 20;i++)
		for(j = 0;j <=20;j++)
			w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;

	for(i = 1;i <= 20;i++)
		for(j = 1;j <= 20;j++)
			for(k = 1;k <= 20;k++)
				if (i < j && j < k)
					w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];

	while(scanf("%d %d %d", &a, &b, &c), a != -1 || b != -1 || c != -1)
	{
		if (a <= 0 || b <= 0 || c <= 0)
		{
			printf("w(%d, %d, %d) = 1\n", a, b, c);
			continue;
		}
		if (a > 20 || b > 20 || c > 20)
			printf("w(%d, %d, %d) = %lld\n", a, b, c, w[20][20][20]);
		else
			printf("w(%d, %d, %d) = %lld\n", a, b, c, w[a][b][c]);
	}
	return 0;
}
