#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

int graph[2001][2001];
int nodeNum;
int checked;

int visited[2005];
int dfn[2005], low[2005];
int comp[2005];
int inStack[2005];
stack<int> tarjanSt;
int compTag;
int dfsTime;

void dfs(int p)
{
    visited[p] = 1;
    dfn[p] = low[p] = dfsTime++;
    tarjanSt.push(p);
    inStack[p] = 1;

    for(int i = 0;i < nodeNum;i++)
    {
        if (graph[p][i])
        {
            if (!visited[i])
            {
                dfs(i);
                low[p] = min(low[i], low[p]);
            }
            else if (inStack[i])
                low[p] = min(low[p], dfn[i]);
        }
    }

    if (dfn[p] == low[p])
    {
        int v = tarjanSt.top();
        tarjanSt.pop();
        inStack[v] = 0;
        while(v != p)
        {
            comp[v] = compTag;
            v = tarjanSt.top();
            tarjanSt.pop();
            inStack[v] = 0;
        }
        comp[p] = compTag;
        compTag++;
    }
}

void tarjan()
{
    compTag = 1;
    dfsTime = 1;
    memset(visited, 0, sizeof(visited));
    memset(inStack, 0, sizeof(inStack));
    for(int i = 0;i < nodeNum;i++)
        if (!visited[i])
            dfs(i);

    for(int i = 0;i < nodeNum - 2;i += 2)
        if (comp[i] == comp[i + 1])
        {
            checked = false;
            break;
        }
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    memset(graph, 0, sizeof(graph));
    for(int i = 0;i < m;i++)
    {
        int a, b, c;
        char str[20];
        scanf("%d %d %d", &a, &b, &c);
        scanf("%s", str);
        
        if (strcmp(str, "AND") == 0)
        {
            if (c == 1)
            {
                graph[a * 2][a * 2 + 1] = 1;
                graph[a * 2][b * 2 + 1] = 1;
                graph[b * 2][b * 2 + 1] = 1;
                graph[b * 2][a * 2 + 1] = 1;
            }
            else
            {
                graph[a * 2 + 1][b * 2] = 1;
                graph[b * 2 + 1][a * 2] = 1;
            }
        }
        else if (strcmp(str, "OR") == 0)
        {
            if (c == 0)
            {
                graph[a * 2 + 1][a * 2] = 1;
                graph[b * 2 + 1][b * 2] = 1;
            }
            else
            {
                graph[a * 2][b * 2 + 1] = 1;
                graph[b * 2][a * 2 + 1] = 1;
            }
        }
        else
        {
            if (c == 0)
            {
                graph[a * 2][b * 2] = 1;
                graph[b * 2][a * 2] = 1;
                graph[a * 2 + 1][b * 2 + 1] = 1;
                graph[b * 2 + 1][a * 2 + 1] = 1;
            }
            else
            {
             //   cout << "fda" << endl;
                graph[a * 2][b * 2 + 1] = 1;
                graph[b * 2][a * 2 + 1] = 1;
                graph[a * 2 + 1][b * 2] = 1;
                graph[b * 2 + 1][a * 2] = 1;
            }
        }
    }
    
    nodeNum = n * 2;
    checked = 1;
    tarjan();
    
    if (checked)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
