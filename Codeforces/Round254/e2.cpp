#include <stdio.h>
#include <stdlib.h>

#define N 100005
#define typev long long // type of res

int m, n;
typev ar[N]; // index: 1 ~ N

int lowb(int t) { return t & (-t) ; }
void add(int i, typev v) {
	for ( ; i <= n; ar[i] += v, i += lowb(i));
}
typev sum(int i) {
	typev s = 0;
	for ( ; i > 0; s += ar[i], i -= lowb(i));
	return s;
}

int color[N];
int main()
{
	scanf("%d %d", &n, &m);
	int i, j;
	for(i = 1;i <= n;i++)
		color[i] = i;
	ar[0] = 0;	
	for(i = 0;i < m;i++)
	{
		int qType;
		int l, r;
		scanf("%d", &qType);
		if (qType == 1)
		{
			long long x;
			scanf("%d %d", &l, &r);
			scanf("%lld", &x);
			for(j = l;j <= r;j++)
			{
				long long c = abs(x - color[j]);
				add(j, c);
				color[j] = x;
			}
		}
		else
		{
			scanf("%d %d", &l, &r);
			long long colorness = sum(r) - sum(l - 1);
			printf("%I64d\n", colorness);
		}
	}
	return 0;
}
