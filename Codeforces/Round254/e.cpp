#include <stdio.h>
#include <stdlib.h>

#define N 100005
#define typev long long // type of res

int m, n;
typev ar[N]; // index: 1 ~ N
int lowBit[N];

void add(int i, typev v) {
	for ( ; i <= n; ar[i] += v, i += lowBit[i]);
}
typev sum(int i) {
	typev s = 0;
	for ( ; i > 0; s += ar[i], i -= lowBit[i]);
	return s;
}

int color[N];
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n;i++)
		lowBit[i] = i & (-i);
	for(i = 1;i <= n;i++)
		color[i] = i;
	ar[0] = 0;	
	for(i = 0;i < m;i++)
	{
		int qType;
		int l, r, x;
		scanf("%d", &qType);
		if (qType == 1)
		{
			scanf("%d %d %d", &l, &r, &x);
			for(j = l;j <= r;j++)
			{
				add(j, abs(color[j] - x));
				color[j] = x;
			}
		}
		else
		{
			scanf("%d %d", &l, &r);
			printf("%I64d\n", sum(r) - sum(l - 1));
		}
	}
	return 0;
}
