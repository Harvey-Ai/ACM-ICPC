#include <stdio.h>
#include <stdlib.h>

struct ch
{
	int l;
	int v;
}ch[105];

int cmp(const void *a, const void *b)
{
	struct ch *aa = (struct ch *)a;
	struct ch *bb = (struct ch *)b;
	return bb->l - aa->l;
}

int main()
{
	int ncase;
	int n, k, b, t;
	int i;
	int passNum, pickNum;
	int icase;
	int res;

	int l[101], v[101];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d %d", &n, &k, &b, &t);

		for(i = 0;i < n;i++)
			scanf("%d", &ch[i].l);

		for(i = 0;i < n;i++)
			scanf("%d", &ch[i].v);

		qsort(ch, n, sizeof(ch[0]), cmp);

		pickNum = 0;
		passNum = 0;
		res = 0;
		for(i = 0;i < n;i++)
		{
			if (passNum >= k)
				break;

			if (b - ch[i].l > t * ch[i].v)
				pickNum++;
			else
			{
				passNum++;
				res += pickNum;
			}
		}
		if (passNum >= k)
			printf("Case #%d: %d\n", icase, res);
		else
			printf("Case #%d: IMPOSSIBLE\n", icase);
	}
	return 0;
}
