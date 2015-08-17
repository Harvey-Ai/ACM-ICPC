#include <stdio.h>

int main()
{
	char str1[105], str2[105], res[105];
	int i;
	int temp;

	while(scanf("%s %s", str1, str2) != EOF)
	{
		for(i = 0;str1[i] != '\0';i++)
		{
			temp = str1[i] + str2[i] - '0' -'0';
			if (temp == 1)
				res[i] = '1';
			else
				res[i] = '0';
		}
		res[i] = '\0';
		printf("%s\n", res);
	}
	return 0;
}
