#include <cstdio>

int mass[505][505];

int check(int a1, int b1, int a2, int b2)
{
	int temp1 = mass[a1][b1];
	int temp2 = mass[a1][b2];
	int temp3 = mass[a2][b1];
	int temp4 = mass[a2][b2];
	double midi, midj;
	int i, j;
	double pi, pj;
	double sum1, sum2;

	mass[a1][b1] = mass[a1][b2] = mass[a2][b1] = mass[a2][b2] = 0;

	midi = (a2 - a1 + 1) * 1.0 / 2.0 + a1;
	midj = (b2 - b1 + 1) * 1.0 / 2.0 + b1;

//	printf("%lf %lf\n", midi, midj);
	sum1 = sum2 = 0;
	for(i = a1;i <= a2;i++)
		for(j = b1;j <= b2;j++)
		{
			pi = i + 0.5 - midi;
			pj = j + 0.5 - midj;
		//	printf("%lf %lf\n", pi, pj);
		//	printf("%lf %lf %lf %lf %lf %lf\n", i, j, midi, midj, pi, pj);
			sum1 += pi * mass[i][j];
			sum2 += pj * mass[i][j];
		}

//	printf("%lf %lf\n", sum1, sum2);
	if (sum1 == 0 && sum2 == 0)
	{
		mass[a1][b1] = temp1;
		mass[a1][b2] = temp2;
		mass[a2][b1] = temp3;
		mass[a2][b2] = temp4;
		return 1;
	}
	else
	{
		mass[a1][b1] = temp1;
		mass[a1][b2] = temp2;
		mass[a2][b1] = temp3;
		mass[a2][b2] = temp4;
		return 0;
	}
}

int main()
{
	int ncase;
	int icase;
	int i, j, k;
	int border;
	int r, c, d;
	int ans;
	char ss[505];

//	freopen("1.txt", "r", stdin);
//	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d", &r, &c, &d);
		for(i = 0;i < r;i++)
		{
			scanf("%s", ss);
			for(j = 0;j < c;j++)
			{
				mass[i][j] = ss[j] - '0';
				mass[i][j] += d;
			}
		}

		border = r > c ? c : r;

	//	printf("%d %d\n", check(0, 0, 0, 0), border);
	//	printf("%d %d\n", check(1, 1, 5, 5), border);
		ans = -1;
		for(k = border;k >= 3;k--)
		{
			for(i = 0;i + k - 1 < r;i++)
			{
				for(j = 0;j + k -1 < c;j++)
					if (check(i, j, i + k - 1, j + k - 1))
					{
						ans = k;
			//			printf("%d\n", ans);
						break;
					}
				if (ans > 0)
					break;
			}
			if (ans > 0)
				break;
		}
		if (ans > 0)
			printf("Case #%d: %d\n", icase, ans);
		else
			printf("Case #%d: IMPOSSIBLE\n", icase);
	}
	return 0;
}
