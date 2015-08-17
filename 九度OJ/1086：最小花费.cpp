/*
题目描述：
在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下:
距离s           票价
0<S<=L1         C1
L1<S<=L2        C2
L2<S<=L3        C3
输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9。
每两个站之间的距离不超过L3。
当乘客要移动的两个站的距离大于L3的时候，可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。
现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。
然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。
根据输入，输出乘客从A到B站的最小花费。
输入：
以如下格式输入数据：
L1  L2  L3  C1  C2  C3
A  B
N
a[2]
a[3]
……
a[N]
输出：
可能有多组测试数据，对于每一组数据，
根据输入，输出乘客从A到B站的最小花费。
样例输入：
1 2 3 1 2 3
1 2
2
2
样例输出：
2
*/


#include <iostream>
using namespace std;
 
int l1, l2, l3, c1, c2, c3;
long long price(int dist)
{
    if (dist <= 0)
        return 0;
    if (dist <= l1)
        return c1;
    else if (dist <= l2)
        return c2;
    else if (dist <= l3)
        return c3;
    return -1;
}
 
long long dp[1000][1000];
long long g[1000][1000];
long long arr[1005];
int main()
{
    int a, b;
    int n;
    int i, j;
 
    while(cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3)
    {
        cin >> a >> b;
        a--;b--;
        cin >> n;
        arr[0] = 0;
        for(i = 1;i < n;i++)
            cin >> arr[i];
 
        for(i = 0;i < n;i++)
            for(j = i;j < n;j++)
            {
                g[i][j] = arr[j] - arr[i];
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
            }
 
        for(i = 1;i < n;i++)
        {
            if (a + i < n)
            {
                for(j = a;j <= a + i;j++)
                    if (dp[a][j] != -1 && price(g[j][a + i]) != -1 && (dp[a][a + i] > dp[a][j] + price(g[j][a + i]) || dp[a][a + i] == -1))
                        dp[a][a + i] = dp[a][j] + price(g[j][a + i]);
            }
            if (a - i >= 0)
            {
                for(j = a;j >= a - i;j--)
                    if (dp[a - i][a] != -1 && price(g[a - i][j]) != -1 && (dp[a - i][a] > dp[j][a] + price(g[a - i][j]) || dp[a - i][a] == -1))
                        dp[a - i][a] = dp[j][a] + price(g[a - i][j]);
            }
        }
 
        if (a > b)
            cout << dp[b][a] << endl;
        else
            cout << dp[a][b] << endl;
    }
    return 0;
}
