#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int flag[100005];
long long dp[100005];
int main()
{
	int n;
	cin >> n;
	memset(flag, 0, sizeof(flag));
	for(int i = 0;i < n;i++)
	{
		int a;
		scanf("%d", &a);
		flag[a]++;
	}
	dp[0] = 0;
	dp[1] = flag[1];
	
	long long res = dp[1];
	for(int i = 2;i < 100005;i++)
	{
		if (dp[i - 1] < dp[i - 2] + (long long)i * flag[i])
			dp[i] = dp[i - 2] +(long long)i * flag[i];
		else
			dp[i] = dp[i - 1];
		if (dp[i] > res)
			res = dp[i];
	}
	
	cout << res << endl;
	return 0;
}
