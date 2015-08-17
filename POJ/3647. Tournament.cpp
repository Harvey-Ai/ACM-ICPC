/*
Description

Every September, the Kingdom of Loowater holds a jousting tournament. In each of a series of event, a pair of knights attempt to knock each other from their respective horses. The winning knight is paired with another, while the loser is elimnated. This process continues until all but one knight is eliminated; this knight is declared champion.

The tournament schedule is organized so that no knight needs to compete in more than e events to be champion, for the minimum possible e given k, the number of knights. In order to construct the schedule, it may be necessary to identify several knights who compete in fewer than e events; these knights are said to be awarded a bye and are excluded from the first round of competition.

The first round of competition involves pairing as many knights as possible among those who are not awarded a bye. The competition is more interesting if the knights in each pair are as evenly matched in ability as possible. You are to determine which knights should be awarded a bye so as to make the first round as interesting as possible.

Input

Standard input consists of several test cases followed by a line containing 0. Each test case begins with an integer 1 < k ≤ 2500, the number of knights. k lines follow, each giving the name and ability of a knight. The name is a string of lower case letters not longer than 20; the ability is a real number.

The mismatch between knights with abilities a and b respectively is defined to be (a - b)2.

Output

For each test case, output the names of the knights to be given a bye such that the sum of all mismatch values for pairs of knights competing in the first round is minimized. If there are several solutions, any will do. Output an empty line between test cases.

Sample Input

3
gallahad 10
lancelot 11
mccartney 2
0
Sample Output

mccartney

*/


#include <stdio.h>
#include <algorithm>
using namespace std;
struct kk
{
	char name[23];
	double ab;
}kn[2501];
double dp[2501][2501],dis[2501],a[2501];
int tag[2501][2501],bye[2501],b[2501];
bool cmp(const kk a,const kk b)
{
	return a.ab<b.ab;
}
int main()
{
	double min;
	int i,j,k,m,n,d,temp,l;
	l=0;
	while(scanf("%d",&n),n)
	{
		if(l)
			putchar('\n');
		l=1;m=1;
		while(m<n)
			m*=2;
		m=2*n-m;
		for(i=1;i<=n;i++)
			scanf("%s%lf",kn[i].name,&kn[i].ab);
		if(m==n)
			continue;
		sort(&kn[1],&kn[n+1],cmp);
		for(i=2;i<=n;i++)
			dis[i]=(kn[i].ab-kn[i-1].ab)*(kn[i].ab-kn[i-1].ab);
		for(i=0;i<=n;i++)
			a[i]=b[i]=0;
		for(i=2;i<=m;i+=2)
		{
			for(j=i;j<=n;j++)
			{
				dp[i][j]=a[j-2]+dis[j];
				tag[i][j]=b[j-2];
			}
			min=1e20;
			for(j=i;j<=n;j++)
			{
				if(dp[i][j]<min)
				{
					min=dp[i][j];
					d=j;
				}
				a[j]=min;b[j]=d;
			}
		}
		memset(bye,0,sizeof(bye));
		min=dp[m][m];k=m;
		for(j=m+1;j<=n;j++)
			if(dp[m][j]<min)
			{
				k=j;
				min=dp[m][j];
			}
		for(i=k+1;i<=n;i++)
			bye[i]=1;
		for(i=m;i>0;i-=2)
		{
			temp=tag[i][k];
			for(j=temp+1;j<k-1;j++)
				bye[j]=1;
			k=temp;
			if(temp==0)
				break;
		}
		for(i=1;i<=n;i++)
			if(bye[i])
				printf("%s\n",kn[i].name);
	}
	return 0;
}
