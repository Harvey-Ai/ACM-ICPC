/*
Description

A military contractor for the Department of Defense has just completed a series of preliminary tests for a new defensive missile called the CATCHER which is capable of intercepting multiple incoming offensive missiles. The CATCHER is supposed to be a remarkable defensive missile. It can move forward, laterally, and downward at very fast speeds, and it can intercept an offensive missile without being damaged. But it does have one major flaw. Although it can be fired to reach any initial elevation, it has no power to move higher than the last missile that it has intercepted. 

The tests which the contractor completed were computer simulations of battlefield and hostile attack conditions. Since they were only preliminary, the simulations tested only the CATCHER's vertical movement capability. In each simulation, the CATCHER was fired at a sequence of offensive missiles which were incoming at fixed time intervals. The only information available to the CATCHER for each incoming missile was its height at the point it could be intercepted and where it appeared in the sequence of missiles. Each incoming missile for a test run is represented in the sequence only once. 

The result of each test is reported as the sequence of incoming missiles and the total number of those missiles that are intercepted by the CATCHER in that test. 

The General Accounting Office wants to be sure that the simulation test results submitted by the military contractor are attainable, given the constraints of the CATCHER. You must write a program that takes input data representing the pattern of incoming missiles for several different tests and outputs the maximum numbers of missiles that the CATCHER can intercept for those tests. For any incoming missile in a test, the CATCHER is able to intercept it if and only if it satisfies one of these two conditions: 

The incoming missile is the first missile to be intercepted in this test. 
-or- 
The missile was fired after the last missile that was intercepted and it is not higher than the last missile which was intercepted.
Input

The input data for any test consists of a sequence of one or more non-negative integers, all of which are less than or equal to 32,767, representing the heights of the incoming missiles (the test pattern). The last number in each sequence is -1, which signifies the end of data for that particular test and is not considered to represent a missile height. The end of data for the entire input is the number -1 as the first value in a test; it is not considered to be a separate test.
Output

Output for each test consists of a test number (Test #1, Test #2, etc.) and the maximum number of incoming missiles that the CATCHER could possibly intercept for the test. That maximum number appears after an identifying message. There must be at least one blank line between output for successive data sets. 

Note: The number of missiles for any given test is not limited. If your solution is based on an inefficient algorithm, it may not execute in the allotted time. 
Sample Input

389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1
Sample Output

Test #1:
  maximum possible interceptions: 6

Test #2:
  maximum possible interceptions: 2
*/


#include <stdio.h>
#define N 100005

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
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return low;
}

int main()
{
	int i, len, res, pos, ncase = 1;
	while(scanf("%d", &arr[0]), arr[0] != -1)
	{
		for(i = 1;arr[i-1] != -1;i++)
			scanf("%d", &arr[i]);

		len = i -1 ;
		res = 0;
		tailM[0] = arr[0];
		for(i = 1;i < len;i++)
		{
			if (tailM[res] > arr[i])
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
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n", ncase++, res + 1);
	}
	return 0;
}
