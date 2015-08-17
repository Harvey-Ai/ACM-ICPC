/*
Description

Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. 
As an example, the maximal sub-rectangle of the array: 

0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
is in the lower left corner: 

9 2 
-4 1 
-1 8 
and has a sum of 15. 
Input

The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
Output

Output the sum of the maximal sub-rectangle.
Sample Input

4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
Sample Output

15
*/

#include <stdio.h>
#define N 105

int arr[N][N], sum[N][N], compress[N];

int maxSeg(int *seg, int n)
{
	int i, sum = 0, max = 0;
	for(i = 0;i < n;i++)
	{
		sum += seg[i];
		if (sum < 0)
			sum = 0;
		else
			if (sum > max)
				max = sum;
	}
	return max;

}
int main()
{
	int n, i, j, k, res, temp;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			scanf("%d", &arr[i][j]);


	for(i = 0;i < n;i++)
	{
		sum[i][0] = 0;
		sum[i][1] = arr[i][0];
	}
	for(i = 0;i < n;i++)
		for(j = 1;j < n;j++)
			sum[i][j+1] = sum[i][j] + arr[i][j];

	res = -1000000;
	for(i = 0 ;i < n;i++)
		for(j = i + 1;j <= n;j++)
		{
			for(k = 0;k < n;k++)
				compress[k] = sum[k][j] - sum[k][i];

			temp = maxSeg(compress, n);
			if (temp > res)
				res = temp;
		}
	printf("%d\n", res);
	return 0;
}

