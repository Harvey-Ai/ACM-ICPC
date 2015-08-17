#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 201, M = 10100;
const double INF = 10000000000;

struct EDGE
{
	int u, v, next;
	double cap;
}edge[M];

int map[M][2], n, m, dis[N], cur[N], gap[N], pre[N];
int num, head[N], d[N], step, path[N], s, t;
bool used[N];

void init()
{
	memset(d, 0, sizeof(d));
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &map[i][0], &map[i][1]);
		d[map[i][0]]++;
		d[map[i][1]]++;
	}
}

void add(int u, int v, double w)
{
	edge[num].u = u;
	edge[num].v = v;
	edge[num].cap = w;
	edge[num].next = head[u];
	head[u] = num++;
}

double SAP(int s, int t)
{
	memset(gap,0,sizeof(gap));
	memset(dis,0,sizeof(dis));
	int i;
	for(int i = 1;i <= t;i++)
		cur[i] = head[i];
	int top = s;
	gap[s] = t;
	double maxflow = 0,flow = INF;
	while(dis[s] < t)
	{
		for(i = head[top];i != -1;i = edge[i].next)
		{
			if(edge[i].cap > 0&& dis[top] == dis[edge[i].v] + 1)
				break;
		}
		if(i != -1)
		{
			cur[top] = i;
			int v = edge[i].v;
			if(edge[i].cap < flow)
				flow = edge[i].cap;
			top = v;
			pre[v] = i;
			if(top == t)
			{
				maxflow += flow;
				while(top != s)
				{
					edge[pre[top]].cap -= flow;
					edge[pre[top]^1].cap += flow;
					top = edge[pre[top]^1].v;
				}
				flow = INF;
			}
		}
		else
		{
			if(--gap[dis[top]] == 0)
				break;
			dis[top] = t;
			cur[top] = head[top];
			for(int j = head[top];j != -1;j = edge[j].next)
			{
				if(edge[j].cap > 0&& dis[edge[j].v] + 1 < dis[top])
				{
					dis[top] = dis[edge[j].v] + 1;
					cur[top] = j;
				}
			}
			gap[dis[top]]++;
			if(top != s)
			{
				top = edge[pre[top]^1].v;
			}
		}
	}
	return maxflow;
}

double makegraph(double g)
{
	num = 0;
	memset(head, -1, sizeof(head));
	for(int i=1; i<=n; i++)
	{
		add(s, i, m);
		add(i, s, 0);
		add(i, t, m+2*g-d[i]);
		add(t, i, 0);
	}
	for(int i=1; i<=m; i++)
	{
		add(map[i][0], map[i][1] , 1);
		add(map[i][1], map[i][0] , 0);

		add(map[i][1], map[i][0] , 1);
		add(map[i][0], map[i][1] , 0);
	}
	return n*m - SAP(s, t);
}

void dfs(int u)
{
	used[u] = 1;
	if(u>=1 && u<=n)
		path[++step] = u;
	int v;
	for(int i=head[u]; i!=-1; i=edge[i].next)
	{
		v = edge[i].v;
		if(edge[i].cap >0 && !used[v])
			dfs(v);
	}
}

void solve()
{
	if(m == 0)
	{
		printf("1\n1\n");
		return ;
	}
	double left=0, right=m, mid, esp = 1.0/n/n/2;
	double now;
	s = n+1;
	t = n+2;
	while(right-left > esp)
	{
		mid = (left+right)/2;
		now = makegraph(mid);
		if(now > 0)
			left = mid;
		else right = mid;
	}
	makegraph(left);
	memset(used, 0, sizeof(used));
	step = 0;
	dfs(s);
	printf("%d\n", step);
	sort(path+1, path+step+1);
	for(int i=1; i<=step; i++)
		printf("%d\n", path[i]);
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init();
		solve();
	}
	return 0;
}
