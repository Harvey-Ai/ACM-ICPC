/*
Description
你正在参与一项输油管道的项目，此项目的目标是架设一组输油管道系统，使得从源头到目的地输送的石油流量最大。如果直接从源头架设管道到目的地，一旦管道有损坏，将无法输送石油。为了增强管道系统抵抗破坏的能力，你决定设置 N - 2 个中间节点，从而把管道分散开来。
源头和目的地可以视为特殊的节点，他们的编号分别为 1 和 N，而其他的中间节点的标号为 2 到 N - 1。每条管道有特定的流量限制 c，石油可以以不超过 c 的速率在管道内流动。两个节点之间至多由一条管道连接，也就是说这两个节点之间单位时间内流动的石油不超过 c。
现在你们已经选定了 N 个节点，并且制定好了建设计划。你想知道，每当一条管道建造完成，从节点 1 到节点 N 最大流量能够增加多少。

Input
输入包括多组数据。第一行是整数 T，表示有多少组测试数据。每组测试数据的第一行包括两个整数 N 和 M，表示节点的数量和将要建造的管道数量。接下来 M 行按建造顺序描述每条管道，每行包括三个整数 i, j, c，表示要在节点 i 和 j 之间建造一条容量为 c 的管道。

1 ≤ T ≤ 100 
0 ≤ M ≤ N(N - 1)/2 
1 ≤ v ≠ u ≤ N 
1 ≤ c ≤ 100 
小数据：2 ≤ N ≤ 20 
大数据：2 ≤ N ≤ 200
Output
对于每组测试数据，先输出一行“Case #c:”，其中 c 为测试数据编号（从 1 开始）。紧接着按建造顺序输出使得总流量增加的管道编号和相应的增加量，以一个空格隔开。
Sample Input
3
2 1
1 2 3
4 5
1 2 9
2 3 7
3 4 6
2 4 4
1 3 1
5 7
1 2 1
1 3 2
1 4 3
2 5 4
3 2 3
4 3 3
3 5 2
Sample Output
Case #1:
1 3
Case #2:
3 6
4 3
5 1
Case #3:
4 1
5 2
6 1
7 2

*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 205
#define inf 10000000
/*
int nodeCap[205];
int graph[205][205];

void dfs(int node)
{
	if (node == 1)	return;
	int cap = 0;
	for(int i = 0;i < 205;i++)
		if (graph[i][node])
		{
			if (nodeCap[i] == -1)
				dfs(i);
			cap += nodeCap[i] > graph[i][node] ? graph[i][node] : nodeCap[i];
		}
	nodeCap[node] = cap;
}
*/
int  flow[N][N], up[N][N];
int pv[N], que[N], d[N];
void maxflow(int n, int src, int sink) {
	// BFS, O(E * maxflow)
	int p, q, t, i, j;
	do{
		for (i = 0; i < n; pv[i++] = 0) ;
		pv[t = src] = src + 1; d[t] = inf;
		for (p=q=0; p<=q && !pv[sink]; t=que[p++])
			for (i=0; i<n; i++)
			{
				if(!pv[i]&&up[t][i]&&(j=up[t][i]-flow[t][i])>0)
					pv[que[q++]=i]=+t+1, d[i]=d[t]<j?d[t]:j;
				else if (!pv[i]&&up[i][t]&&(j=flow[i][t])>0)
					pv[que[q++]=i]=-t-1, d[i]=d[t]<j?d[t]:j;
			}
		for (i=sink; pv[i] && i!=src; )
		{             
			if(pv[i]>0)flow[pv[i]-1][i]+=d[sink],i=pv[i]-1;
			else flow[i][-pv[i]-1]-=d[sink], i=-pv[i]-1;
		}
	}while (pv[sink]); 
}
/*
int limitflow(int n, int src, int sink)
{
	int i, j, sk, ks;
	if (src == sink) return inf;
	up[n][n+1] = up[n+1][n] = up[n][n] = up[n+1][n+1] = 0;
	for (i = 0; i < n; i++)
	{
		up[n][i] = up[i][n] = up[n+1][i] = up[i][n+1] = 0;
		for (j = 0; j < n; j++)
		{
			up[i][j] -= low[i][j];
			up[n][i] += low[j][i];
			up[i][n+1] += low[i][j];
		}
	}
	sk = up[src][sink];
	ks = up[sink][src];
	up[src][sink] = up[sink][src] = inf;
	maxflow(n+2, n, n+1);
	for (i = 0; i < n; i++)
		if (flow[n][i] < up[n][i]) return -1;
	flow[src][sink] = flow[sink][src] = 0;
	up[src][sink] = sk; up[sink][src] = ks; 
	// ! min: src <- sink;   max: src -> sink;
	maxflow(n, sink, src);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			up[i][j] += low[i][j]; 
			flow[i][j] += low[i][j]; 
		}
	for (j = i = 0; i < n; j += flow[src][i++]) ;
	return j; 
}
*/
/*
int cal(int desNode)
{
	dfs(desNode);
}
*/

int main()
{
	int lastCap;
	int ncase;
	int m, n;
	scanf("%d", &ncase);
	for(int icase = 1;icase <= ncase;icase++)
	{
		lastCap = 0;
		scanf("%d %d", &n, &m);
		memset(up, 0, sizeof(up));
		memset(flow, 0, sizeof(flow));
		printf("Case #%d:\n", icase);

		for(int i = 0;i < m;i++)
		{
			int node1, node2, cap;
			scanf("%d %d %d", &node1, &node2, &cap);
			up[node1][node2] = up[node2][node1] = cap;
			int res = 0;
			maxflow(n + 1, 1, n);
			for(int j = 1;j < n;j++)
				res += flow[j][n];
			if (res > lastCap)
			{
				printf("%d %d\n", i + 1, res - lastCap);
				lastCap = res;
			}
		}
	}
	return 0;
}
