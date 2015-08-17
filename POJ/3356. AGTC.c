/*
Description

Let x and y be two strings over some finite alphabet A. We would like to transform x into y allowing only operations given below:

Deletion: a letter in x is missing in y at a corresponding position.
Insertion: a letter in y is missing in x at a corresponding position.
Change: letters at corresponding positions are distinct
Certainly, we would like to minimize the number of all possible operations.

Illustration
A G T A A G T * A G G C

| | |       |   |   | |

A G T * C * T G A C G C
Deletion: * in the bottom line
Insertion: * in the top line
Change: when the letters at the top and bottom are distinct
This tells us that to transform x = AGTCTGACGC into y = AGTAAGTAGGC we would be required to perform 5 operations (2 changes, 2 deletions and 1 insertion). If we want to minimize the number operations, we should do it like

A  G  T  A  A  G  T  A  G  G  C

|  |  |        |     |     |  |

A  G  T  C  T  G  *  A  C  G  C
and 4 moves would be required (3 changes and 1 deletion).

In this problem we would always consider strings x and y to be fixed, such that the number of letters in x is m and the number of letters in y is n where n ≥ m.

Assign 1 as the cost of an operation performed. Otherwise, assign 0 if there is no operation performed.

Write a program that would minimize the number of possible operations to transform any string x into a string y.

Input

The input consists of the strings x and y prefixed by their respective lengths, which are within 1000.

Output

An integer representing the minimum number of possible operations to transform any string x into a string y.

Sample Input

10 AGTCTGACGC
11 AGTAAGTAGGC
Sample Output

4
*/



#include <stdio.h>
#define N 1005

int dp[N][N];

int main()
{
	int i, j, n1, n2, temp, res;
	char s1[N], s2[N];

	while(scanf("%d", &n1) != EOF)
	{
		scanf("%s", s1);
		scanf("%d", &n2);
		scanf("%s", s2);

		dp[0][0] = 0;
		for(i = 0;i <= n1;i++)
			dp[i][0] = i;

		for(i = 0;i <= n2;i++)
			dp[0][i] = i;

		for(i = 1;i <= n1;i++)
			for(j = 1;j <= n2;j++)
			{
				dp[i][j] = dp[i-1][j-1];
				if (s1[i-1] != s2[j-1])
					dp[i][j]++;

				if (dp[i-1][j] + 1 < dp[i][j])
					dp[i][j] = dp[i-1][j] + 1;
				
				if (dp[i][j-1] + 1 < dp[i][j])
					dp[i][j] = dp[i][j-1] + 1;
			}
		res = dp[n1][n2];

		printf("%d\n", res);
	}
	return 0;
}
