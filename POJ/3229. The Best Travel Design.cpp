/*
Description

Dou Nai is an excellent ACM programmer, and he felt so tired recently that he wants to release himself from the hard work. He plans a travel to Xin Jiang .With the influence of literature, he wishes to visit Tian Chi, Da Ban Town, Lou Lan mysterious town , Yi Li , and other sights that also have great attraction to him. But the summer vocation time is not long. He must come back before the end of the summer vocation. For visiting more sights and all the necessary sights, he should make a thorough plan. Unfortunately, he is too tired to move, so you must help him to make this plan. Here are some prerequisites: there are two ways of transportation, bus and train, and velocity of the bus is 120km/h and the train is 80km/h. Suppose the travel is started from Urumuqi (point 1), and the end of the travel route is Urumuqi too. You need to spend some time to visit the sights, but the time of each visit is not always equal. Suppose we spend 12 hours on traveling every day.
Input

There are several test cases. For each case, the first line is three integers N, M and K. N (1<=n<=15) is the number of sights, M(0<=M<=N) is total sights he must arrived (sight 1 is always must be arrived) and K is total traveling time (per day). The second line is M integers which sights he must visited. The third line is N integers, the ith integer means the time he will stay in the sight i (per hour). Then several lines follow. Each line is four integers x, y, len and kind, 1<=x, y<=n, 0<len<=1000, means there is a bidirectional path between sights x and y, the distance is len, kind=0 means x and y are connected by train, kind=1 is by bus.
x=y=len=kind=0 means end of the path explanation.
N=M=K=0 means end of the input.
Output

For each case, output maximum sights he will travel with all necessary sights visited or "No Solution" if he can't travel all the sights he like best in time.
Sample Input

3 3 3
1 2 3
10 8 6
1 2 120 0
1 3 60 1
2 3 50 1
0 0 0 0
3 3 2
1 2 3
10 8 6
1 2 120 0
1 3 60 1
2 3 50 1
0 0 0 0
0 0 0
Sample Output

3
No Solution

*/

#include <iostream>
#include <cstdio>
using namespace std;

int spTime[20];
double dp[1 << 15][20];
int graph[20][20][2];
double transferTime[20][20];
int n, m, k;
int mustVisit;

void dfs(int status, int sight, double value)
{
	if (dp[status][sight] != -1 && dp[status][sight] < value)
		return;

	dp[status][sight] = value;
	for(int i = 2;i <= n;i++)
	{
		if (transferTime[sight][i] > 0 && ((status & (1 << (i - 1))) == 0))
			if (transferTime[sight][i] + value + spTime[i] <= k)
				dfs((status | (1 << (i - 1))), i, transferTime[sight][i] + value + spTime[i]);
	}
}

void floyd()
{
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
             if (graph[i][j][0] != -1)
             {
                 if (graph[i][j][1] == 0)
                    transferTime[i][j] = graph[i][j][0] * 1.0 / 80;
                 else
                     transferTime[i][j] = graph[i][j][0] * 1.0 / 120;
             }
             else
                transferTime[i][j] = -1;
    
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
        {
            if (k == i)
                continue;
            for(int j = 1;j <= n;j++)
            {
                if (j == k || j == i)
                    continue;
                if (transferTime[i][k] > 0 && transferTime[k][j] > 0 && (transferTime[i][j] < 0 || transferTime[i][j] > transferTime[i][k] + transferTime[k][j]))
                    transferTime[i][j] = transferTime[i][k] + transferTime[k][j];
            }
        }
}

int main()
{
	while(cin >> n >> m >> k, m || n || k)
	{
		k *= 12;
		mustVisit = 0;
		for(int i = 0;i < m;i++)
		{
			int a;
			cin >> a;
			mustVisit |= 1 << (a - 1);
		}
		
		for(int i = 1;i <= n;i++)
            scanf("%d", &spTime[i]);

		for(int i = 0;i < 1 << n;i++)
			for(int j = 0;j <= n;j++)
				dp[i][j] = -1;

		for(int i = 0;i < 20;i++)
			for(int j = 0;j < 20;j++)
				graph[i][j][0] = graph[j][i][1] = -1;

		int x, y, len, kind;
		while(scanf("%d %d %d %d", &x, &y, &len, &kind), x || y || len || kind)
		{
			graph[x][y][0] = graph[y][x][0] = len;
			graph[x][y][1] = graph[y][x][1] = kind;
		}
		floyd();
		dfs(1, 1, spTime[1]);

		int res = -1;
		for(int i = 0;i < (1 << n);i++)
		{
			if((i & mustVisit) != mustVisit)
				continue;	

			int oneNum = 0;
			int temp = i;
			while(temp)
			{
				temp = temp & (temp - 1);
				oneNum++;
			}

			for(int j = 2;j <= n;j++)
			{
				if (dp[i][j] == -1)
					continue;

				if (transferTime[j][1] > 0 && transferTime[j][1] + dp[i][j] < k)
                    res = res < oneNum ? oneNum : res;
			}
		}

		if (res >= m)
			cout << res << endl;
		else
			cout << "No Solution" << endl;
	}
	return 0;
}
