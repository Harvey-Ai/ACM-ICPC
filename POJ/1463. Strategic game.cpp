/*
Description

Bob enjoys playing computer games, especially strategic games, but sometimes he cannot find the solution fast enough and then he is very sad. Now he has the following problem. He must defend a medieval city, the roads of which form a tree. He has to put the minimum number of soldiers on the nodes so that they can observe all the edges. Can you help him? 

Your program should find the minimum number of soldiers that Bob has to put for a given tree. 

For example for the tree: 


the solution is one soldier ( at the node 1).
Input

The input contains several data sets in text format. Each data set represents a tree with the following description: 

the number of nodes 
the description of each node in the following format 
node_identifier:(number_of_roads) node_identifier1 node_identifier2 ... node_identifiernumber_of_roads 
or 
node_identifier:(0) 

The node identifiers are integer numbers between 0 and n-1, for n nodes (0 < n <= 1500);the number_of_roads in each line of input will no more than 10. Every edge appears only once in the input data.
Output

The output should be printed on the standard output. For each given input data set, print one integer number in a single line that gives the result (the minimum number of soldiers). An example is given in the following:
Sample Input

4
0:(1) 1
1:(2) 2 3
2:(0)
3:(0)
5
3:(3) 1 4 2
1:(1) 0
2:(0)
0:(0)
4:(0)
Sample Output

1
2

*/


#include <stdio.h>
#include <vector>
using namespace std;
int res;
int tag[1505];
vector <int>tree[1505];
void dfs(int p,int f)
{
	int i,len;
	len=tree[p].size();
	for(i=0;i<len;i++)
		if(tree[p][i]!=f)
			dfs(tree[p][i],p);
	if(tag[p]==0&&tag[f]==0)
		if(f!=-1)
		{
			res++;
			tag[f]=1;
		}
}	
int main()
{
	int i,j,a,b,m,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			tree[i].clear();
		memset(tag,0,sizeof(tag));
		for(i=0;i<n;i++)
		{
			scanf("%d:(%d)",&a,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&b);
				tree[a].push_back(b);
				tree[b].push_back(a);
			}
		}
		res=0;
		dfs(0,-1);
		printf("%d\n",res);
	}
	return 0;
}
