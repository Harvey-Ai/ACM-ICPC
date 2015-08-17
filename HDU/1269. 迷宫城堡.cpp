/*
Problem Description
为了训练小希的方向感，Gardon建立了一座大城堡，里面有N个房间(N<=10000)和M条通道(M<=100000)，每个通道都是单向的，就是说若称某通道连通了A房间和B房间，只说明可以通过这个通道由A房间到达B房间，但并不说明通过它可以由B房间到达A房间。Gardon需要请你写个程序确认一下是否任意两个房间都是相互连通的，即：对于任意的i和j，至少存在一条路径可以从房间i到房间j，也存在一条路径可以从房间j到房间i。
 

Input
输入包含多组数据，输入的第一行有两个数：N和M，接下来的M行每行有两个数a和b，表示了一条通道可以从A房间来到B房间。文件最后以两个0结束。
 

Output
对于输入的每组数据，如果任意两个房间都是相互连接的，输出"Yes"，否则输出"No"。
 

Sample Input
3 3
1 2
2 3
3 1
3 3
1 2
2 3
3 2
0 0
 

Sample Output
Yes
No
*/


#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
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
            dfs(graph[nodeI][i], num);

//       if (inStack[nodeI])
            low[nodeI] = low[graph[nodeI][i]] < low[nodeI] ? low[graph[nodeI][i]] : low[nodeI];
  //     else
    //       low[nodeI] = dnf[graph[nodeI][i]] < low[nodeI] ? dnf[graph[nodeI][i]] : low[nodeI];
            
    }
    
    if (low[nodeI] == dnf[nodeI])
	{
		vector<int> newRes;
		while(tarjanSt.size() > inStack[nodeI])
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

	for(int i = 0;i < num;i++)
		if (!visit[i])
		{
			dfsTime = 0;
			dfs(i, num);
            break;
		}

	return res;
}

int main()
{
	int n, m;

	while(cin >> n >> m, m || n)
	{
		vector< vector<int> > matrix;
		matrix.resize(n);
		
		for(int i = 0;i < m;i++)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
            matrix[a].push_back(b);
		}
		tarjan(matrix);

		if (res.size() == 1 && res[0].size() == n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
