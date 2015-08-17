/*
Description

Ratish is a young man who always dreams of being a hero. One day his friend Luffy was caught by Pirate Arlong. Ratish set off at once to Arlong's island. When he got there, he found the secret place where his friend was kept, but he could not go straight in. He saw a large door in front of him and two locks in the door. Beside the large door, he found a strange rock, on which there were some odd words. The sentences were encrypted. But that was easy for Ratish, an amateur cryptographer. After decrypting all the sentences, Ratish knew the following facts: 

Behind the large door, there is a nesting prison, which consists of M floors. Each floor except the deepest one has a door leading to the next floor, and there are two locks in each of these doors. Ratish can pass through a door if he opens either of the two locks in it. There are 2N different types of locks in all. The same type of locks may appear in different doors, and a door may have two locks of the same type. There is only one key that can unlock one type of lock, so there are 2N keys for all the 2N types of locks. These 2N keys were divided into N pairs, and once one key in a pair is used, the other key will disappear and never show up again. 

Later, Ratish found N pairs of keys under the rock and a piece of paper recording exactly what kinds of locks are in the M doors. But Ratish doesn't know which floor Luffy is held, so he has to open as many doors as possible. Can you help him to choose N keys to open the maximum number of doors?
Input

There are several test cases. Every test case starts with a line containing two positive integers N (1 <= N <= 210) and M (1 <= M <= 211) separated by a space, the first integer represents the number of types of keys and the second integer represents the number of doors. The 2N keys are numbered 0, 1, 2, ..., 2N - 1. Each of the following N lines contains two different integers, which are the numbers of two keys in a pair. After that, each of the following M lines contains two integers, which are the numbers of two keys corresponding to the two locks in a door. You should note that the doors are given in the same order that Ratish will meet. A test case with N = M = 0 ends the input, and should not be processed.
Output

For each test case, output one line containing an integer, which is the maximum number of doors Ratish can open.
Sample Input

3 6
0 3
1 2
4 5
0 1
0 2
4 1
4 2
3 5
2 2
0 0
Sample Output

4
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[4096];
int nodeNum;
int checked;

int visited[4096];
int dfn[4096], low[4096];
int comp[4096];
int inStack[4096];
stack<int> tarjanSt;
int compTag;
int dfsTime;


void dfs(int p)
{
    visited[p] = 1;
    dfn[p] = low[p] = dfsTime++;
    tarjanSt.push(p);
    inStack[p] = 1;

    for(int i = 0;i < graph[p].size();i++)
    {
        int c = graph[p][i];
        if (!visited[c])
        {
            dfs(c);
            low[p] = min(low[c], low[p]);
        }
        else if (inStack[c])
            low[p] = min(low[p], dfn[c]);
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
    {
        if (comp[i] == comp[i + 1])
        {
            checked = false;
            break;
        }
    }
}

int edge[2048][2];
vector<int> temp[4096];
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m), n || m)
    {
        nodeNum = n * 4;
        for(int i = 0;i < nodeNum;i++)
            temp[i].clear();
        for(int i = 0;i < n;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            temp[b * 2 + 1].push_back(a * 2);
            temp[a * 2 + 1].push_back(b * 2);
        }
        
        for(int i = 0;i < m;i++)
            scanf("%d %d", &edge[i][0], &edge[i][1]); 
       
        int h = m - 1, l = 0;
        int res = -1;
        while(h >= l)
        {
            int mid = (h + l) / 2;
            for(int i = 0;i < nodeNum;i++)
                graph[i] = temp[i];
            
            for(int i = 0;i <= mid;i++)
            {
                graph[edge[i][0] * 2].push_back(edge[i][1] * 2 + 1);
                graph[edge[i][1] * 2].push_back(edge[i][0] * 2 + 1);
            }
            
            checked = true;
            tarjan();
            if (checked)
            {
                res = max(mid, res);
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        
        cout << res + 1 << endl;
    }
    return 0;
}
