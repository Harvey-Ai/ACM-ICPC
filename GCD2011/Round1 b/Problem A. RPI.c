#include <stdio.h>

double wp[105], owp[105], oowp[105];
char g[105][105];
int main()
{
	int ncase;
	int icase;
	int i, j, k;
	int n;
	int match, num;
	double temp;
	double win;
	double sum;
	double res;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);

		for(i = 0;i < n;i++)
			scanf("%s", g[i]);

		for(i = 0;i < n;i++)
		{
			win = 0;
			match = 0;
			for(j = 0;j < n;j++)
				if (g[i][j] != '.')
				{
					match++;
					if (g[i][j] == '1')
						win++;
				}
			wp[i] = win * 1.0 / match;

			num = 0;
			temp = 0;
			for(j = 0;j < n;j++)
			{
				if (i == j)
					continue;
				if (g[i][j] == '.')
					continue;
				num++;

				match = 0;
				win = 0;
				for(k = 0;k < n;k++)
				{
					if (k == i)
						continue;
					if (g[j][k] != '.')
					{
						match++;
						if (g[j][k]== '1')
							win++;
					}
				}
		//		printf("%d %lf\n", match, win); 
				temp += win * 1.0 / match;
			}
		//	printf("%lf %d\n", temp, num);
			if (num != 0)
				owp[i] = temp / num;
			else
				owp[i] = 0;
		}

		for(i = 0;i < n;i++)
		{
			sum = 0;
			match = 0;
			for(j = 0;j < n;j++)
				if (g[i][j] != '.')
				{
					sum += owp[j];
					match++;
				}
			oowp[i] = sum / match;
		}

		printf("Case #%d:\n", icase);

		for(i = 0;i < n;i++)
		{
			res = (wp[i] + owp[i] * 2 + oowp[i]) / 4;
		//	printf("%lf %lf %lf %lf\n", wp[i], owp[i], oowp[i], res);
			printf("%.6g\n", res);
		}

	}
	return 0;
}
