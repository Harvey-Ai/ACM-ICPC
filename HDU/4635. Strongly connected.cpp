/*
Problem Description
Give a simple directed graph with N nodes and M edges. Please tell me the maximum number of the edges you can add that the graph is still a simple directed graph. Also, after you add these edges, this graph must NOT be strongly connected.
A simple directed graph is a directed graph having no multiple edges or graph loops.
A strongly connected digraph is a directed graph in which it is possible to reach any node starting from any other node by traversing edges in the direction(s) in which they point. 
 

Input
The first line of date is an integer T, which is the number of the text cases.
Then T cases follow, each case starts of two numbers N and M, 1<=N<=100000, 1<=M<=100000, representing the number of nodes and the number of edges, then M lines follow. Each line contains two integers x and y, means that there is a edge from x to y.
 

Output
For each case, you should output the maximum number of the edges you can add.
If the original graph is strongly connected, just output -1.
 

Sample Input
3
3 3
1 2
2 3
3 1
3 3
1 2
2 3
1 3
6 6
1 2
2 3
3 1
4 5
5 6
6 4
 

Sample Output
Case 1: -1
Case 2: 1
Case 3: 15

*/


#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;

vector<int> visit;
vector< vector<int> > graph;
stack<int> tarjanSt;
vector<int> inStack;
vector<int> dnf, low;
vector< vector<int> > res;
int dfsTime;

void dfs(int nodeI, int num)
{
    if (visit[nodeI])
        return;

    visit[nodeI] = 1;
    dnf[nodeI] = dfsTime++;
    low[nodeI] = dnf[nodeI];
    tarjanSt.push(nodeI);
    inStack[nodeI] = tarjanSt.size() - 1;

    for(int i = 0;i < graph[nodeI].size();i++)
    {
        if (!visit[graph[nodeI][i]])
        {
            assert(inStack[graph[nodeI][i]] == -1);
            dfs(graph[nodeI][i], num);
            low[nodeI] = min(low[nodeI], low[graph[nodeI][i]]);
        }
		else if (inStack[graph[nodeI][i]] != -1)
            low[nodeI] = min(low[nodeI], dnf[graph[nodeI][i]]);
    }
    
    if (low[nodeI] == dnf[nodeI])
    {
        vector<int> newRes;
        int k = inStack[nodeI];
        while(tarjanSt.size() > k)
        {
            newRes.push_back(tarjanSt.top());
            inStack[tarjanSt.top()] = -1;
            tarjanSt.pop();
        }
        res.push_back(newRes);
    }
}

vector<vector<int> > &tarjan(vector< vector<int> > &matrix)
{
    int num = matrix.size();
    graph = matrix;
    
    visit.resize(num);
    for(int i = 0;i < num;i++)
        visit[i] = 0;

    inStack.resize(num);
    for(int i = 0;i < num;i++)
        inStack[i] = -1;
    dnf.resize(num);
    low.resize(num);
    res.clear();
    while(!tarjanSt.empty())
        tarjanSt.pop();

    for(int i = 0;i < num;i++)
        if (!visit[i])
        {
        //    dfsTime = 0;
            dfs(i, num);
        }
    return res;
}

int main()
{
    int ncase;
    cin >> ncase;
    int m, n;
    for(int icase = 1;icase <= ncase;icase++)
    {
        vector<vector<int> > matrix;
        cin >> n >> m;
        
        matrix.resize(n);
        for(int i = 0;i < m;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            matrix[a].push_back(b);
        } 
        dfsTime = 0;
        tarjan(matrix);
     
        vector<int> chunkIndex;
        chunkIndex.resize(n);   
        for(int i = 0;i < res.size();i++)
            for(int j = 0;j < res[i].size();j++)
                chunkIndex[res[i][j]] = i;
            
        vector<int> in, out;
        in.resize(res.size());
        out.resize(res.size());
           
        for(int i = 0;i < n;i++)
            for(int j = 0;j < matrix[i].size();j++)
            {
                if (chunkIndex[i] != chunkIndex[matrix[i][j]])
                {
                    out[chunkIndex[i]]++;
                    in[chunkIndex[matrix[i][j]]]++;
                }
            }
        
        __int64 abstractEdges =1000000000;
        for(int i = 0;i < res.size();i++)
        {
            if ((in[i] == 0 || out[i] == 0) && abstractEdges > (__int64)res[i].size() * (n - res[i].size()))
                abstractEdges = (__int64)res[i].size() * (n - res[i].size());
        }
        
        __int64 total = (__int64)n * (n - 1);
        total -= (__int64)m;
        if (res.size() == 1)
            cout << "Case " << icase << ": -1" << endl;
        else
            cout << "Case " << icase << ": " << total - abstractEdges << endl;
    }
    return 0;
}
