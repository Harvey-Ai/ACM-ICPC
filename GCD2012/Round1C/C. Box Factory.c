#include <iostream>
using namespace std;

long long mmin(long long a, long long b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int ncase, icase;
	long long g[105][105];
	long long arr[105][2], brr[105][2];
	long long sum1[105], sum2[105];
	int m, n;
	int i, j;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &n, &m);

		for(i = 0;i < n;i++)
			scanf("%lld %lld", &arr[i][0], &arr[i][1]);
		for(i = 0;i < m;i++)
			scanf("%lld %lld", &brr[i][0], &brr[i][1]);

		for(i = 0;i < 105;i++)
			for(j = 0;j < 105;j++)
				sum1[i][j] = sum2[i][j] = 0;

		for(i = 1;i < n;i++)
			for(j = 0;j < 105;j++)
				sum1[i][arr[i][1] - 1] = sum1[i - 1][arr[i][1] - 1] + arr[i][0];
		
		for(i = 1;i < m;i++)
			for(j = 0;j < 105;j++)
				sum2[i][brr[i][1] - 1] = sum2[i - 1][brr[i][1] - 1] + brr[i][0];

		for(i = 0;i < m;i++)
			for(j = 0;j < n;j++)

		
		for(i = 0;i <= m;i++)
			g[i][0] = g[0][i] = 0;
		for(i = 0;i <= n;i++)
			g[i][0] = g[0][i] = 0;

		for(i = 1;i <= n;i++)
			for(j = 1;j <= m;j++)
			{
				g[i][j] = 0;
				for(k = i;k >= 0;k--)
					for(l = j;l >= 0;l--)
						g[i][j] = g[k][l] + pipei[k + 1][i][l + 1][j] > g[i][j] ? g[k][l] +pipei[k + 1][i][l + 1][j] : g[i][j];
			}
		printf("Case #%d: %lld\n", icase, g[n][m]);
	}
	return 0;
}
