#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[500][500];
long long cost[500][500];

int main()
{
    int m, n, k, l;

    int ll, rr, cc;
    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cost[i][j] = -1;
    for(int i = 0;i < m;i++)
    {
        cin >> ll >> rr >> cc;
        for(int j = rr;j >= ll;j--)
            if (cost[j][rr] == -1 || cost[j][rr] > cc)
                cost[j][rr] = cc;
    }

    dp[0][0] = 0;
    for (int i = 1;i <= n;i++)
        dp[0][i] = -1;
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= k && i - j >= 0;j++)
        {
            if (i == j)
                dp[i][j] = -1;
            else
                dp[i][j] = dp[i - 1][j];
            for(int s = i - 1;s >= 0 && j >= i - s && s >= j - i + s;s--)
                if (dp[s][j - i + s] != -1 && cost[s + 1][i] != -1 && (dp[s][j - i + s] + cost[s + 1][i] < dp[i][j] || dp[i][j] == -1))
                    dp[i][j] = dp[s][j - i + s] + cost[s + 1][i]; 
        }
    }


    // printf("dp[8][7]: %d dp[10][3] %d dp[10][9 %d\n", dp[8][7], dp[10][3], dp[10][9]);
    long long res = -1;
    for(int i = 1;i <= n;i++)
        if (k <= i && dp[i][k] != -1 && (dp[i][k] < res || res == -1))
            res = dp[i][k];

    printf("%lld\n", res);
    return 0;
}

