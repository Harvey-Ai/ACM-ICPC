#include <queue>
#include <cmath>
using namespace std;
#define N 100005

struct edge
{
	vector < pair<int,__int64> > adj;
}ee[N];


priority_queue< pair<__int64, int>, vector< pair<__int64, int > >, greater< pair<__int64, int > > > q;

void addE(int a, int b, __int64 w)
{
	ee[a].adj.push_back(make_pair<int, __int64>(b, w));
	ee[b].adj.push_back(make_pair<int, __int64>(a, w));
}

int main()
{
	__int64 dist[N];
	int path[N], res[N];
	int set[N];
	int m, n;
	int i;
	int a, b;
	__int64 w;
	int temp;
	while(scanf("%d %d", &m, &n) != EOF)
	{
	for(i = 0;i < n;i++)
	{
		scanf("%d %d %I64d", &a, &b, &w);
		if (a == b)
			continue;
		addE(a, b ,w);
	}

	memset(set, 0, sizeof(set));
	set[1] = 1;
	
	for(i = 0;i <= m;i++)
		dist[i] = -1;
	dist[1] = 0;

	for(i = 0;i <= m;i++)
		path[i] = -1;

	for(i = 0;i < ee[1].adj.size();i++)
	{
		dist[ee[1].adj[i].first] = ee[1].adj[i].second;
		q.push(make_pair(ee[1].adj[i].second, ee[1].adj[i].first));
		path[ee[1].adj[i].first] = 1;
	}

	while(!q.empty())
	{
		pair<__int64, int> top = q.top();
		q.pop();
		while(set[top.second] && !q.empty())
		{
			top = q.top();
			q.pop();
		}

	//	printf("%d\n", top.first);
		if (set[top.second])
			break;
		set[top.second] = 1;

		for(i = 0;i < ee[top.second].adj.size();i++)
			if (!set[ee[top.second].adj[i].first] && 
				(dist[ee[top.second].adj[i].first] == -1 || 
				 dist[ee[top.second].adj[i].first] > ee[top.second].adj[i].second + dist[top.second]))
			{
				dist[ee[top.second].adj[i].first] = ee[top.second].adj[i].second + dist[top.second];
				q.push(make_pair(dist[ee[top.second].adj[i].first], ee[top.second].adj[i].first));
				path[ee[top.second].adj[i].first] = top.second;
			//	printf("%d %d\n", ee[top.first].adj[i].second, top.second);
			}
	}

	if (path[m] != -1)
	{
		temp = m;
		i = 0;
		while(path[temp] != -1)
		{
			res[i++] = temp;
			temp = path[temp];
		}
		printf("%d", 1);

		i--;
		while(i >= 0)
			printf(" %d", res[i--]);
		putchar('\n');
	}
	else
		printf("-1\n");
	}
	return 0;
}
