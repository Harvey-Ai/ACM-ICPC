/*
Description

Windy has a country, and he wants to build an army to protect his country. He has picked up N girls and M boys and wants to collect them to be his soldiers. To collect a soldier without any privilege, he must pay 10000 RMB. There are some relationships between girls and boys and Windy can use these relationships to reduce his cost. If girl x and boy y have a relationship d and one of them has been collected, Windy can collect the other one with 10000-d RMB. Now given all the relationships between girls and boys, your assignment is to find the least amount of money Windy has to pay. Notice that only one relationship can be used when collecting one soldier.

Input

The first line of input is the number of test case.
The first line of each test case contains three integers, N, M and R.
Then R lines followed, each contains three integers xi, yi and di.
There is a blank line before each test case.

1 ≤ N, M ≤ 10000
0 ≤ R ≤ 50,000
0 ≤ xi < N
0 ≤ yi < M
0 < di < 10000

Output

For each test case output the answer in a single line.
Sample Input

2

5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

5 5 10
2 4 9820
3 2 6236
3 1 8864
2 4 8326
2 0 5156
2 0 1463
4 1 2439
0 4 4373
3 4 8889
2 4 3133
Sample Output

71071
54223

*/


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
