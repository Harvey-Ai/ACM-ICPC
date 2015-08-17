#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cc
{
	int ind, prio;
	char name[15];
}crew[105];


int cmp(const void *a, const void *b)
{
	struct cc *aa = (struct cc *)a;
	struct cc *bb = (struct cc *)b;

	if (aa->prio != bb->prio)
		return aa->prio - bb->prio;
	else
		return aa->ind - bb->ind;
}

int main()
{
	int i;
	int n;
	char tp[10];
	scanf("%d", &n);

	for(i = 0;i < n;i++)
	{
		scanf("%s %s", crew[i].name, tp);
		crew[i].ind = i;
		if (strcmp(tp, "captain") == 0)
			crew[i].prio = 4;
		else if (strcmp(tp, "man") == 0)
			crew[i].prio = 3;
		else if (strcmp(tp, "woman") == 0 || strcmp(tp, "child") == 0)
			crew[i].prio = 2;
		else if (strcmp(tp, "rat") == 0)
			crew[i].prio = 1;
	}

	qsort(crew, n, sizeof(crew[0]), cmp);

	for(i = 0;i < n;i++)
		printf("%s\n", crew[i].name);
	return 0;
}
