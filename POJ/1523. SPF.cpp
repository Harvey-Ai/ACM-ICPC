/*
Description

Consider the two networks shown below. Assuming that data moves around these networks only between directly connected nodes on a peer-to-peer basis, a failure of a single node, 3, in the network on the left would prevent some of the still available nodes from communicating with each other. Nodes 1 and 2 could still communicate with each other as could nodes 4 and 5, but communication between any other pairs of nodes would no longer be possible. 

Node 3 is therefore a Single Point of Failure (SPF) for this network. Strictly, an SPF will be defined as any node that, if unavailable, would prevent at least one pair of available nodes from being able to communicate on what was previously a fully connected network. Note that the network on the right has no such node; there is no SPF in the network. At least two machines must fail before there are any pairs of available nodes which cannot communicate. 

Input

The input will contain the description of several networks. A network description will consist of pairs of integers, one pair per line, that identify connected nodes. Ordering of the pairs is irrelevant; 1 2 and 2 1 specify the same connection. All node numbers will range from 1 to 1000. A line containing a single zero ends the list of connected nodes. An empty network description flags the end of the input. Blank lines in the input file should be ignored.
Output

For each network in the input, you will output its number in the file, followed by a list of any SPF nodes that exist. 

The first network in the file should be identified as "Network #1", the second as "Network #2", etc. For each SPF node, output a line, formatted as shown in the examples below, that identifies the node and the number of fully connected subnets that remain when that node fails. If the network has no SPF nodes, simply output the text "No SPF nodes" instead of a list of SPF nodes.
Sample Input

1 2
5 4
3 1
3 2
3 4
3 5
0

1 2
2 3
3 4
4 5
5 1
0

1 2
2 3
3 4
4 6
6 3
2 5
5 1
0

0
Sample Output

Network #1
  SPF node 3 leaves 2 subnets

Network #2
  No SPF nodes

Network #3
  SPF node 2 leaves 2 subnets
  SPF node 3 leaves 2 subnets
*/



#include <vector>
#include <iostream>
#include <stack>
using namespace std;


vector<int> visit;
vector< vector<int> > graph;
stack<int> tarjanSt;
vector<int> inStack;
vector<int> dnf, low;
vector< vector<int> > res;
int dfsTime;
vector<int> component;

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
			dfs(graph[nodeI][i], num);
			if (dnf[nodeI] <= low[graph[nodeI][i]])
				component[nodeI] ++;
		
            low[nodeI] = low[graph[nodeI][i]] < low[nodeI] ? low[graph[nodeI][i]] : low[nodeI];
        }
		else
            low[nodeI] = dnf[graph[nodeI][i]] < low[nodeI] ? dnf[graph[nodeI][i]] : low[nodeI];
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

	component.resize(num);
	component[0] = 0;
	for(int i = 1;i < num;i++)
		component[i] = 1;
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
	int a, b;
	int icase = 1;
	while(cin >> a, a)
	{
		cin >> b;
		
		vector<vector<int> > matrix;
		matrix.resize(1000);
		a--, b--;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
		while(cin >> a, a)
		{
			cin >> b;
			a--, b--;
			matrix[a].push_back(b);
			matrix[b].push_back(a);
		}
		
		tarjan(matrix);

		int flag = 0;
		cout << "Network #" << icase++ << endl;
		for(int i = 0;i < component.size();i++)
		{
			if (component[i] > 1)
			{
				cout << "  SPF node " << i + 1 << " leaves " << component[i] << " subnets" << endl;
				flag = 1;
			}
		}
		if (!flag)
			cout << "  No SPF nodes" << endl;
	
        cout << endl;
    }

	return 0;
}
