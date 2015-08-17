/*
Problem Description
On Octorber 21st, HDU 50-year-celebration, 50-color balloons floating around the campus, it's so nice, isn't it? To celebrate this meaningful day, the ACM team of HDU hold some fuuny games. Especially, there will be a game named "crashing color balloons".

There will be a n*n matrix board on the ground, and each grid will have a color balloon in it.And the color of the ballon will be in the range of [1, 50].After the referee shouts "go!",you can begin to crash the balloons.Every time you can only choose one kind of balloon to crash, we define that the two balloons with the same color belong to the same kind.What's more, each time you can only choose a single row or column of balloon, and crash the balloons that with the color you had chosen. Of course, a lot of students are waiting to play this game, so we just give every student k times to crash the balloons.

Here comes the problem: which kind of balloon is impossible to be all crashed by a student in k times.



 

Input
There will be multiple input cases.Each test case begins with two integers n, k. n is the number of rows and columns of the balloons (1 <= n <= 100), and k is the times that ginving to each student(0 < k <= n).Follow a matrix A of n*n, where Aij denote the color of the ballon in the i row, j column.Input ends with n = k = 0.
 

Output
For each test case, print in ascending order all the colors of which are impossible to be crashed by a student in k times. If there is no choice, print "-1".
 

Sample Input
1 1
1
2 1
1 1
1 2
2 1
1 2
2 2
5 4
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
3 3
50 50 50
50 50 50
50 50 50
0 0
 

Sample Output
-1
1
2
1 2 3 4 5
-1
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

int board[105][105];
int main()
{
    int n, k;
    while(cin >> n >> k, n || k)
    {
        vector< vector<int> > graph;
        graph.resize(n);
        for(int i = 0;i < n;i++)
            graph[i].resize(n);
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                cin >> board[i][j];
            
        vector<int> res;
        for(int c = 1;c <= 50;c++)
        {
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    graph[i][j] = 0;
                
            int hasC = 0;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    if (board[i][j] == c)
                    {
                        hasC = 1;
                        graph[i][j] = 1;
                    }
                    
             if (hasC && maxMatch(graph) > k)
                 res.push_back(c);
        }
        
        if (res.size() == 0)
            cout << -1 << endl;
        else
        {
            for(int i = 0;i < res.size() - 1;i++)
                cout << res[i] << " ";
            cout << res[res.size() - 1] << endl;
        }
    }
    return 0;
}
