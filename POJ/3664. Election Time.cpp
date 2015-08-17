/*
Description

The cows are having their first election after overthrowing the tyrannical Farmer John, and Bessie is one of N cows (1 ≤ N ≤ 50,000) running for President. Before the election actually happens, however, Bessie wants to determine who has the best chance of winning.

The election consists of two rounds. In the first round, the K cows (1 ≤ K ≤ N) cows with the most votes advance to the second round. In the second round, the cow with the most votes becomes President.

Given that cow i expects to get Ai votes (1 ≤ Ai ≤ 1,000,000,000) in the first round and Bi votes (1 ≤ Bi ≤ 1,000,000,000) in the second round (if he or she makes it), determine which cow is expected to win the election. Happily for you, no vote count appears twice in the Ai list; likewise, no vote count appears twice in the Bi list.

Input

* Line 1: Two space-separated integers: N and K 
* Lines 2..N+1: Line i+1 contains two space-separated integers: Ai and Bi

Output

* Line 1: The index of the cow that is expected to win the election.

Sample Input

5 3
3 10
9 2
5 6
8 4
6 5
Sample Output

5
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
struct dd
{
	int a,b,id;
}arr[50001];
bool cmp(const dd a,const dd b)
{
	if(a.a>b.a)
		return 1;
	else
		return 0;
}
int main()
{
	int i,n,k,max,id;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&arr[i].a,&arr[i].b);
			arr[i].id=i;
		}
		sort(&arr[0],&arr[n],cmp);
		id=0;max=0;
		for(i=0;i<k;i++)
			if(arr[i].b>max)
			{
				id=arr[i].id;
				max=arr[i].b;
			}
		printf("%d\n",id+1);
	}
	return 0;
}
