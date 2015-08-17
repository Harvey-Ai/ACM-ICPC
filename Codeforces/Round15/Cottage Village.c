#include <stdio.h>
#define N 1005

struct house
{
	double a, b;
};

int cmp(const void *a, const void *b)
{
	struct house *aa = (struct house *)a;
	struct house *bb = (struct house *)b;
	return aa->a - bb->a;
}
int main()
{
	int n, t;
	int x, a;
	int res;
	int i;
	struct house hos[N];
	scanf("%d %d", &n, &t);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d", &x, &a);
		hos[i].a = x - (a * 1.0 / 2);
		hos[i].b = x + (a * 1.0 / 2);
	}
	qsort(hos, n, sizeof(hos[0]), cmp);

	res = 2;
	for(i = 1;i < n;i++)
		if (hos[i].a - hos[i - 1].b > (double)t)
			res += 2;
		else if (hos[i].a - hos[i - 1].b == (double)t)
			res++;
	printf("%d\n", res);
	return 0;
}
