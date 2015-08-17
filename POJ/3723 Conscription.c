#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20005
int set[N];

struct edge
{
	int x, y;
	int cost;
}e[50005];

int cmp(const void *a, const void *b)
{
	struct edge *aa = (struct edge *)a;
	struct edge *bb = (struct edge *)b;
	return aa->cost - bb->cost;
}

/* init the set. all will be set a value -1 */
void makeSet()
{
	memset(set, -1, sizeof(set));
}

/* find operation. return the id's root num */
int getF(int id)
{
	int father = id;
	int temp = id;
	while(set[father] >= 0)
		father = set[father];

	while(set[id] >= 0)
	{
		temp = set[id];
		set[id] = father;
		id =temp;
	}
	return father;
}

/* union operation. union the sets who containt element id1, id2 */
int Union(int id1, int id2)
{
	int fA, fB;
	fA = getF(id1);
	fB = getF(id2);

	if (fA == fB)
		return 0;
	if (set[fA] < set[fB])
	{
		set[fA] += set[fB];
		set[fB] = fA;
	}
	else
	{
		set[fB] += set[fA];
		set[fA] = fB;
	}
	return 1;
}

int kruskal(int m, int n)
{
	qsort(e, m, sizeof(e[0]), cmp);
	int w = n;
	int i;
	int ans = 0;
	makeSet();
	for(i = 0;i < m;i++)
		if (Union(e[i].x, e[i].y))
		{
			w--;
			ans += e[i].cost;
		}
	return ans + 10000 * w;

}

int main()
{
	int ncase;
	int res;
	int i, m, n, r, a, b, c;
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d %d %d", &m, &n, &r);
		for(i = 0;i < r;i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			e[i].x = a;
			e[i].y = b + m;
			e[i].cost = 10000 - c;
		}
		res = kruskal(r, m + n);
		printf("%d\n", res);

	}
	return 0;
}
