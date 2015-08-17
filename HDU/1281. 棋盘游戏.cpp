/*
Problem Description
小希和Gardon在玩一个游戏：对一个N*M的棋盘，在格子里放尽量多的一些国际象棋里面的“车”，并且使得他们不能互相攻击，这当然很简单，但是Gardon限制了只有某些格子才可以放，小希还是很轻松的解决了这个问题（见下图）注意不能放车的地方不影响车的互相攻击。 
所以现在Gardon想让小希来解决一个更难的问题，在保证尽量多的“车”的前提下，棋盘里有些格子是可以避开的，也就是说，不在这些格子上放车，也可以保证尽量多的“车”被放下。但是某些格子若不放子，就无法保证放尽量多的“车”，这样的格子被称做重要点。Gardon想让小希算出有多少个这样的重要点，你能解决这个问题么？

 

Input
输入包含多组数据， 
第一行有三个数N、M、K(1<N,M<=100 1<K<=N*M)，表示了棋盘的高、宽，以及可以放“车”的格子数目。接下来的K行描述了所有格子的信息：每行两个数X和Y，表示了这个格子在棋盘中的位置。
 

Output
对输入的每组数据，按照如下格式输出： 
Board T have C important blanks for L chessmen.
 

Sample Input
3 3 4
1 2
1 3
2 1
2 2
3 3 4
1 2
1 3
2 1
3 2
 

Sample Output
Board 1 have 0 important blanks for 2 chessmen.
Board 2 have 3 important blanks for 3 chessmen.
*/

#include <iostream>
#include <vector>
using namespace std;

namespace maxMatchNS
{
    int nx, ny;
    vector<int> matchX, matchY;
    vector< vector<int> > biGraph;

    void initialize(vector< vector<int> > graph)
    {
        nx = graph.size();
        ny = graph[0].size();
        matchX.resize(nx);
        matchY.resize(ny);
        biGraph = graph;

       for(int i = 0;i < nx;i++)
            matchX[i] = -1;
       for(int i = 0;i < ny;i++)
            matchY[i] = -1;
    }
}

vector<int> yUsed;
// find augment path
int path(int xNode)
{
    for(int i = 0;i < maxMatchNS::ny;i++)
    {
        if (maxMatchNS::biGraph[xNode][i] && !yUsed[i])
        {
            yUsed[i] = 1;

            if (maxMatchNS::matchY[i] == -1 || path(maxMatchNS::matchY[i]))
            {
                maxMatchNS::matchX[xNode] = i;
                maxMatchNS::matchY[i] = xNode;
                return 1;
            }
        }
    }
    return 0;
}

int maxMatch(vector< vector<int> > graph)
{
    maxMatchNS::initialize(graph);
    yUsed.resize(maxMatchNS::ny);

    int res = 0;
    for(int i = 0;i < maxMatchNS::nx;i++)
    {
        for(int j = 0;j < maxMatchNS::ny;j++)
            yUsed[j] = 0;
        res += path(i);
    }

    return res;
}

int main()
{
    int m, n, k;
    int ncase = 1;
    while(cin >> m >> n >> k)
    {
        vector<vector<int> > graph;
        graph.resize(m);
        for(int i = 0;i < m;i++)
            graph[i].resize(n);
        
        for(int i = 0;i < k;i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
        }
        
        int matchNum = maxMatch(graph);
        vector<int> matchPoint;
        
        for(int i = 0;i < n;i++)
        {
            if (maxMatchNS::matchX[i] != -1)
            {
                matchPoint.push_back(i);
                matchPoint.push_back(maxMatchNS::matchX[i]);
            }
        }
        
        int impNode = 0;
        for(int i = 0;i < matchPoint.size();i += 2)
        {
            graph[matchPoint[i]][matchPoint[i + 1]] = 0;
            if (maxMatch(graph) < matchNum)
                impNode++;
            graph[matchPoint[i]][matchPoint[i + 1]] = 1;
        }
                
        cout << "Board " << ncase++ << " have " << impNode << " important blanks for " << matchNum << " chessmen." << endl;
    }
    return 0;
}
