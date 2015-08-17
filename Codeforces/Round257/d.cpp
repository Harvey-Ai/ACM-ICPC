#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > graph;
vector< vector<int> > cost;
vector<int> trainCost;
vector<int> removeTrain;

struct distType
{
    long long dist;
    int index;

    distType (int in, long long d)
    {
        dist = d;
        index = in;
    }

    friend bool operator < (const distType a, const distType b)
    {
        if (a.dist > b.dist)
            return 1;
        else if (a.dist == b.dist)
            return a.index > b.index;
        else
            return 0;
    }
};

void dijkstra(int src, int n)
{
    vector<long long>dist;
    priority_queue<distType> distQueue;
    
    for(int i = 0;i <= n;i++)
        if (trainCost[i] > 0)
            distQueue.push(distType(i, trainCost[i]));
    distQueue.push(distType(0, 0));
    
    dist.resize(n + 1);
    for(int i = 0;i <= n;i++)
        dist[i] = -1;
    
    vector<int> visit;
    visit.resize(n + 1);
    for(int i = 0;i <= n;i++)
        visit[i] = 0;

    while(!distQueue.empty())
    {
        long long minDist = distQueue.top().dist;
        int minPoint = distQueue.top().index;
        distQueue.pop();

        if (visit[minPoint])
			continue;
		visit[minPoint] = 1;
        dist[minPoint] = minDist;
        for(int j = 0;j < graph[minPoint].size();j++)
        {
            long long newDist = dist[minPoint] + cost[minPoint][j];
            
            if (trainCost[graph[minPoint][j]] >= newDist)
                removeTrain[graph[minPoint][j]] = 1;
            
			if (dist[graph[minPoint][j]] > newDist || dist[graph[minPoint][j]] == -1)
            {
                dist[graph[minPoint][j]] = newDist;
                distQueue.push(distType(graph[minPoint][j], newDist));
            }
        }
    }
}   

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0;i <= n;i++)
    {
        vector<int> a;
        graph.push_back(a);
        cost.push_back(a);
    }
    for(int i = 0;i < m;i++)
    {
        int ui, vi, xi;
        cin >> ui >> vi >> xi;
        ui--;
        vi--;
        int updated = 0;
		/*
		for(int j = 0;j < graph[ui].size();j++)
            if (graph[ui][j] == vi)
            {
                if (cost[ui][j] > xi)   cost[ui][j] = xi;
                for(int k = 0;k < graph[vi].size();k++)
                    if (graph[vi][k] == ui)
                    {
                        if (cost[vi][k] > xi)   cost[vi][k] = xi;
                        break;
                    }
                updated = 1;
                break;
            }
		*/
        if (!updated)
        {
            graph[ui].push_back(vi);
            cost[ui].push_back(xi);
            graph[vi].push_back(ui);
            cost[vi].push_back(xi);
        }
    }

    long long res = 0;
    trainCost.resize(n + 1);
    for(int i = 0;i <= n;i++)
        trainCost[i] = -1;
    trainCost[0] = 0;
    removeTrain.resize(n + 1);
    for(int i = 0;i <= n;i++)
        removeTrain[i] = 0;
    for(int i = 0;i < k;i++)
    {
        int si, yi;
        cin >> si >> yi;
        si--;
        res += (trainCost[si] != -1);
        if (trainCost[si] == -1 || trainCost[si] > yi) 
            trainCost[si] = yi;
    }

    dijkstra(0, n);
    for(int i = 1;i < n;i++)
        if (removeTrain[i])
            res++;
    cout << res << endl;

    return 0;
}
