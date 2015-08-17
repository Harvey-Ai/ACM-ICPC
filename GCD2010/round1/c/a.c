#include <stdio.h>
#include <stdlib.h>
#define N 1005

struct line
{
	int a, b;
};

int cmp(const void *a, const void *b)
{
	struct line *aa = (struct line *)a;
	struct line *bb = (struct line *)b;

	return aa->a - bb->a;
}
int main()
{
	struct line arr[N];
	int ncase, icase;
	int i, j, n;
	int cnt;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d %d", &arr[i].a, &arr[i].b);

		qsort(arr, n, sizeof(arr[0]), cmp);

		cnt = 0;
		for(i = 0;i < n;i++)
			for(j = i + 1;j < n;j++)
				if (arr[i].b > arr[j].b)
					cnt++;

		printf("Case #%d: %d\n", icase, cnt);
	}
	return 0;
}
