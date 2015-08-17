/*
Description

Bessie is training for her next race by running on a path that includes hills so that she will be prepared for any terrain. She has planned a straight path and wants to run as far as she can -- but she must be back to the farm within M seconds (1 ≤ M ≤ 10,000,000).

The entire path she has chosen is T units (1 ≤ T ≤ 100,000) in length and consists of equal-length portions that are uphill, flat, or downhill. The input data describes path segment i with a single character Si that is u, f, or d, indicating respectively uphill, flat, or downhill.

Bessie takes U seconds (1 ≤ U ≤ 100) to run one unit of uphill path, F (1 ≤ F ≤ 100) seconds for a unit of flat path, and D (1 ≤ D ≤ 100) seconds for a unit of downhill path. Note that, when returning home, uphill paths become downhill paths and downhill paths become uphill paths.

Find the farthest distance Bessie can get from the farm and still make it back in time.

Input

* Line 1: Five space-separated integers: M, T, U, F, and D
* Lines 2..T+1: Line i+1 describes path segment i with a single letter: Si

Output

* Line 1: A single integer that is the farthest distance (number of units) that Bessie can get from the farm and make it back in time.

Sample Input

13 5 3 2 1
u
f
u
d
f
Sample Output

3

*/


#include <stdio.h>
char arr[100001];
int main()
{
	int i,m,t,u,f,d,time;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(i=0;i<t;i++)
	{
		getchar();
		arr[i]=getchar();
	}
	time=0;i=0;
	while(time<=m&&i<t)
	{
		if(arr[i]=='u'||arr[i]=='d')
			time+=u+d;
		else
			time+=2*f;
		i++;
	}
	if(time<=m)
		i++;
	printf("%d\n",i-1);
	return 0;
}
