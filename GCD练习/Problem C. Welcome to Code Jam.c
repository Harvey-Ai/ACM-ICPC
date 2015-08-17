#include <stdio.h>
#include <string.h>

char target[] = "welcome to code jam";

int main()
{
	int ncase, icase;
	int dp[505];
	char str[505];
	int tar_len;
	int i, j;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);


	tar_len = strlen(target);

	scanf("%d", &ncase);
	getchar();

	for(icase = 1;icase <= ncase;icase++)
	{
		memset(dp, 0, sizeof(dp));
		gets(str);
//		printf("%s\n", str);
		for(i = 0;str[i] != '\0';i++)
		{
			for(j = tar_len - 1;j >= 0;j--)
				if (str[i] == target[j])
				{
					if (j == 0)
						dp[j + 1]++;
					else
						dp[j + 1] += dp[j];
					dp[j + 1] %= 10000;
				}
		//	printf("%d %d\n", i, dp[tar_len]);
		}

		printf("Case #%d: %04d\n", icase, dp[tar_len]);
	}
	return 0;
}
