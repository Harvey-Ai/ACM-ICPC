/*
Description

Marsha and Bill own a collection of marbles. They want to split the collection among themselves so that both receive an equal share of the marbles. This would be easy if all the marbles had the same value, because then they could just split the collection in half. But unfortunately, some of the marbles are larger, or more beautiful than others. So, Marsha and Bill start by assigning a value, a natural number between one and six, to each marble. Now they want to divide the marbles so that each of them gets the same total value. Unfortunately, they realize that it might be impossible to divide the marbles in this way (even if the total value of all marbles is even). For example, if there are one marble of value 1, one of value 3 and two of value 4, then they cannot be split into sets of equal value. So, they ask you to write a program that checks whether there is a fair partition of the marbles.
Input

Each line in the input file describes one collection of marbles to be divided. The lines contain six non-negative integers n1 , . . . , n6 , where ni is the number of marbles of value i. So, the example from above would be described by the input-line "1 0 1 2 0 0". The maximum total number of marbles will be 20000. 
The last line of the input file will be "0 0 0 0 0 0"; do not process this line.
Output

For each collection, output "Collection #k:", where k is the number of the test case, and then either "Can be divided." or "Can't be divided.". 
Output a blank line after each test case.
Sample Input

1 0 1 2 0 0 
1 0 0 0 1 1 
0 0 0 0 0 0 
Sample Output

Collection #1:
Can't be divided.

Collection #2:
Can be divided.
*/


#include <stdio.h>
#include <string.h>
#define MAXN 60005
int values[MAXN];
int flags[MAXN];

int main()
{
	int a[5];
	int ncase = 1;
	int i, j, k, temp, cnt, sum;

	while(scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]), a[0] || a[1] || a[2] || a[3] || a[4] || a[5])
	{
		for (i = 0;i < 6;i++)
		{
			if (a[i] > 12)
			{
				if (a[i] % 2)
					a[i] = 11;
				else
					a[i] = 12;
			}
		}

		memset(flags, 0, sizeof(flags));

		flags[0] = 1;
		values[0] = 0;
		cnt = 1;

		sum = 0;
		for(i = 0;i < 6;i++)
			sum += (i + 1)*a[i];

		if (sum % 2)
		{
			printf("Collection #%d:\nCan't be divided.\n\n", ncase++);
			continue;
		}

		for(i = 0;i < 6;i++)
		{
			for(j = 0;j < a[i];j++)
			{
				temp = cnt;
				for (k = 0;k < cnt;k++)
				{
					if (values[k] + i + 1 <= sum / 2 && flags[values[k] + i + 1] == 0)
					{
						values[temp++] = values[k] + i + 1;
						flags[values[k] + i + 1] = 1;
					}
				}
				cnt = temp;
				if (flags[sum / 2])
					break;
			}
			if (flags[sum / 2])
					break;
		}

		if (flags[sum / 2])
			printf("Collection #%d:\nCan be divided.\n\n", ncase++);
		else
			printf("Collection #%d:\nCan't be divided.\n\n", ncase++);
	}
	return 0;
}
