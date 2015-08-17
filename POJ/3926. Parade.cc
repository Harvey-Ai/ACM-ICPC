/*
Description

Panagola, The Lord of city F likes to parade very much. He always inspects his city in his car and enjoys the welcome of his citizens. City F has a regular road system. It looks like a matrix with n+1 west-east roads and m+1 north-south roads. Of course, there are (n+1)*(m+1) road crosses in that system. The parade can start at any cross in the southernmost road and end at any cross in the northernmost road. Panagola will never travel from north to south or pass a cross more than once. Citizens will see Panagola along the sides of every west-east road. People who love Panagola will give him a warm welcome and those who hate him will throw eggs and tomatoes instead. We call a road segment connecting two adjacent crosses in a west-east road a “love-hate zone”. Obviously there are m love-hate zones in every west-east road. When passing a love-hate zone, Panagola may get happier or less happy, depending on how many people love him or hate him in that zone. So we can give every love-hate zone a “welcome value” which may be negative, zero or positive. As his secretary, you must make Panagola as happy as possible. So you have to find out the best route - of which the sum of the welcome values is maximal. You decide where to start the parade and where to end it. 

When seeing his Citizens, Panagola always waves his hands. He may get tired and need a break. So please never make Panagola travel in a same west-east road for more than k minutes. If it takes p minutes to pass a love-hate zone, we say the length of that love-hate zone is p. Of course you know every love-hate zone's length. 

The figure below illustrates the case in sample input. In this figure, a best route is marked by thicker lines. 


Input

There are multiple test cases. Input ends with a line containing three zeros. 
Each test case consists of 2 * n + 3 lines. 
The first line contains three integers: n, m and k.(0<n<=100,0<m<=10000, 0<=k<=3000000) 
The next n+1 lines stands for n + 1 west-east roads in north to south order. Each line contains m integers showing the welcome values of the road's m love-hate zones, in west to east order. 
The last n+1 lines also stands for n + 1 west-east roads in north to south order. Each line contains m integers showing the lengths (in minutes) of the road's m love-hate zones, in west to east order.
Output

For each test case, output the sum of welcome values of the best route. The answer can be fit in a 32 bits integer.
Sample Input

2 3 2 
7 8 1 
4 5 6 
1 2 3 
1 1 1 
1 1 1 
1 1 1 
0 0 0
Sample Output

27
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int inf = 1 << 29;
const int maxn = 105;
const int maxm = 10005;
struct node
{
    int pos;
    int val;
}Q[maxm];
int suw[maxn][maxm],sul[maxn][maxm],dp[2][maxm];
char str[2000001];
int k,m,n,wei;

int getint()
{
    int data = 0,u = 1;
    while(str[wei] < '0' || str[wei] > '9' ) wei++;
    if(wei && str[wei-1]=='-')  u = -1;
    while(str[wei] >= '0' && str[wei] <= '9')
    {
        data = data * 10 + str[wei] - '0';
        wei++;
    }
    return data * u;
}

void read()
{
    for(int i=n+1;i>=1;i--)
    {
        suw[i][0] = 0;
        gets(str);
        wei = 0;
        for(int j=1;j<=m;j++)
        {
            suw[i][j] = getint();
            suw[i][j] += suw[i][j-1];
        }
    }
    for(int i=n+1;i>=1;i--)
    {
        sul[i][0] = 0;
        gets(str);
        wei = 0;
        for(int j=1;j<=m;j++)
        {
            sul[i][j] = getint();
            sul[i][j] += sul[i][j-1];
        }
    }
    return;
}

void init(int cho,int val)
{
    for(int i=0;i<=m;i++)
    {
        dp[cho][i] = val;
    }
    return;
}

void solve()
{
    init(0,0);
    for(int i=1;i<=n+1;i++)
    {
        int cur = i & 1;
        int pre = cur ^ 1;
        init(cur,-inf);
        int head = 0,rear = 0;
        for(int j=0;j<=m;j++)
        {
            int tmp = dp[pre][j] - suw[i][j];
            while(head < rear && Q[rear-1].val <= tmp)
            {
                rear--;
            }
            Q[rear].pos = j;
            Q[rear++].val = tmp;
            while(head < rear && sul[i][j] - sul[i][Q[head].pos] > k)
            {
                head++;
            }
            dp[cur][j] = MAX(dp[cur][j] , Q[head].val + suw[i][j]);
        }
        head = rear = 0;
        for(int j=m;j>=0;j--)
        {
            int tmp = dp[pre][j] + suw[i][j];
            while(head < rear && Q[rear-1].val <= tmp)
            {
                rear--;
            }
            Q[rear].pos = j;
            Q[rear++].val = tmp;
            while(head < rear && sul[i][Q[head].pos] - sul[i][j] > k)
            {
                head++;
            }
            dp[cur][j] = MAX(dp[cur][j] , Q[head].val - suw[i][j]);
        }
    }
    int res = -inf;
    for(int i=0;i<=m;i++)
    {
        res = MAX(res , dp[(n+1) & 1][i]);
    }
    printf("%d\n",res);
    return;
}

int main()
{
    while(gets(str))
    {
        wei = 0;
        n = getint();
        m = getint();
        k = getint();
        if(n+m+k == 0) break;
        read();
        solve();
    }
    return 0;
}
