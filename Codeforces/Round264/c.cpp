#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

long long arr[2005][2005];
long long dp1[2005][2005][2];
long long dp2[2005][2005][2];

int main()
{
	int n;
	cin >> n;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%I64d", &arr[i][j]);

	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));

	for(int j = 0;j < n;j++)
		dp1[0][j][1] = dp1[0][j][0] = arr[0][j];
	for(int i = 1;i < n;i++)
	{
		dp1[i][0][0] = arr[i][0];
		dp1[i][0][1] = dp1[i - 1][1][1] + arr[i][0];
		for(int j = 1;j < n - 1;j++)
		{
			dp1[i][j][0] = dp1[i - 1][j - 1][0] + arr[i][j];
			dp1[i][j][1] = dp1[i - 1][j + 1][1] + arr[i][j];
		}
		dp1[i][n - 1][0] = dp1[i - 1][n - 2][0] + arr[i][n - 1];
		dp1[i][n - 1][1] =  arr[i][n - 1];
	}

	for(int j = 0;j < n;j++)
		dp2[n - 1][j][1] = dp2[n - 1][j][0] = arr[n - 1][j];
	for(int i = n - 2;i >= 0;i--)
	{
		dp2[i][0][0] = arr[i][0];
		dp2[i][0][1] = dp2[i + 1][1][1] + arr[i][0];
		for(int j = 1;j < n - 1;j++)
		{
			dp2[i][j][0] = dp2[i + 1][j - 1][0] + arr[i][j];
			dp2[i][j][1] = dp2[i + 1][j + 1][1] + arr[i][j];
		}
		dp2[i][n - 1][0] = dp2[i + 1][n - 2][0] + arr[i][n - 1];
		dp2[i][n - 1][1] =  arr[i][n - 1];
	}

	int x1, x2, y1, y2;
	long long max1 = -1, max2 = -1;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if (max1 < dp1[i][j][0] + dp1[i][j][1] + dp2[i][j][0] + dp2[i][j][1] - arr[i][j] - arr[i][j] - arr[i][j])
			{
				x1 = i, y1 = j;
				max1 = dp1[i][j][0] + dp1[i][j][1] + dp2[i][j][0] + dp2[i][j][1] - arr[i][j] - arr[i][j] - arr[i][j];
			}

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if (max2 < dp1[i][j][0] + dp1[i][j][1] + dp2[i][j][0] + dp2[i][j][1] - arr[i][j] - arr[i][j] - arr[i][j] && (x1 + y1) % 2 != (i + j) % 2)
			{
				max2 = dp1[i][j][0] + dp1[i][j][1] + dp2[i][j][0] + dp2[i][j][1] - arr[i][j] - arr[i][j] - arr[i][j];
				x2 = i, y2 = j;
			}

	x1++, y1++, x2++, y2++;
	cout << max1 + max2 << endl;
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	return 0;
}
