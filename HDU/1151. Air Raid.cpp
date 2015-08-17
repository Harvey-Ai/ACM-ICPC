/*
Problem Description
Consider a town where all the streets are one-way and each street leads from one intersection to another. It is also known that starting from an intersection and walking through town's streets you can never reach the same intersection i.e. the town's streets form no cycles.

With these assumptions your task is to write a program that finds the minimum number of paratroopers that can descend on the town and visit all the intersections of this town in such a way that more than one paratrooper visits no intersection. Each paratrooper lands at an intersection and can visit other intersections following the town streets. There are no restrictions about the starting intersection for each paratrooper.
 

Input
Your program should read sets of data. The first line of the input file contains the number of the data sets. Each data set specifies the structure of a town and has the format:

no_of_intersections
no_of_streets
S1 E1
S2 E2
......
Sno_of_streets Eno_of_streets

The first line of each data set contains a positive integer no_of_intersections (greater than 0 and less or equal to 120), which is the number of intersections in the town. The second line contains a positive integer no_of_streets, which is the number of streets in the town. The next no_of_streets lines, one for each street in the town, are randomly ordered and represent the town's streets. The line corresponding to street k (k <= no_of_streets) consists of two positive integers, separated by one blank: Sk (1 <= Sk <= no_of_intersections) - the number of the intersection that is the start of the street, and Ek (1 <= Ek <= no_of_intersections) - the number of the intersection that is the end of the street. Intersections are represented by integers from 1 to no_of_intersections.

There are no blank lines between consecutive sets of data. Input data are correct.
 

Output
The result of the program is on standard output. For each input data set the program prints on a single line, starting from the beginning of the line, one integer: the minimum number of paratroopers required to visit all the intersections in the town.
 

Sample Input
2
4
3
3 4
1 3
2 3
3
3
1 3
1 2
2 3
 

Sample Output
2
1
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
    int ncase;
    cin >> ncase;
    
    while(ncase--)
    {
        int nc, ns;
        cin >> nc >> ns;
        vector< vector<int> > graph;
        graph.resize(nc);
        for(int i = 0;i < nc;i++)
            graph[i].resize(nc);
        
        for(int i = 0;i < ns;i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
        }
        
        cout << nc - maxMatch(graph) << endl;
    }
    return 0;
}
