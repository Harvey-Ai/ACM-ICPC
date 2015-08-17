/*
题目描述：
    This time, you are supposed to find A+B where A and B are two matrices, and then count the number of zero rows and columns.
输入：
    The input consists of several test cases, each starts with a pair of positive integers M and N (≤10) which are the number of rows and columns of the matrices, respectively. Then 2*M lines follow, each contains N integers in [-100, 100], separated by a space. The first M lines correspond to the elements of A and the second M lines to that of B.
    The input is terminated by a zero M and that case must NOT be processed.
输出：
    For each test case you should output in one line the total number of zero rows and columns of A+B.
样例输入：
2 2
1 1
1 1
-1 -1
10 9
2 3
1 2 3
4 5 6
-1 -2 -3
-4 -5 -6
0
样例输出：
1
5
*/


#include <iostream>
using namespace std;
 
int main()
{
    int i, j;
    int a;
    int g[100][100];
    int m, n;
 
    while(cin >>m, m)
    {
        cin >> n;
 
        for(i = 0;i < m;i++)
            for(j = 0;j < n;j++)
                cin >> g[i][j];
 
        for(i = 0;i < m;i++)
            for(j = 0;j < n;j++)
            {
                cin >> a;
                g[i][j] += a;
            }
 
        int res = 0;
        for(i = 0;i < m;i++)
        {
            for(j = 0;j < n;j++)
                if (g[i][j] != 0)
                    break;
 
            if (j == n)
                res ++;
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < m;j++)
                if (g[j][i] != 0)
                    break;
 
            if (j == m)
                res ++;
        }
        cout << res << endl;
    }
    return 0;
}
