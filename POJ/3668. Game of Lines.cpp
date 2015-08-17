/*
Description

Farmer John has challenged Bessie to the following game: FJ has a board with dots marked at N (2 ≤ N ≤ 200) distinct lattice points. Dot i has the integer coordinates Xi and Yi (-1,000 ≤ Xi ≤ 1,000; -1,000 ≤ Yi ≤ 1,000).

Bessie can score a point in the game by picking two of the dots and drawing a straight line between them; however, she is not allowed to draw a line if she has already drawn another line that is parallel to that line. Bessie would like to know her chances of winning, so she has asked you to help find the maximum score she can obtain.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 describes lattice point i with two space-separated integers: Xi and Yi.

Output

* Line 1: A single integer representing the maximal number of lines Bessie can draw, no two of which are parallel.
　

Sample Input

4
-1 1
-2 0
0 0
1 1
Sample Output

4
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
double p[201][2],arr[500000];
int main()
{
	int i,j,cnt,n,f,res;
	scanf("%d",&n);
	cnt=0;f=0;
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&p[i][0],&p[i][1]);
		for(j=0;j<i;j++)
		{
			if((p[i][0]-p[j][0])!=0)
				arr[cnt++]=(p[i][1]-p[j][1])/(p[i][0]-p[j][0]);
			else
				f=1;
		}
	}
	sort(&arr[0],&arr[cnt]);
	res=1;
	for(i=1;i<cnt;i++)
		if(arr[i]!=arr[i-1])
			res++;
	printf("%d\n",res+f);
	return 0;
}


