/*
Description

Farmer John has decided to give each of his cows a cell phone in hopes to encourage their social interaction. This, however, requires him to set up cell phone towers on his N (1 ≤ N ≤ 10,000) pastures (conveniently numbered 1..N) so they can all communicate.

Exactly N-1 pairs of pastures are adjacent, and for any two pastures A and B (1 ≤ A ≤ N; 1 ≤ B ≤ N; A ≠ B) there is a sequence of adjacent pastures such that A is the first pasture in the sequence and B is the last. Farmer John can only place cell phone towers in the pastures, and each tower has enough range to provide service to the pasture it is on and all pastures adjacent to the pasture with the cell tower.

Help him determine the minimum number of towers he must install to provide cell phone service to each pasture.

Input

* Line 1: A single integer: N
* Lines 2..N: Each line specifies a pair of adjacent pastures with two space-separated integers: A and B

Output

* Line 1: A single integer indicating the minimum number of towers to install

Sample Input

5
1 3
5 2
4 3
3 5
Sample Output

2
*/


#include <stdio.h>
#include <vector>
using namespace std;
vector <int>tree[10001];
int ff[10001],res;
void dfs(int a,int f)
{
	int i,len,flag;
	flag=0;
	len=tree[a].size();
	for(i=0;i<len;i++)
		if(tree[a][i]!=f)
		{
			dfs(tree[a][i],a);
			if(ff[tree[a][i]]==0)
				flag=1;
		}
	if(flag)
	{
		res++;
		ff[a]=1;
		ff[f]=1;
	}
}

int main()
{
	int i,a,b,n;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	res=0;
	dfs(1,0);
	if(ff[1]==0)
		res++;
	printf("%d\n",res);
	return 0;
}
