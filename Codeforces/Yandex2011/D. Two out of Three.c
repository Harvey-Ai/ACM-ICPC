#include <iostream>
using namespace std;

const int MAX = 1000000005;

inline int max(int a, int b)
{
	return a < b ? b : a;
}

int dp[1005][1005];
int path[1005][1005][2];
int arr[1005];
vector <int> step;

int main()
{
	int i, k;
	int lastM;
	int temp, min, res;
	int n;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	if (n == 1)
	{
		printf("1\n");
		printf("%d\n", arr[0]);
		return 0;
	}

	odd = 0;
	if (n % 2)
	{
		arr[n] = 0;
		odd = 1;
		n++;
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = arr[0];

	for(i = 2;i < n;i += 2)
	{
		lastM = max(arr[i], arr[i - 1]);
		for(k = 0;k < i - 1;k++)
		{
			dp[i][k] = dp[i - 2][k] + lastM;
			path[i][k][1] = i;
			path[i][k][0] = i - 1;
		}

		min = MAX;
		for(k = 0;k < i - 1;k++)
		{
			temp = max(arr[k], arr[i - 1]) + dp[i - 2][k] - arr[k];
			if (temp < min)
			{
				id = k;
				min = temp;
			}
		}
		dp[i][i] = min + arr[i];
		path[i][i][1] = i - 1;
		path[i][i][0] = id;

		min = MAX;
		for(k = 0;k < i - 1;k++)
		{
			temp = max(arr[k], arr[i]) + dp[i - 2][k] - arr[k];
			if (temp < min)
			{
				id = k;
				min = temp;
			}
		}
		dp[i][i - 1] = min + arr[i - 1];
		path[i][i - 1][1] = i;
		path[i][i - 1][0] = id;
	}

	res = MAX;
	for(k = 0;k < n - 1;k++)
	{
		temp = dp[n - 2][k] + max(arr[k], arr[n - 1]) - arr[k];
		if (temp < res)
		{
			id = k;
			res = temp;
		}
	}

	printf("%d\n", res);

	step.clear();
	if (odd)
		step.push_back(id + 1);
	else
	{
		step.push_back(n);
		step.push_back(id + 1);
	}
	if (id == n - 2)
		i = n - 3;
	else
	{
		i = n - 2;
		used[id] = 1;
	}

	while(i > 0)
	{
		if (used[i])
			continue;

		if (i % 2 == 1)
		{
			min = MAX;
			for(k = 0;k < i;k++)
			{
				temp = dp[i - 1][k] + max(arr[i], arr[k]) - arr[k];
				if (temp < min)
				{
					id = k;
					temp = min;
				}
			}
			if (id == i - 1)
				i -= 2;
			else
				i--;
			used[id] = 1;
		}
		else
		{
			step.push_back(i);
			step.push_back(path[i][id][0]);
			id = path[i][id][0];
			used[id] = 1;
			i--;
		}
	}
	return 0;
}
