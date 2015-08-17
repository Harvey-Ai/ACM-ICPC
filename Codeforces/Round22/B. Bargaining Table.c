#include <stdio.h>
#include <string.h>
#define N 30

char arr[N][N];
int temp[N];
int main()
{
	int i1, i2, i, j;
	int len, maxLen;
	int res;
	int m, n;

	scanf("%d %d", &m, &n);

	for(i = 0;i < m;i++)
		scanf("%s", arr[i]);

	res = 0;
	for(i1 = 0;i1 < m;i1++)
	{
		memset(temp, 0, sizeof(temp));
		for(i2 = i1;i2 < m;i2++)
		{
			for(j = 0;j < n;j++)
				temp[j] |= (arr[i2][j] - '0');

			len = 0;
			maxLen = 0;
			for(j = 0;j < n;j++)
			{
				if (temp[j] == 0)
					len++;
				else
					len = 0;
				if (maxLen < len)
					maxLen = len;
			}
			if (maxLen && (i2 - i1 + 1) * 2 + maxLen * 2 > res)
				res = (i2 - i1 + 1)* 2 + maxLen * 2;
		}
	}
	printf("%d\n", res);
}
