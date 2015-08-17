#include <stdio.h>

int main()
{
	int i;
	char matrix[4][4];

	for(i = 0;i < 3;i++)
		scanf("%s",matrix[i]);

	for(i = 0;i < 3;i++)
		if (matrix[0][i] != matrix[2][2 - i])
		{
			printf("NO\n");
			return 0;
		}
	if (matrix[1][0] != matrix[1][2])
	{
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	return 0;
}
