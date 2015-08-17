/*
Description

A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
Input

The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
Output

For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
Sample Input

2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
Sample Output

2
3
*/


#include <stdio.h>
#define N 100005

int arr[N];
int main()
{
	int ncase;
	int s, n;
	int head, tail, max, res;
	int i;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d %d", &n, &s);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		head = -1;
		max = 0;
		res = n + 1;
		for(tail = 0;tail < n;tail++)
		{
			max += arr[tail];
			if (max >= s)
			{
				while (max >= s)
				{
					head++;
					max -= arr[head];
				}

				if (tail - head + 1 < res) 
					res = tail - head + 1;
			}
		}

		printf("%d\n", res == n + 1 ? 0 : res);
	}
	return 0;
}
