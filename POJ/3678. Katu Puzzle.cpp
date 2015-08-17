/*
Description

Katu Puzzle is presented as a directed graph G(V, E) with each edge e(a, b) labeled by a boolean operator op (one of AND, OR, XOR) and an integer c (0 ≤ c ≤ 1). One Katu is solvable if one can find each vertex Vi a value Xi (0 ≤ Xi ≤ 1) such that for each edge e(a, b) labeled by op and c, the following formula holds:

 Xa op Xb = c

The calculating rules are:

AND	0	1
0	0	0
1	0	1
OR	0	1
0	0	1
1	1	1
XOR	0	1
0	0	1
1	1	0
Given a Katu Puzzle, your task is to determine whether it is solvable.

Input

The first line contains two integers N (1 ≤ N ≤ 1000) and M,(0 ≤ M ≤ 1,000,000) indicating the number of vertices and edges.
The following M lines contain three integers a (0 ≤ a < N), b(0 ≤ b < N), c and an operator op each, describing the edges.

Output

Output a line containing "YES" or "NO".

Sample Input

4 4
0 1 1 AND
1 2 1 OR
3 2 0 AND
3 0 0 XOR
Sample Output

YES
Hint

X0 = 1, X1 = 1, X2 = 0, X3 = 1.

*/


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
