#include <iostream>
#include <algorithm>
using namespace std;

struct target
{
	int x, r;
	int ind;
}tar[10005];

int beated[10005];
int hit[200005][2];

int bs(int a, int n)
{
	int left = 0, right = n - 1;
	int mid = (left + right) / 2;

	while(left <= right)
	{
		mid = (left + right) / 2;
		if (a < tar[mid].x - tar[mid].r)
			right = mid - 1;
		else if (a > tar[mid].x + tar[mid].r)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int cmp(const target &a, const target &b)
{
	return a.x - b.x >= 0 ? 0 : 1;
}

int main()
{
	int n, m;
	int i, index;
	int res;

	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d", &tar[i].x, &tar[i].r);
		tar[i].ind = i;
	}
	//
	sort(&tar[0], &tar[n], cmp);

//	for(i = 0;i < n;i++)
	//	printf("%d %d\n", tar[i].x, tar[i].r);

	memset(beated, 0, sizeof(beated));
	scanf("%d", &m);
	for(i = 0;i < m;i++)
	{
		scanf("%d %d", &hit[i][0], &hit[i][1]);

		index = bs(hit[i][0], n);

	//	printf("%d\n", index);
		if (index != -1 && 
			(hit[i][0] - tar[index].x) * (hit[i][0] - tar[index].x) + (hit[i][1] * hit[i][1]) <= (tar[index].r * tar[index].r) &&
			beated[tar[index].ind] == 0)
			beated[tar[index].ind] = i + 1;
		if (index > 0 && 
			(hit[i][0] - tar[index - 1].x) * (hit[i][0] - tar[index - 1].x) + (hit[i][1] * hit[i][1]) <= (tar[index - 1].r * tar[index - 1].r) &&
			beated[tar[index - 1].ind] == 0)
			beated[tar[index - 1].ind] = i + 1;
		if (index != -1 && index < (n - 1) && 
			(hit[i][0] - tar[index + 1].x) * (hit[i][0] - tar[index + 1].x) + (hit[i][1] * hit[i][1]) <= (tar[index + 1].r * tar[index + 1].r) &&
			beated[tar[index + 1].ind] == 0)
			beated[tar[index + 1].ind] = i + 1;
	}

	res = 0;
	for(i = 0;i < n;i++)
		if (beated[i])
			res++;

	printf("%d\n", res);
	for(i = 0;i < n;i++)
		if (beated[i])
			printf("%d ", beated[i]);
		else
			printf("-1 ");
	return 0;
}
