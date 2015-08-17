#include <iostream>
using namespace std;

int arr[5005];
int dp[5005][2];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	dp[0][0] = 0;dp[0][1] = 0;
	for(int i = 0;i < n;i++)
	{
		dp[i + 1][0] = arr[i];
		int min = -1;
		for(int j = 0;j < i + 1;j++)
		{
			if (dp[j][1] == -1)
				continue;
			if (dp[j][0] > arr[i])
			{
				if (min == -1 || min > dp[j][1])
					min = dp[j][1];
				dp[j][1] = -1;
			}
			else
			{
				if (min == -1 || min > dp[j][1] + arr[i] - dp[j][0])
					min = dp[j][1] + arr[i] - dp[j][0];
				if (dp[j][0] < arr[i])
					dp[j][1] = dp[j][1] + 1;
			}
		}
		dp[i + 1][1] = min;
	}
	int min = -1;
	for(int i = 0;i <= n;i++)
	{
		if (dp[i][1] == -1)
			continue;

		if (min == -1 || min > dp[i][1])
			min = dp[i][1];
	}
	cout << min << endl;
	return 0;
}
