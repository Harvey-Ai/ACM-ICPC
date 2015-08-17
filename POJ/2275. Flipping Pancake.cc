/*
Description

We start with a stack n of pancakes of distinct sizes. The problem is to convert the stack to one in which the pancakes are in size order with the smallest on the top and the largest on the bottom. To do this, we are allowed to flip the top k pancakes over as a unit (so the k-th pancake is now on top and the pancake previously on top is now in the k-th position). 

For example: 


This problem is to write a program, which finds a sequence of at most (2n - 3) flips, which converts a given stack of pancakes to a sorted stack. 
Input

Each line of the input gives a separate data set as a sequence of numbers separated by spaces. The first number on each line gives the number, N, of pancakes in the data set. The input ends when N is 0 (zero) with no other data on the line. The remainder of the data set are the numbers 1 through N in some order giving the initial pancake stack. 

The numbers indicate the relative sizes of the pancakes. N will be, at most, 30.
Output

For each data set, the output is a single-space separated sequence of numbers on a line. The first number on each line, K, gives the number of flips required to sort the pancakes. This number is followed by a sequence of K numbers, each of which gives the number of pancakes to flip on the corresponding sorting step. There may be several correct solutions for some datasets. For instance 3 3 2 3 is also a solution to the first problem below.
Sample Input

3 1 3 2
5 4 3 2 5 1
0
Sample Output

3 2 3 2
3 3 4 5
*/

#include <stdio.h>

int arr[50];
int ansNum;
int ans[100];
int main()
{
	int i, j, w;
	int n;
	int tt, kk;
	int temp;

	while(scanf("%d", &n), n)
	{
		ansNum = 0;
		kk = 0;
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);
		for(tt = n;tt >= 1;tt--)
		{
			for(j = 0;j < n;j++)
				if (tt == arr[j])
					break;
			if (j + 1 == tt)
				continue;

			for(w = 0;w < (j + 1) / 2;w++)
			{
				temp = arr[w];
				arr[w] = arr[j - w];
				arr[j - w] = temp;
			}
			if (j != 0)
				ans[ansNum++] = j + 1;

			for(w = 0;w < tt / 2;w++)
			{
				temp = arr[w];
				arr[w] = arr[tt - 1 - w];
				arr[tt - 1 - w] = temp;
			}
			if (tt != 1)
				ans[ansNum++] = tt;
		}
		if (ansNum > 2 * n - 3 && n > 1)
			while(1);
		if (ansNum != 0 && n == 1)
			while(1);
		printf("%d", ansNum);
		for(i = 0;i < ansNum;i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
