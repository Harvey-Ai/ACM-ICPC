/*
Problem Description

yayamao is so clever that he would like to apply post-graduate of MIT(the Massachusetts Institute of Technology).But all the other teammates think that is impossible and daydreaming. wzc gives yayamao a simple puzzle.If yayamao can solve it quickly, wzc promises to support and help yayamao preparing materials.
The puzzle is that, wzc takes out N cards(1,…,N), each card has an integer number Li written on it.yayamao can choose a real number Xi from each card, but the real number should satisfy that |Xi| <= Li.For all choosen Xi, wzc defines a function F(X1,X2,…,XN) = Σ(Xi * Xj)(i < j) and asks yayamao to find the minimum result of the funcion F.

yayamao is stumped by this puzzle and asks you to help him.Can you quickly solve this problem?

 Input

There are multiple cases ,for each case,
First line is the number of cards N (2 <= N <= 40)

Then following N numbers (L1,L2,…LN) that Li (1 <= Li <= 100) is the number written on the ith card.

There may be one or more blank lines between each input case.

 Output

For each case
Output the minimum result of the function F by choosing the group of (X1,X2,…XN). which is rounded to two digits after the decimal point.

 Sample Input

2
2 4

3
1 2 3
 Sample Output

-8.00
-7.00
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int dp[45][4005], set[50];
	int i, j, n, res, max;
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));

		for(i = 0, max = 0;i < n;i++)
		{
			scanf("%d", &set[i]);
			max += set[i];
		}
		
		dp[0][set[0]] = 1;

		for(i = 1;i < n;i++)
			for(j = 0;j <= max;j++)
				if (dp[i-1][j])
				{
					dp[i][j+set[i]] = 1;
					dp[i][abs(j-set[i])] = 1;
				}

		for(j = 0;j <= max; j++)
			if (dp[n-1][j])
			{
				res = j;
				break;
			}
		res *= res;

		for(i = 0;i < n;i++)
			res -= set[i]*set[i];

		printf("%.2lf\n", (double)(res/2));
	}
	return 0;
}
