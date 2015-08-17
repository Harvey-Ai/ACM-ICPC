/*
Problem Description

This problem is very simple and well known.

It is shown as follows:

There is a tree which has n nodes, and the nodes are numbered from 1 to n, No. 1 is always the root of the tree. Given you two nodes of the tree, you should count the total number of their common ancestors.

 Input

There are mulitiple tests. For each test, the first line is an integer n(1<=n<=50000), following n lines, the i+1-th line denotes the information of the i-th node. For each line, there is an integer k(0<=k<=n-1), denoting the number of direct children of the i-th node. Then following k integers, denoting the No. of the i-th node. When k is equal to 0, denoting the i-th node is leaf node. You should note that the node can be the ancestor of itself.

The n+2-th line is an integer m (1<=m<=30,000), denoting there are m queries. Following m lines, for each line, there are two integers x and y, denoting the No. of the two nodes.

 Output

For each query, you should count the total number of their common ancestors.

 Sample Input

12
3 2 3 4
2 5 6
0
0
2 7 8
2 9 10
0
0
0
2 11 12
0
0
6
3 11
7 12
4 8
9 12
8 10
1 12
 Sample Output

1
2
1
3
2
1
*/

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> tree[50001];
int r[50001],d[100002][20];
int num;
void dfs(int node,int h)
{
	int i;
	r[node]=num;
	d[num++][0]=h;
	for(i=0;i<tree[node].size();i++)
	{
		dfs(tree[node][i],h+1);
		d[num++][0]=h;
	}
}
int main()
{
	int i,j,k,n,a,b,temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			tree[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&a);
				a--;
				if(a!=i)
					tree[i].push_back(a);
			}
		}
		num=0;
		dfs(0,1);
		temp=2;
		for(i=1;temp<=num;i++)
		{
			for(j=0;j+temp-1<num;j++)
			{
				d[j][i]=d[j][i-1];
				if(d[j][i]>d[j+temp/2][i-1])
					d[j][i]=d[j+temp/2][i-1];
			}
			temp*=2;
		}
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			a=r[a];b=r[b];
			if(a>b)
			{
				temp=a;
				a=b;
				b=temp;
			}
			temp=1;
			for(i=0;;i++)
			{
				if(a+temp>=b-temp+1)
					break;
				temp*=2;
			}
			if(d[a][i]<d[b-temp+1][i])
				printf("%d\n",d[a][i]);
			else
				printf("%d\n",d[b-temp+1][i]);
		}
	}
	return 0;
}

