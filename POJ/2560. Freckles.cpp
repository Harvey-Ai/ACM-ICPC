/*
Description

In an episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad's back to form a picture of the Liberty Bell. Alas, one of the freckles turns out to be a scar, so his Ripley's engagement falls through. 
Consider Dick's back to be a plane with freckles at various (x,y) locations. Your job is to tell Richie how to connect the dots so as to minimize the amount of ink used. Richie connects the dots by drawing straight lines between pairs, possibly lifting the pen between lines. When Richie is done there must be a sequence of connected lines from any freckle to any other freckle.
Input

The first line contains 0 < n <= 100, the number of freckles on Dick's back. For each freckle, a line follows; each following line contains two real numbers indicating the (x,y) coordinates of the freckle.
Output

Your program prints a single real number to two decimal places: the minimum total length of ink lines that can connect all the freckles.
Sample Input

3
1.0 1.0
2.0 2.0
2.0 4.0
Sample Output

3.41
*/

#include <stdio.h>
#include <math.h>
struct eage
{
	int vex;
	double lowcost;
};

int main()
{
	int i,j,v,n;
	double min,temp,rel,point[101][2];
	eage closeage[101];
	while(scanf("%d",&n)!=EOF)
	{
		rel=0;
		scanf("%lf%lf",&point[0][0],&point[0][1]);
		for(i=1;i<n;i++)
		{
			scanf("%lf%lf",&point[i][0],&point[i][1]);
			closeage[i].vex=0;
			closeage[i].lowcost=sqrt((point[i][0]-point[0][0])*(point[i][0]-point[0][0])+(point[i][1]-point[0][1])*(point[i][1]-point[0][1]));
		}
		closeage[0].vex=-1;
		for(i=1;i<n;i++)
		{
			min=10000000;
			v=0;
			for(j=0;j<n;j++)
				if(closeage[j].vex!=-1&&closeage[j].lowcost<min)
				{
					v=j;
					min=closeage[j].lowcost;
				}
			rel+=min;

			closeage[v].lowcost=0;
			closeage[v].vex=-1;
			for(j=0;j<n;j++)
			{
				temp=sqrt((point[j][0]-point[v][0])*(point[j][0]-point[v][0])+(point[j][1]-point[v][1])*(point[j][1]-point[v][1]));
				if(closeage[j].vex!=-1&&temp<closeage[j].lowcost)
					closeage[j].lowcost=temp;
			}
		}
		printf("%.2lf\n",rel);
	}
	return 0;
}
