#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	int pos;
	int m, n;
	int ff, ans;
	char str[100];
	int arr[1005];

	scanf("%d %d", &n, &m);

	memset(arr, 0, sizeof(arr));

	for(i = 0;i < m;i++)
	{
		for(j = 0;j < 4;j++)
		{
			scanf("%s", str);
			if (strcmp(str, "right") == 0)
				ff = 1;
			if (strcmp(str, "left") == 0)
				ff = -1;
		}
		scanf("%d", &pos);
		if (ff == 1)
		{
			for(j = 1;j <= pos;j++)
				arr[j] = -1;
			for(j = pos + 1;j <= n;j++)
				if (arr[j] == 0)
					arr[j] = 1;
		}
		else
		{
			for(j = 1;j < pos;j++)
				if (arr[j] == 0)
					arr[j] = 1;
			for(j = pos;j <= n;j++)
				arr[j] = -1;
		}
	}

	ans = 0;
	for(i = 1;i <= n;i++)
		if (arr[i] != -1)
			ans++;
	if (ans <= 0)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
