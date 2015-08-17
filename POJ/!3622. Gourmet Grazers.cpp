/*
Description

Like so many others, the cows have developed very haughty tastes and will no longer graze on just any grass. Instead, Farmer John must purchase gourmet organic grass at the Green Grass Grocers store for each of his N (1 ≤ N ≤ 100,000) cows.

Each cow i demands grass of price at least Ai (1 ≤ Ai ≤ 1,000,000,000) and with a greenness score at least Bi (1 ≤ Bi ≤ 1,000,000,000). The GGG store has M (1 ≤ M ≤ 100,000) different types of grass available, each with a price Ci (1 ≤ Ci ≤ 1,000,000,000) and a greenness score of Di (1 ≤ Di ≤ 1,000,000,000). Of course, no cow would sacrifice her individuality, so no two cows can have the same kind of grass.

Help Farmer John satisfy the cows' expensive gourmet tastes while spending as little money as is necessary.

Input

* Line 1: Two space-separated integers: N and M.
* Lines 2..N+1: Line i+1 contains two space-separated integers: Ai and Bi 
* Lines N+2..N+M+1: Line i+N+1 contains two space-separated integers: Ci and Di

Output

* Line 1: A single integer which is the minimum cost to satisfy all the cows. If that is not possible, output -1.

Sample Input

4 7
1 1
2 3
1 4
4 2
3 2
2 1
4 3
5 2
5 4
2 6
4 4
Sample Output

12

*/


#include <stdio.h>
#include <algorithm>
using namespace std;
struct cow
{
	int price,green;
}demand[100001];
struct store
{
	int price,green;
}have[100001];
bool cmp(const cow a,const cow b)
{
	if(a.price<b.price)
		return 1;
	if(a.price==b.price)
	{
		if(a.green<b.green)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
bool ccmp(const store a,const store b)
{
	if(a.price<b.price)
		return 1;
	if(a.price==b.price)
	{
		if(a.green<b.green)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int main()
{
	int i,j,k,n,m;
	double rel;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d%d",&demand[i].price,&demand[i].green);
	sort(&demand[0],&demand[n],cmp);
	for(i=0;i<m;i++)
		scanf("%d%d",&have[i].price,&have[i].green);
	sort(&have[0],&have[m],ccmp);
	rel=0;j=0;
	for(i=0;i<n;i++)
	{
		for(;j<m;j++)
			if(demand[i].price<=have[j].price)
				break;
		for(k=j;k<m;k++)
			if(demand[i].green<=have[k].green)
				break;
		if(k<m)
		{
			rel+=have[k].price;
			have[k].price=-1;
		}
		else
			break;
	}
	if(i<n)
		printf("-1\n");
	else
		printf("%.0lf\n",rel);
	return 0;
}
