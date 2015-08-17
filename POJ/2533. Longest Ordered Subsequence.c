/*
Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.
Sample Input

7
1 7 3 5 9 4 8
Sample Output

4

*/

#include <stdio.h>
#define N 1005

int arr[N], tailM[N];

int Bsearch(int element, int n)
{
	int low = 0, high = n, mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if (tailM[mid] == element)
			return mid;
		else
		{
			if (tailM[mid] > element)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return low;
}

int main()
{
	int i, n, res, pos;
	while(scanf("%d", &n) != EOF)
	{
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		res = 0;
		tailM[0] = arr[0];
		for(i = 1;i < n;i++)
		{
			if (tailM[res] < arr[i])
			{
				res++;
				tailM[res] = arr[i];
			}
			else
			{
				pos = Bsearch(arr[i], res);
				tailM[pos] = arr[i];
			}
		}
		printf("%d\n", res + 1);
	}
	return 0;
}

