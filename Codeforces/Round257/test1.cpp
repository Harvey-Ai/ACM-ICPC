#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 5

vector< vector<int> > graph;
vector< vector<int> > cost;

int dist1[N + 1], dist2[N], dist3[N];
int graph2[N + 1][N + 1];

struct distType
{
	int dist;
	int index;
	distType(int in, int d)
	{
		index = in;
		dist = d;
	}
	friend bool operator < (const distType a, const distType b)
    {
        if (a.dist > b.dist)
            return 1;
        else
            return 0;
    }
};

void dijkstra(int src, int n)
{
	queue<distType> distQueue;
	for(int i = 0;i < graph[src].size();i++)
		distQueue.push(distType(graph[src][i], cost[src][i]));
	vector<int>dist;
	for(int i = 0;i <= n;i++)
		dist.push_back(-1);
	dist[src] = 0;

	while(!distQueue.empty())
	{
		int minDist = distQueue.front().dist;
		int minPoint = distQueue.front().index;
		distQueue.pop();
		if (dist[minPoint] != -1 && dist[minPoint] <= minDist)
			continue;
		dist[minPoint] = minDist;
		
		for(int j = 0;j < graph[minPoint].size();j++)
		{
			int newDist = dist[minPoint] + cost[minPoint][j];
			distQueue.push(distType(graph[minPoint][j], newDist));
		}
	}

	for(int i = 0;i < n;i++)
		dist1[i] = dist[i];
}

void dijkstra2(int src, int n)
{
    vector<int> dist;
    dist.resize(n + 1);
    for(int i = 0;i < n;i++)
        dist[i] = graph2[src][i];
    dist[src] = 0;
    vector<int> found;
    found.resize(n + 1);
    for(int i = 0;i < n;i++)
        found[i] = 0;
    found[src] = 1;

    for(int i = 1;i < n;i++)
    {
        int minDist = -1;
        int minPoint = -1;
        for(int j = 0;j < n;j++)
            if (dist[j] != -1 && !found[j] && (minDist == -1 || minDist > dist[j]))
            {
                minDist = dist[j];
                minPoint = j;
            }
        if (minDist == -1)
            break;
        
        for(int j = 0;j < n;j++)
            if (minPoint != j && !found[j] && graph2[minPoint][j] != -1 && (dist[j] == -1 || dist[j] > minDist + graph2[minPoint][j]))
                dist[j] = minDist + graph2[minPoint][j];
        
        found[minPoint] = 1;
    }
    
    for(int i = 0;i < n;i++)
        dist2[i] = dist[i];
}


void dijkstra3(int src, int n)
{
    priority_queue<distType> distQueue;
    for(int i = 0;i < graph[src].size();i++)
        distQueue.push(distType(graph[src][i], cost[src][i]));
  //  vector<long long>dist;
   // for(int i = 0;i <= n;i++)
    //    dist.push_back(-1);
      for(int i = 0;i < n;i++)
        dist3[i] = -1;
    dist3[src] = 0;

    while(!distQueue.empty())
    {
        long long minDist = distQueue.top().dist;
        int minPoint = distQueue.top().index;
        distQueue.pop();

        cout << minPoint << " " << minDist << endl;
        if (dist3[minPoint] == -1)
        {
            minDist = minDist - 1 <= 0 ? 1 : minDist - 1;
            dist3[minPoint] = minDist;
        }
        else
        {
            if (dist3[minPoint] > minDist)
            {
                cout << "fdafd" << endl;
                while(1);
            }
            continue;
        }
        
        for(int j = 0;j < graph[minPoint].size();j++)
        {
            long long newDist = dist3[minPoint] + cost[minPoint][j];
            distQueue.push(distType(graph[minPoint][j], newDist));
        }
    }
}   

int main()
{
    for(int i = 0;i < N + 1;i++)
        graph2[i][i] = 0;
    for(int i = 0;i < N + 1;i++)
    {
        vector<int> a;
        graph.push_back(a);
        cost.push_back(a);
    }
    int flag = 1;
    
    while(flag)
    {
        cout << "the same" << endl;
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                graph2[i][j] = -1;
        for(int i = 0;i < N;i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
        for(int i = 0;i < N;i++)
        {
            int a = rand() % N;
            int b = rand() % N;
            int c = rand() % N;
            
            if (a == b)
            {
                i--;
                continue;
            }
            if (graph2[a][b] == -1 || graph2[a][b] > c)
                graph2[a][b] = graph2[b][a] = c;
            graph[a].push_back(b);
            cost[a].push_back(c);
            graph[b].push_back(a);
            cost[b].push_back(c);
        }
     //   dijkstra(0, N);
      //  dijkstra2(0, N);
        dijkstra3(0, N);
       /* for(int j = 0;j < N;j++)
            if (dist1[j] != dist3[j] )
            {
                flag = 0;
                break;
            }*/
    }

    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            if (graph2[i][j] != -1)
                cout << i << " " << j << " " << graph2[i][j] << endl;
    cout << "=============" << endl;
    for(int i = 0;i < N;i++)
        cout << dist1[i] << " " << dist3[i] << endl;
    return 0;
}
