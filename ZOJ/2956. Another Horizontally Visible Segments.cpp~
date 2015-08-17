/*
There are a number of disjoint vertical line segments in the plane. We say that two vertical line segments are horizontally visible if they can be connected by a horizontal line segment. A clique is a set of vertical line segments, in which any two segments in the set are horizontally visible. Your job is to find the largest clique.

Read the description of a set of vertical segments, you are to compute the largest clique of the segments and output the number of the segments in the largest clique.

Input

The first line of the input contains exactly one positive integer T equal to the number of data sets. T data sets follow.

The first line of each data set contains exactly one integer N (1 <= N <= 4000) equal to the number of vertical line segments.

Each of the following N lines consists of exactly 3 non-negative integers separated by single spaces:

Xi , Yi1 , Yi2 - its x-coordinate, y-coordinate of the beginning of a segment and y-coordinate of its end. The coordinates satisfy 0 <= Yi1 < Yi2 <= 10000. The segments are disjoint.

Output

The output should consist of exactly N lines, one line for each data set. Each line should contain exactly one integer that is the number of the segments in the largest clique.

Sample Input

1
3
1 0 1
2 1 2
3 0 3
Sample Output

3
*/

#include <stdio.h>
#include <memory>
struct p
{
	int x,y1,y2;
}pp[4001];

int main()
{
	int rel[10001];
	int i,j,T,n,max;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&pp[i].x,&pp[i].y1,&pp[i].y2);
		max=0;
		memset(rel,0,sizeof(rel));
		for(i=0;i<n;i++)
			for(j=pp[i].y1;j<=pp[i].y2;j++)
				rel[j]++;
		for(i=0;i<10001;i++)
			if(max<rel[i])
				max=rel[i];
		printf("%d\n",max);
	}
	return 0;
}
