#include <stdio.h>
#include <string.h>

char name[100][100];
int isIn[100];

int main()
{
	int i, p, a, b, num, n;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%s", name[i]);
	scanf("%d,%d", &a, &b);

	memset(isIn, 0, sizeof(isIn));

	for(i = 0, p = a - 1;i < n;i++)
	{
		for(num = 0;;p++)
		{
			if (p >= n)
				p -= n;
			if (isIn[p] == 0)
				num++;
			if (num >= b)
				break;
		}
		isIn[p] = 1;
		printf("%s\n", name[p]);
		p++;
	}
	return 0;
}
