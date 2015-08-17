#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1005

struct sg
{
	int bg, ed;
}seg[N];

int cmp(const void *a, const void *b)
{
	struct sg *aa = (struct sg *)a;
	struct sg *bb = (struct sg *)b;
	return aa->ed - bb->ed;
}

int main()
{
	int n;
	int i, j;
	int res;
	int x;
	int temp;
	int nailed[N];
	int ans[N];
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d", &seg[i].bg, &seg[i].ed);
		if (seg[i].bg > seg[i].ed)
		{
			temp = seg[i].bg;
			seg[i].bg = seg[i].ed;
			seg[i].ed = temp;
		}
	}
	qsort(seg, n, sizeof(seg[0]), cmp);
	memset(nailed, 0, sizeof(nailed));

	res = 0;
	for(i = 0;i < n;i++)
		if (!nailed[i])
		{
		//	printf("%d\n", i);
			x = seg[i].ed;
			for(j = i + 1;j < n;j++)
				if (seg[j].bg <= x)
					nailed[j] = 1;
				else
					break;
		//	printf("%d\n", j);
			ans[res] = x;
			res++;
		}
	printf("%d\n", res);
	for(i = 0;i < res;i++)
		printf("%d ", ans[i]);
	return 0;
}
