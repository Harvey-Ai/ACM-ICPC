/*
Description

Farmer John had just acquired several new farms! He wants to connect the farms with roads so that he can travel from any farm to any other farm via a sequence of roads; roads already connect some of the farms.

Each of the N (1 ≤ N ≤ 1,000) farms (conveniently numbered 1..N) is represented by a position (Xi, Yi) on the plane (0 ≤ Xi ≤ 1,000,000; 0 ≤ Yi ≤ 1,000,000). Given the preexisting M roads (1 ≤ M ≤ 1,000) as pairs of connected farms, help Farmer John determine the smallest length of additional roads he must build to connect all his farms.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Two space-separated integers: Xi and Yi 
* Lines N+2..N+M+2: Two space-separated integers: i and j, indicating that there is already a road connecting the farm i and farm j.

Output

* Line 1: Smallest length of additional roads required to connect all farms, printed without rounding to two decimal places. Be sure to calculate distances as 64-bit floating point numbers.

Sample Input

4 1
1 1
3 1
2 3
4 3
1 4
Sample Output

4.00
*/

#include <stdio.h>
#include <math.h>
double g[1001][1001],closet[1001],p[1001][2];
int main()
{
	double rel,min,temp;
	int i,j,v,a,b,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&p[i][0],&p[i][1]);
	for(i=0;i<n;i++)
	{
		g[i][i]=0;
		for(j=0;j<i;j++)
		{
			temp=(p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
			g[j][i]=g[i][j]=sqrt(temp);
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		g[a-1][b-1]=g[b-1][a-1]=0;
	}
	closet[0]=-1;
	for(i=1;i<n;i++)
		closet[i]=g[0][i];
	rel=0;
	for(i=1;i<n;i++)
	{
		min=-1;
		for(j=0;j<n;j++)
			if(closet[j]!=-1&&(closet[j]<min||min==-1))
			{
				v=j;
				min=closet[j];
			}
		rel+=min;
		closet[v]=-1;
		for(j=0;j<n;j++)
			if(closet[j]!=-1&&g[j][v]<closet[j])
				closet[j]=g[j][v];
	}
	printf("%.2lf\n",rel);
	return 0;
}
