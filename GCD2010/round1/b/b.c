#include <stdio.h>
#include <stdlib.h>

#define N 105

struct chick
{
	int location, sp;
	int can;
};

int main()
{
	struct chick ch[N];
	int i;
	int res;
	int n, k, b, t;
	int cnt;
	int ncase, icase;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d %d", &n, &k, &b, &t);
		for(i = 0;i < n;i++)
			scanf("%d", &ch[i].location);
		for(i = 0;i < n;i++)
			scanf("%d", &ch[i].sp);

		cnt = 0;
		for(i = 0;i < n;i++)
		{
			if (ch[i].sp == 0 || (((b - ch[i].location) + ch[i].sp - 1)/ ch[i].sp) > t)
				ch[i].can = 0;
			else
			{
				ch[i].can = 1;
				cnt++;
			}
		}
		if (cnt < k)
		{
			printf("Case #%d: IMPOSSIBLE\n", icase);
			continue;
		}

		for(i = 0;i < n && cnt > k;i++)
			if(ch[i].can)
				cnt--;
		res = 0;
		while(i < n)
		{
			if (ch[i].can)
			{
				res += n - i - cnt;
				cnt--;
			}
			i++;
		}
		printf("Case #%d: %d\n", icase, res);
	}
	return 0;
}
