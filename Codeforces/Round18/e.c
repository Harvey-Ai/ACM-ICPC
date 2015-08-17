#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 505

char str[N][N];
char out[N][N];
int diff[N][27][27];
int dp[N][27][27][3];

struct buff
{
	int a1, a2;
	int value;
}buff[1000];

int cmp(const void *a, const void *b)
{
	struct buff *aa = (struct buff *)a;
	struct buff *bb = (struct buff *)b;

	return aa->value - bb->value;
}

void initDiff(char str[N][N], int m, int n)
{
	int i, j, k1, k2;
	memset(diff, 0, sizeof(diff));
	for(i = 0;i < m;i++)
	{
		for(k1 = 0;k1 < 26;k1++)
			for(k2 = 0;k2 < 26;k2++)
			{
				for(j = 0;j < n;j++)
					if (j & 0x01)
					{
						if (str[i][j] != k2 +'a')
							diff[i + 1][k1][k2] ++;
					}
					else
					{
						if (str[i][j] != k1 +'a')
							diff[i + 1][k1][k2] ++;
					}
			}
	}
}

int main()
{
	int m, n;
	int i, j, k1, k2, k11, k22;
	int min, preK1, preK2;
	int temp;
	int buffN;

	scanf("%d %d", &m, &n);
	for(i = 0;i < m;i++)
		scanf("%s", str[i]);

	if (n < 2)
	{
		min = 0;
		out[0][0] = str[0][0];
		for(i = 1;i < m;i++)
			if (str[i][0] == out[i - 1][0])
			{
				min++;
				for(j = 0;j < 26;j++)
					if (out[i - 1][0] != j + 'a' &&
						(i + 1 >= m || str[i + 1][0] != j + 'a'))
					{
						out[i][0] = j + 'a';
						break;
					}
			}
			else
				out[i][0] = str[i][0];

		printf("%d\n", min);
		for(i = 0;i < m;i++)
			printf("%s\n", out[i]);
		return 0;
	}

	initDiff(str, m, n);
	memset(dp, 0, sizeof(dp));

	for(i = 1;i <= m;i++)
	{
		buffN = 0;
		for(k11 = 0;k11 < 26;k11++)
			for(k22 = 0;k22 < 26;k22++)
			{
				if (k11 == k22)
					continue;
				buff[buffN].a1 = k11;
				buff[buffN].a2 = k22;
				buff[buffN].value = dp[i - 1][k11][k22][0];
				buffN++;
			}

		qsort(buff, buffN, sizeof(buff[0]), cmp);
		for(k1 = 0;k1 < 26;k1++)
			for(k2 = 0;k2 < 26;k2++)
			{
				if (k1 == k2)
					continue;

				for(j = 0;j < buffN;j++)
					if (k1 != buff[j].a1 &&	k2 != buff[j].a2)
					{
						min = buff[j].value;
						preK1 = buff[j].a1;
						preK2 = buff[j].a2;
						break;
					}
				dp[i][k1][k2][0] = min + diff[i][k1][k2];
			//	printf("(%d %d) %d\n", k1, k2, dp[i][k1][k2][0]);
				dp[i][k1][k2][1] = preK1;
				dp[i][k1][k2][2] = preK2;
			}
	}

	min = -1;
	for(k1 = 0;k1 < 26;k1++)
		for(k2 = 0;k2 < 26;k2++)
		{
			if (k1 == k2)
				continue;
			if (dp[m][k1][k2][0] < min || min == -1)
			{
				min = dp[m][k1][k2][0];
				preK1 = k1;
				preK2 = k2;
			}
		}

	printf("%d\n", min);
	for(i = m;i >= 1;i--)
	{
		for(j = 0;j < n;j++)
			if (j & 0x01)
				out[i][j] = preK2 + 'a';			
			else
				out[i][j] = preK1 + 'a';
		out[i][j] = '\0';

		temp = preK1;
		preK1 = dp[i][preK1][preK2][1];		
		preK2 = dp[i][temp][preK2][2];
	}

	for(i = 1;i <= m;i++)
		printf("%s\n", out[i]);
	return 0;
}
