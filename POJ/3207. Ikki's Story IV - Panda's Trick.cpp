/*
Description

liympanda, one of Ikki’s friend, likes playing games with Ikki. Today after minesweeping with Ikki and winning so many times, he is tired of such easy games and wants to play another game with Ikki.

liympanda has a magic circle and he puts it on a plane, there are n points on its boundary in circular border: 0, 1, 2, …, n − 1. Evil panda claims that he is connecting m pairs of points. To connect two points, liympanda either places the link entirely inside the circle or entirely outside the circle. Now liympanda tells Ikki no two links touch inside/outside the circle, except on the boundary. He wants Ikki to figure out whether this is possible…

Despaired at the minesweeping game just played, Ikki is totally at a loss, so he decides to write a program to help him.

Input

The input contains exactly one test case.

In the test case there will be a line consisting of of two integers: n and m (n ≤ 1,000, m ≤ 500). The following m lines each contain two integers ai and bi, which denote the endpoints of the ith wire. Every point will have at most one link.

Output

Output a line, either “panda is telling the truth...” or “the evil panda is lying again”.

Sample Input

4 2
0 1
3 2
Sample Output

panda is telling the truth...
*/

#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int graph[1001][1001];
int nodeNum;
int checked;

int visited[1005];
int dfn[1005], low[1005];
int comp[1005];
int inStack[1005];
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
	int m, n;
	int edge[505][2];

	scanf("%d %d", &n, &m);
	for(int i = 0;i < m;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		edge[i][0] = min(a, b);
		edge[i][1] = max(a, b);
	}

	for(int i = 0;i < m;i++)
		for(int j = i + 1;j < m;j++)
		{
			int flag1 = (edge[j][0] > edge[i][0]) && (edge[j][0] < edge[i][1]);
			int flag2 = (edge[j][1] > edge[i][0]) && (edge[j][1] < edge[i][1]);
			if (flag1 != flag2)
			{
				graph[i * 2][j * 2 + 1] = graph[j * 2 + 1][i * 2] = 1;
				graph[i * 2 + 1][j * 2] = graph[j * 2][i * 2 + 1] = 1;
			}
		}

	checked = 1;
	nodeNum = m * 2;
	tarjan();

	if (checked)
		cout << "panda is telling the truth..." << endl;
	else
		cout << "the evil panda is lying again" << endl;
	return 0;
}
