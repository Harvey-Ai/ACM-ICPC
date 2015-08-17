/*
Description

Farmer John wants the cows to prepare for the county jumping competition, so Bessie and the gang are practicing jumping over hurdles. They are getting tired, though, so they want to be able to use as little energy as possible to jump over the hurdles.

Obviously, it is not very difficult for a cow to jump over several very short hurdles, but one tall hurdle can be very stressful. Thus, the cows are only concerned about the height of the tallest hurdle they have to jump over.

The cows' practice room has N (1 ≤ N ≤ 300) stations, conveniently labeled 1..N. A set of M (1 ≤ M ≤ 25,000) one-way paths connects pairs of stations; the paths are also conveniently labeled 1..M. Path i travels from station Si to station Ei and contains exactly one hurdle of height Hi (1 ≤ Hi ≤ 1,000,000). Cows must jump hurdles in any path they traverse.

The cows have T (1 ≤ T ≤ 40,000) tasks to complete. Task i comprises two distinct numbers, Ai and Bi (1 ≤ Ai ≤ N; 1 ≤ Bi ≤ N), which connote that a cow has to travel from station Ai to station Bi (by traversing over one or more paths over some route). The cows want to take a path the minimizes the height of the tallest hurdle they jump over when traveling from Ai to Bi . Your job is to write a program that determines the path whose tallest hurdle is smallest and report that height.
　

Input

* Line 1: Three space-separated integers: N, M, and T
* Lines 2..M+1: Line i+1 contains three space-separated integers: Si , Ei , and Hi 
* Lines M+2..M+T+1: Line i+M+1 contains two space-separated integers that describe task i: Ai and Bi

Output

* Lines 1..T: Line i contains the result for task i and tells the smallest possible maximum height necessary to travel between the stations. Output -1 if it is impossible to travel between the two stations.

Sample Input

5 6 3
1 2 12
3 2 8
1 3 5
2 5 3
3 4 4
2 4 8
3 4
1 2
5 1
Sample Output

4
8
-1

*/


#include <stdio.h>
#define max 10000010
int g[301][301];
int main()
{
	int i,j,k,n,m,t,temp,a,b,c;
	for(i=0;i<301;i++)
		for(j=0;j<301;j++)
			g[i][j]=max;
	scanf("%d%d%d",&n,&m,&t);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		g[a][b]=c;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(g[i][k]!=max&&g[k][j]!=max)
				{
					if(g[i][k]>g[k][j])
						temp=g[i][k];
					else
						temp=g[k][j];
					if(temp<g[i][j])
						g[i][j]=temp;
				}
			}
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		if(g[a][b]!=max)
			printf("%d\n",g[a][b]);
		else
			printf("-1\n");
	}
	return 0;
}
