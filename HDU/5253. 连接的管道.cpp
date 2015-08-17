/*
Problem Description
老 Jack 有一片农田，以往几年都是靠天吃饭的。但是今年老天格外的不开眼，大旱。所以老 Jack 决定用管道将他的所有相邻的农田全部都串联起来，这样他就可以从远处引水过来进行灌溉了。当老 Jack 买完所有铺设在每块农田内部的管道的时候，老 Jack 遇到了新的难题，因为每一块农田的地势高度都不同，所以要想将两块农田的管道链接，老 Jack 就需要额外再购进跟这两块农田高度差相等长度的管道。

现在给出老 Jack农田的数据，你需要告诉老 Jack 在保证所有农田全部可连通灌溉的情况下，最少还需要再购进多长的管道。另外，每块农田都是方形等大的，一块农田只能跟它上下左右四块相邻的农田相连通。
 

Input
第一行输入一个数字T(T≤10)，代表输入的样例组数

输入包含若干组测试数据，处理到文件结束。每组测试数据占若干行，第一行两个正整数 N,M(1≤N,M≤1000)，代表老 Jack 有N行*M列个农田。接下来 N 行，每行 M 个数字，代表每块农田的高度，农田的高度不会超过100。数字之间用空格分隔。
 

Output
对于每组测试数据输出两行：

第一行输出："Case #i:"。i代表第i组测试数据。

第二行输出 1 个正整数，代表老 Jack 额外最少购进管道的长度。
 

Sample Input
2
4  3
9 12 4
7 8 56
32 32 43
21 12 12
2  3
34 56 56
12 23 4
 

Sample Output
Case #1:
82
Case #2:
74
*/

#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int arr[1005][1005];
int dist[1005][1005];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool check(int a, int b)
{
    if (a < 0 || a >= n || b < 0 || b >= m)
        return false;
    return true;
}

struct qEle
{
    int x, y, dist;

    qEle(int xx, int yy, int d)
    {
        x = xx, y = yy;
        dist = d;
    }
    qEle()
    {
        x = 0, y = 0;
        dist = -1;
    }
    bool operator() (qEle e1, qEle e2)
    {
        return e1.dist >= e2.dist;
    }
};


int main()
{
    int ncase;
    cin >> ncase;

    for(int icase = 1;icase <= ncase;icase++)
    {
        cin >> n >> m;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                scanf("%d", &arr[i][j]);

        for(int i = 0;i < 1005;i++)
            for(int j = 0;j < 1005;j++)
                dist[i][j] = 1000000;
        
        priority_queue<qEle, vector<qEle>, qEle> pQ;
        pQ.push(qEle(0, 0, 0));
        
        long long cost = 0;
        for(int i = 0;i < m * n;i++)
        {
            qEle ele = pQ.top();
            pQ.pop();

            while(dist[ele.x][ele.y] == -1)
            {
                ele = pQ.top();
                pQ.pop();
            }

            
            cost += ele.dist;
            dist[ele.x][ele.y] = -1;
            for(int j = 0;j < 4;j++)
            {
                int x = ele.x + dir[j][0], y = ele.y + dir[j][1];
                if (check(x, y) && dist[x][y] != -1)
                    if (abs(arr[ele.x][ele.y] - arr[x][y]) < dist[x][y])
                    {
                        dist[x][y] = abs(arr[ele.x][ele.y] - arr[x][y]);
                        pQ.push(qEle(x, y, dist[x][y]));
                    }
            }
        }

        cout << "Case #" << icase << ":" << endl;
        cout << cost << endl;
    }

    return 0;
}
