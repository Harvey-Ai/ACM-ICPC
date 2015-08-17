/*
Problem Description
As we all know, machine scheduling is a very classical problem in computer science and has been studied for a very long history. Scheduling problems differ widely in the nature of the constraints that must be satisfied and the type of schedule desired. Here we consider a 2-machine scheduling problem.

There are two machines A and B. Machine A has n kinds of working modes, which is called mode_0, mode_1, …, mode_n-1, likewise machine B has m kinds of working modes, mode_0, mode_1, … , mode_m-1. At the beginning they are both work at mode_0.

For k jobs given, each of them can be processed in either one of the two machines in particular mode. For example, job 0 can either be processed in machine A at mode_3 or in machine B at mode_4, job 1 can either be processed in machine A at mode_2 or in machine B at mode_4, and so on. Thus, for job i, the constraint can be represent as a triple (i, x, y), which means it can be processed either in machine A at mode_x, or in machine B at mode_y.

Obviously, to accomplish all the jobs, we need to change the machine's working mode from time to time, but unfortunately, the machine's working mode can only be changed by restarting it manually. By changing the sequence of the jobs and assigning each job to a suitable machine, please write a program to minimize the times of restarting machines. 
 

Input
The input file for this program consists of several configurations. The first line of one configuration contains three positive integers: n, m (n, m < 100) and k (k < 1000). The following k lines give the constrains of the k jobs, each line is a triple: i, x, y.

The input will be terminated by a line containing a single zero.
 

Output
The output should be one integer per line, which means the minimal times of restarting machine.
 

Sample Input
5 5 10
0 1 1
1 1 2
2 1 3
3 1 4
4 2 1
5 2 2
6 2 3
7 2 4
8 3 3
9 4 3
0
 

Sample Output
3

*/

#include <iostream>
#include <string>
#include <cstring>
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
    while(cin >> m, m)
    {
         cin >> n >> k;
         vector< vector<int> > graph;
         graph.resize(m);
         for(int i = 0;i < m;i++)
             graph[i].resize(n);
         for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                graph[i][j] = 0;

         int aZero = 0, bZero = 0;
         for(int i = 0;i < k;i++)
         {
             int s, im, in;
             cin >> s >> im >> in;
             graph[im][in] = 1;
             if (im == 0)
                 aZero = 1;
             if (in == 0)
                 bZero = 1;
         }
         
         cout << maxMatch(graph) - aZero - bZero << endl;
    }
    return 0;
}
