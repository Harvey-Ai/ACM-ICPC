/*
Description

Building and maintaining roads among communities in the far North is an expensive business. With this in mind, the roads are build such that there is only one route from a village to a village that does not pass through some other village twice. 
Given is an area in the far North comprising a number of villages and roads among them such that any village can be reached by road from any other village. Your job is to find the road distance between the two most remote villages in the area. 

The area has up to 10,000 villages connected by road segments. The villages are numbered from 1. 
Input

Input to the problem is a sequence of lines, each containing three positive integers: the number of a village, the number of a different village, and the length of the road segment connecting the villages in kilometers. All road segments are two-way.
Output

You are to output a single integer: the road distance between the two most remote villages in the area.
Sample Input

5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
Sample Output

22
*/


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<vector<int> > graph;
vector<vector<int> > cost;
int endP;
int maxDist;
int visited[500005];

int dfs(int p, int dist)
{
    if (visited[p])
        return 0;
    visited[p] = 1;
    if (dist > maxDist)
    {
        maxDist = dist;
        endP = p;
    }
    for(int i = 0;i < graph[p].size();i++)
        dfs(graph[p][i], dist + cost[p][i]);
}

int main()
{
    graph.resize(10005);
    cost.resize(10005);

    int a, b, w;
    int k = 0;
    while(scanf("%d %d %d", &a, &b, &w) != EOF)
    {
   //     k++;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        cost[a - 1].push_back(w);
        cost[b - 1].push_back(w);
  //      if (k >= 5)
    //        break;
    }

    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(0, 0);

    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(endP, 0);
    cout << maxDist << endl;

    return 0;
}
