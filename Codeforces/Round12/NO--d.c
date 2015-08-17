#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 500005

struct women
{
	int a, b, c;
};

struct node
{
	int a, b, c;
	struct node *next;
};

struct women arr[N];

struct node *newNode(int a, int b, int c)
{
	struct node *head = (struct node *)malloc(sizeof(struct node));

	head->a = a;
	head->b = b;
	head->c = c;
	head->next = NULL;
}

int main()
{
	int i, j, n, res, temp;
	struct node *head, *listNode, *pre;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i].a);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i].b);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i].c);

	res = 0;
	head = newNode(0, 0, 0);

	for(i = 0;i < n;i++)
	{
		for(listNode = head->next;listNode != NULL;listNode = listNode->next)
			if (arr[i].a < listNode->a && arr[i].b < listNode->b && arr[i].c < listNode->c)
				break;
		if (listNode != NULL)
			res++;
		else
		{
			for(listNode = head->next, pre = head;listNode != NULL;)
			{
				if (arr[i].a > listNode->a && arr[i].b > listNode->b && arr[i].c > listNode->c)
				{
					res++;
					listNode = listNode->next;
					free(pre->next);
					pre->next = listNode;
				}
				else
				{
					listNode = listNode->next;
					pre = pre->next;
				}
			}

			listNode = newNode(arr[i].a, arr[i].b, arr[i].c);
			listNode->next = head->next;
			head->next = listNode;
		}
	}
	free(head);

	printf("%d\n", res);
	return 0;
}
