/*
Description

Frosh commencing their studies at Waterloo have diverse interests, as evidenced by their desire to take various combinations of courses from among those available.

University administrators are uncomfortable with this situation, and therefore wish to offer a conformity prize to frosh who choose one of the most popular combinations of courses. How many frosh will win the prize?

Input

The input consists of several test cases followed by a line containing 0. Each test case begins with an integer 1 ≤ n ≤ 10000, the number of frosh. For each frosh, a line follows containing the course numbers of five distinct courses selected by the frosh. Each course number is an integer between 100 and 499.

The popularity of a combination is the number of frosh selecting exactly the same combination of courses. A combination of courses is considered most popular if no other combination has higher popularity.

Output

For each line of input, you should output a single line giving the total number of students taking some combination of courses that is most popular.

Sample Input

3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0
Sample Output

2
3
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
struct p
{
	int a[6];
}arr[10005];

int cmp(const void *a1, const void *a2)
{
	int i;
	for(i=0;i<5;i++)
	{
		if((*(p *)a1).a[i]!=(*(p *)a2).a[i])
			return (*(p *)a1).a[i] > (*(p *)a2).a[i] ? 1 : -1;
	}
	return 1;
}
int ccp(const void *a1, const void *a2)
{
	return (*(int *)a1) > (*(int *)a2) ? 1 : -1;
}
int main()
{
	int i,j,n,rel,temp,max;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
				scanf("%d",&arr[i].a[j]);
			qsort(arr[i].a,5,sizeof(int),ccp);
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		max=temp=1;
		for(i=1;i<n;i++)
		{
			for(j=0;j<5;j++)
				if(arr[i-1].a[j]!=arr[i].a[j])
					break;
			if(j>=5)
			{
				temp++;
				if(max<temp)
					max=temp;
			}
			else
    			temp=1;
		}
		if(max==1)
		{
			printf("%d\n",n);
   			continue;
  		}
		temp=1;rel=0;
		for(i=1;i<n;i++)
		{
			for(j=0;j<5;j++)
				if(arr[i-1].a[j]!=arr[i].a[j])
					break;
			if(j>=5)
			{
				temp++;
				if(max==temp)
					rel++;
			}
			else
    			temp=1;
		}
		printf("%d\n",rel*max);
	}
	return 0;
}
