/*
Description

Farmer John is leaving his house promptly at 6 AM for his daily milking of Bessie. However, the previous evening saw a heavy rain, and the fields are quite muddy. FJ starts at the point (0, 0) in the coordinate plane and heads toward Bessie who is located at (X, Y) (-500 ≤ X ≤ 500; -500 ≤ Y ≤ 500). He can see all N (1 ≤ N ≤ 10,000) puddles of mud, located at points (Ai, Bi) (-500 ≤ Ai ≤ 500; -500 ≤ Bi ≤ 500) on the field. Each puddle occupies only the point it is on.

Having just bought new boots, Farmer John absolutely does not want to dirty them by stepping in a puddle, but he also wants to get to Bessie as quickly as possible. He's already late because he had to count all the puddles. If Farmer John can only travel parallel to the axes and turn at points with integer coordinates, what is the shortest distance he must travel to reach Bessie and keep his boots clean? There will always be a path without mud that Farmer John can take to reach Bessie.

Input

* Line 1: Three space-separate integers: X, Y, and N.
* Lines 2..N+1: Line i+1 contains two space-separated integers: Ai and Bi

Output

* Line 1: The minimum distance that Farmer John has to travel to reach Bessie without stepping in mud.

Sample Input

1 2 7
0 2
-1 3
3 1
1 1
4 2
-1 1
2 2
Sample Output

11
*/

#include <stdio.h>
#include <string.h>
int tag[1001][1001],queue[1000000][2],mud[10000][2];
int main()
{
	int i,x,y,tt,rear,h,n;
	scanf("%d%d%d",&x,&y,&n);
	x+=500;y+=500;

	memset(tag,0,sizeof(tag));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&mud[i][0],&mud[i][1]);
		mud[i][0]+=500;
		mud[i][1]+=500;
		tag[mud[i][0]][mud[i][1]]=-1;
	}
	queue[0][0]=queue[0][1]=500;
	h=0;tt=rear=1;
	while(1)
	{
		for(i=h;i<rear;i++)
		{
			if(tag[queue[i][0]][queue[i][1]-1]==0)
			{
				queue[tt][0]=queue[i][0];
				queue[tt++][1]=queue[i][1]-1;
				tag[queue[i][0]][queue[i][1]-1]=tag[queue[i][0]][queue[i][1]]+1;
			}
			if(tag[queue[i][0]][queue[i][1]+1]==0)
			{
				queue[tt][0]=queue[i][0];
				queue[tt++][1]=queue[i][1]+1;
				tag[queue[i][0]][queue[i][1]+1]=tag[queue[i][0]][ queue[i][1]]+1;
			}
			if(tag[queue[i][0]-1][queue[i][1]]==0)
			{
				queue[tt][0]=queue[i][0]-1;
				queue[tt++][1]=queue[i][1];
				tag[queue[i][0]-1][queue[i][1]]=tag[queue[i][0]][queue[i][1]]+1;
			}
			if(tag[queue[i][0]+1][queue[i][1]]==0)
			{
				queue[tt][0]=queue[i][0]+1;
				queue[tt++][1]=queue[i][1];
				tag[queue[i][0]+1][queue[i][1]]=tag[queue[i][0]][queue[i][1]]+1;
			}
		}
		h=rear;rear=tt;
		if(tag[x][y])
			break;
	}
	printf("%d\n",tag[x][y]);
	return 0;
}
