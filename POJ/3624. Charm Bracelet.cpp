/*
Description

Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms. Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints

Sample Input

4 6
1 4
2 6
3 12
2 7
Sample Output

23
*/

#include <stdio.h>
#include <string.h>
int arr[12881],line[12881],temp[12881][2];
int main()
{
	int i,j,w,d,s,t,rear,n,m,max;
	scanf("%d%d",&n,&m);
	memset(arr,0,sizeof(arr));
	memset(line,0,sizeof(line));
	rear=1;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&w,&d);
		t=rear;s=0;
		for(j=0;j<rear;j++)
			if(line[j]+w<=m&&arr[line[j]]+d>arr[line[j]+w])
			{
				if(arr[line[j]+w]==0)
					line[t++]=line[j]+w;
				temp[s][0]=line[j]+w;
				temp[s++][1]=arr[line[j]]+d;
			}
		for(j=0;j<s;j++)
			arr[temp[j][0]]=temp[j][1];
		rear=t;
	}
	max=0;
	for(j=m;j>=0;j--)
		if(max<arr[j])
			max=arr[j];
	printf("%d\n",max);
	return 0;
}
