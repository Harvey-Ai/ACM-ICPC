#include <stdio.h>

struct animal
{
	int a;
	int ind;
}anm[100005];

int cmp(const animal &a, const animal &b)
{
	return (a.a > b.a) ? 1 : 0;
}

int main()
{
	long long k;
	int n;
	scanf("%d %I64d", &n, &k);

	for(i = 0;i < n;i++)
	{
		scanf("%d", &anm[i].a);
		anm[i].ind = i;
	}
	sort(&arr[0], &arr[n], cmp);

	left = k;
	for(i = n - 1;i >= 0;i++)
	{
		if (left - arr[i].a < 0)
			break;
	}
	if (i < 0)
		printf("-1\n");
	else
	{
		head = i;
		for(j = 0;j < n;j++)
			if (
		num = n - i;
		head = left % num + i;
		printf("%d", n - i);
		for(i = head;

}
