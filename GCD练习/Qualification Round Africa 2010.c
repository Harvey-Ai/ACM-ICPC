#include <stdio.h>

int main()
{
	int ncase;
	int n;
	int i, j, icase;
	int sum, need;
	int arr[2005];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &need);
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		for(i = 0;i < n;i++)
		{
			for(j = i + 1;j < n;j++)
				if (arr[i] + arr[j] == need)
					break;
			if (j < n)
				break;
		}
		printf("Case #%d: %d %d\n", icase, i + 1, j + 1);
	}
	return 0;
}
