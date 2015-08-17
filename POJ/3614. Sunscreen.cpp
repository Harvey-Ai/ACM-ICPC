/*
Description

To avoid unsightly burns while tanning, each of the C (1 ≤ C ≤ 2500) cows must cover her hide with sunscreen when they're at the beach. Cow i has a minimum and maximum SPF rating (1 ≤ minSPFi ≤ 1,000; minSPFi ≤ maxSPFi ≤ 1,000) that will work. If the SPF rating is too low, the cow suffers sunburn; if the SPF rating is too high, the cow doesn't tan at all........

The cows have a picnic basket with L (1 ≤ L ≤ 2500) bottles of sunscreen lotion, each bottle i with an SPF rating SPFi (1 ≤ SPFi ≤ 1,000). Lotion bottle i can cover coveri cows with lotion. A cow may lotion from only one bottle.

What is the maximum number of cows that can protect themselves while tanning given the available lotions?

Input

* Line 1: Two space-separated integers: C and L
* Lines 2..C+1: Line i describes cow i's lotion requires with two integers: minSPFi and maxSPFi 
* Lines C+2..C+L+1: Line i+C+1 describes a sunscreen lotion bottle i with space-separated integers: SPFi and coveri

Output

A single line with an integer that is the maximum number of cows that can be protected while tanning

Sample Input

3 2
3 10
2 5
1 5
6 2
4 1
Sample Output

2
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
struct cow
{
	int min,max;
}cc[2501];
struct bot
{
	int con,cover;
}bb[2501];
bool cmp(const cow a,const cow b)
{
	if(a.max<b.max)
		return 1;
	else
		return 0;
}
bool ccmp(const bot a,const bot b)
{
	if(a.con<b.con)
		return 1;
	else
		return 0;
}
int main()
{
	int used[2501];
	int i,j,c,l,res;
	scanf("%d%d",&c,&l);
	for(i=0;i<c;i++)
		scanf("%d%d",&cc[i].min,&cc[i].max);
	sort(&cc[0],&cc[c],cmp);

	for(i=0;i<l;i++)
		scanf("%d%d",&bb[i].con,&bb[i].cover);
	sort(&bb[0],&bb[l],ccmp);
	
	res=0;
	memset(used,0,sizeof(used));
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
		{
			if(!used[j])
				if(bb[i].con>=cc[j].min&&bb[i].con<=cc[j].max)
				{
					res++;
					bb[i].cover--;
					used[j]=1;
					if(bb[i].cover==0)
						break;
				}
		}
	printf("%d\n",res);
	return 0;
}
