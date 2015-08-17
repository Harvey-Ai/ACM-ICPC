/*
Description

The Recaman's sequence is defined by a0 = 0 ; for m > 0, am = am−1 − m if the rsulting am is positive and not already in the sequence, otherwise am = am−1 + m. 
The first few numbers in the Recaman's Sequence is 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9 ... 
Given k, your task is to calculate ak.
Input

The input consists of several test cases. Each line of the input contains an integer k where 0 <= k <= 500000. 
The last line contains an integer −1, which should not be processed.
Output

For each k given in the input, print one line containing ak to the output.
Sample Input

7
10000
-1
Sample Output

20
18658
*/

#include <stdio.h>

long long arr[500005];
int used[10000000];

int main()
{
	int i, a, temp;
	arr[0] = 0;

	for(i = 1;i < 500001;i++)
	{
		temp = arr[i-1] - i;
		if(temp > 0 && !used[temp] )
		{
			arr[i] = temp;
			used[temp] = 1;
		}
		else
		{
			arr[i] = arr[i-1] + i;
			used[arr[i]] = 1;
		}
	}

	while(scanf("%d", &a), a != -1)
		printf("%lld\n", arr[a]);
	return 0;
}
