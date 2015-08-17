/*
Description

Farmer John is assigning some of his N (1 <= N <= 25,000) cows to do some cleaning chores around the barn. He always wants to have one cow working on cleaning things up and has divided the day into T shifts (1 <= T <= 1,000,000), the first being shift 1 and the last being shift T. 

Each cow is only available at some interval of times during the day for work on cleaning. Any cow that is selected for cleaning duty will work for the entirety of her interval. 

Your job is to help Farmer John assign some cows to shifts so that (i) every shift has at least one cow assigned to it, and (ii) as few cows as possible are involved in cleaning. If it is not possible to assign a cow to each shift, print -1.
Input

* Line 1: Two space-separated integers: N and T 

* Lines 2..N+1: Each line contains the start and end times of the interval during which a cow can work. A cow starts work at the start time and finishes after the end time.
Output

* Line 1: The minimum number of cows Farmer John needs to hire or -1 if it is not possible to assign a cow to each shift.
Sample Input

3 10
1 7
3 6
6 10
Sample Output

2
Hint

This problem has huge input data,use scanf() instead of cin to read data to avoid time limit exceed. 

INPUT DETAILS: 

There are 3 cows and 10 shifts. Cow #1 can work shifts 1..7, cow #2 can work shifts 3..6, and cow #3 can work shifts 6..10. 

OUTPUT DETAILS: 

By selecting cows #1 and #3, all shifts are covered. There is no way to cover all the shifts using fewer than 2 cows.

*/

#include <stdio.h>
#include <algorithm>
using namespace std;
struct dd
{
	int x,y;
}arr[25001];
bool cmp(const dd a,const dd b)
{
	return a.x<b.x;
}
int main()
{
	int i,p,cnt,max,id,n,t;
	scanf("%d%d",&n,&t);
	arr[0].x=arr[0].y=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&arr[i].x,&arr[i].y);
	sort(&arr[0],&arr[n+1],cmp);
	max=0;p=0;cnt=0;
	while(p<=n)
	{
		id=0;
		for(i=p+1;i<=n&&arr[i].x-1<=arr[p].y;i++)
			if(arr[i].y>max)
			{
				id=i;
				max=arr[i].y;
			}
		if(id)
		{
			cnt++;
			p=id;
		}
		else
			p=n+1;
	}
	if(max<t)
		printf("-1\n");
	else
		printf("%d\n",cnt);
	return 0;
}
