#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int statusNum = 1 << 16;
int primes[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int dp[100][statusNum];
int pre[100][statusNum];
int index[100][statusNum];
int arr[31];

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for(int i = 0;i < statusNum * 2;i++)
	{
		dp[0][i] = -1;
		pre[0][i] = -1;
		index[0][i] = -1;
	}

	for(int i = 0;i < 100;i++)
		for(int j = 0; j < statusNum * 2;j++)
			dp[i][j] = -1;

	for(int i = 1;i <= 59;i++)
	{
		int status = 0;
		for(int j = 0;j < 17;j++)
			if (i % primes[j] == 0)
				status |= 1 << j;
		if (dp[0][status] == -1 || dp[0][status] > abs(i - arr[0]))
		{
			dp[0][status] = abs(i - arr[0]);
			index[0][status] = i;
		}
	}

	for(int i = 1;i < n;i++)
	{
		for(int j = 1;j < 60;j++)
			for(int k = 0;k < statusNum * 2;k++)
				if (dp[i - 1][k] != -1)
				{
					int flag = 1;
					for(int s = 0;s < 17;s++)
					{
						if (k & 0x01 && j > primes[s] && j % primes[s] == 0)
						{
							flag = 0;
							break;
						}
						k >>= 1;
					}
					if (flag)
					{
						int status = k;
						for(int s = 0;s < 17;s++)
							if (j > primes[s] && j % primes[s] == 0)
							{
								status |= 1 << s;
							}
						if (dp[i][status] == -1 || dp[i][status] > dp[i - 1][k] + abs(j - arr[i]))
						{
							dp[i][status] = dp[i - 1][k] + abs(j - arr[i]);
							pre[i][status] = k;
							index[i][status] = j;
						}
					}
				}
	}

	int res[100];
	int minValue = -1;
	int preStatus = - 1;
	for(int i = 0;i < statusNum * 2;i++)
	{
		if (dp[n - 1][i] == -1)
			continue;
		if (minValue == -1 || dp[n - 1][i] < minValue)
		{
			minValue = dp[n - 1][i];
			res[n - 1] = index[n - 1][i];
			preStatus = pre[n - 1][i];
		}
	}
	for(int i = n - 2;i >= 0;i--)
	{
		res[i] = index[i][preStatus];
		preStatus = pre[i][preStatus];
	}
	for(int i = 0;i < n;i++)
		printf("%d ", res[i]);
	cout << endl;
	return 0;
}
