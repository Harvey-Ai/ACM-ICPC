#include <stdio.h>
#define N 1005

long long loader[N];
int next[N];
int group[N];
int main()
{
	int ncase;
	int i, j;
	int r, k, n;
	int pos, ab;
	long long res;
	int cc;
//	freopen("1.txt","r", stdin);
//	freopen("2.txt","w", stdout);
	scanf("%d", &ncase);

	for(cc = 0;cc < ncase;cc++)
	{
		scanf("%d %d %d", &r, &k, &n);
		for(i = 0;i < n;i++)
			scanf("%d", &group[i]);

		for(i = 0;i < n;i++)
			loader[i] = next[i] = -1;
		pos = 0;
		res = 0;
		for(i = 0;i < r;i++)
		{
			if (loader[pos] == -1)
			{
				ab = group[pos];
				if (ab <= k)
				{
					for(j = pos + 1;j % n != pos;j++)
					{
						if (ab + group[j % n] <= k)
							ab += group[j % n];
						else
							break;
					}
					loader[pos] = ab;
					next[pos] = j % n;
				}
				else
				{
					loader[pos] = 0;
					next[pos] = pos;
				}
			}
			res += loader[pos];
			pos = next[pos];
		}

		printf("Case #%d: %lld\n", cc + 1, res);
	}
	return 0;
}
