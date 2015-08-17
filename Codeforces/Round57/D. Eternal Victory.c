#include <stdio.h>
#include <string.h>
#include <malloc.h>

long long max;
int visited[100005];

struct node
{
	int b, w;
	struct node *next;
};

struct ee
{
	struct node *first, *last;
}edge[100005];

void add(int a, int b, int w)
{
	struct node *temp;
	if (edge[a].first == NULL)
	{
		edge[a].first = (struct node *)malloc(sizeof(struct node));
		edge[a].first->b = b;
		edge[a].first->w = w;
		edge[a].first->next = NULL;
		edge[a].last = edge[a].first;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		edge[a].last->next = temp;
		temp->b = b;
		temp->w = w;
		temp->next = NULL;
		edge[a].last = temp;
	}
}


void dfs(int kk, long long res)
{
	struct node *temp;
	if (res > max)
		max = res;
	visited[kk] = 1;
	for(temp = edge[kk].first;temp != NULL;temp = temp->next)
	{
		if (visited[temp->b] == 0)
			dfs(temp->b, res + temp->w);
	}
	visited[kk] = 0;
}

int main()
{
	int n, i;
	int a, b, w;
	long long sum;
	struct node *temp;
	scanf("%d", &n);

	sum = 0;
	for(i = 0;i < n - 1;i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		sum += w;
		add(a, b, w);
		add(b, a, w);
	}
	sum *= 2;

	max = 0;
	memset(visited, 0, sizeof(visited));

	dfs(1, 0);
//	printf("%lld\n", max);
	printf("%lld\n", sum - max);
	return 0;
}

