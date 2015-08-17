#include <stdio.h>
#include <stdlib.h>
#define N 200005

struct box
{
	long long apple, pear;
	int ind;
}box[N];

int ans[N];
int cmp(const void *a, const void *b)
{
	struct box *aa = (struct box *)a;
	struct box *bb = (struct box *)b;
	return aa->apple - bb->apple;
}

int cmp2(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i;
	int n;
	int ncase;
	int cnt;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d", &n);

		for(i = 0;i < n * 2 - 1;i++)
		{
			scanf("%d %d", &box[i].apple, &box[i].pear);
			box[i].ind = i + 1;
		}

		qsort(box, 2 * n - 1, sizeof(box[0]), cmp);

		printf("YES\n");
		cnt = 0;
		for(i = 0;i < n * 2 - 2;i += 2)
		{
			if (box[i].pear > box[i + 1].pear)
				ans[cnt++] = box[i].ind;
			else
				ans[cnt++] = box[i + 1].ind;
		}
		ans[cnt++] = box[2 * n - 2].ind;

		qsort(ans, cnt, sizeof(ans[0]), cmp2);

		printf("%d", ans[0]);
		for(i = 1;i < cnt;i++)
			printf(" %d", ans[i]);

		putchar('\n');
	}
	return 0;
}
