/*
Description

Bessie hears that an extraordinary meteor shower is coming; reports say that these meteors will crash into earth and destroy anything they hit. Anxious for her safety, she vows to find her way to a safe location (one that is never destroyed by a meteor) . She is currently grazing at the origin in the coordinate plane and wants to move to a new, safer location while avoiding being destroyed by meteors along her way.

The reports say that M meteors (1 ≤ M ≤ 50,000) will strike, with meteor i will striking point (Xi, Yi) (0 ≤ Xi ≤ 300; 0 ≤ Yi ≤ 300) at time Ti (0 ≤ Ti  ≤ 1,000). Each meteor destroys the point that it strikes and also the four rectilinearly adjacent lattice points.

Bessie leaves the origin at time 0 and can travel in the first quadrant and parallel to the axes at the rate of one distance unit per second to any of the (often 4) adjacent rectilinear points that are not yet destroyed by a meteor. She cannot be located on a point at any time greater than or equal to the time it is destroyed).

Determine the minimum time it takes Bessie to get to a safe place.

Input

* Line 1: A single integer: M
* Lines 2..M+1: Line i+1 contains three space-separated integers: Xi, Yi, and Ti

Output

* Line 1: The minimum time it takes Bessie to get to a safe place or -1 if it is impossible.

Sample Input

4
0 0 2
2 1 2
1 1 2
0 3 5
Sample Output

5

*/

#include <stdio.h>
#include <string.h>
int line[1000000][2],g[305][305],tag[305][305];
int main()
{
	int i,j,n,head,tail,rr,time,a,b,c;
	memset(tag,0,sizeof(tag));
	for(i=0;i<305;i++)
		for(j=0;j<305;j++)
			g[i][j]=1001;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(g[a][b]>c)
			g[a][b]=c;
		if(g[a+1][b]>c)
			g[a+1][b]=c;
		if(g[a][b+1]>c)
			g[a][b+1]=c;
		if(a&&g[a-1][b]>c)
			g[a-1][b]=c;
		if(b&&g[a][b-1]>c)
			g[a][b-1]=c;
	}
	if(g[0][0]==0)
	{
		printf("-1\n");
		return 0;
	}
	line[0][0]=line[0][1]=0;
	tag[0][0]=1;
	head=0;rr=tail=1;time=0;
	while(tail>head)
	{
		time++;
		for(i=head;i<tail;i++)
		{
			if(g[line[i][0]][line[i][1]]==1001)
				break;
			if(time<g[line[i][0]][line[i][1]+1]&&tag[line[i][0]][line[i][1]+1]==0)
			{
				line[rr][0]=line[i][0];
				line[rr++][1]=line[i][1]+1;
				tag[line[i][0]][line[i][1]+1]=1;
			}
			if(line[i][1]&&time<g[line[i][0]][line[i][1]-1]&&tag[line[i][0]][line[i][1]-1]==0)
			{
				line[rr][0]=line[i][0];
				line[rr++][1]=line[i][1]-1;
				tag[line[i][0]][line[i][1]-1]=1;
			}
			if(line[i][0]&&time<g[line[i][0]-1][line[i][1]]&&tag[line[i][0]-1][line[i][1]]==0)
			{
				line[rr][0]=line[i][0]-1;
				line[rr++][1]=line[i][1];
				tag[line[i][0]-1][line[i][1]]=1;
			}
			if(time<g[line[i][0]+1][line[i][1]]&&tag[line[i][0]+1][line[i][1]]==0)
			{
				line[rr][0]=line[i][0]+1;
				line[rr++][1]=line[i][1];
				tag[line[i][0]+1][line[i][1]]=1;
			}
		}
		if(i<tail)
			break;
		head=tail;
		tail=rr;
	}
	if(tail>head)
		printf("%d\n",time-1);
	else
		printf("-1\n");
	return 0;
}

