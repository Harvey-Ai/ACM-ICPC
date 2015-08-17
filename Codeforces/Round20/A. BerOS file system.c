#include <stdio.h>
#define MAXL 105

int main()
{
	int i, j;
	char str[MAXL];
	char res[MAXL];

	scanf("%s", str);

	res[0] = str[0];
	j = 1;
	for(i = 1; str[i] != '\0';i++)
		if (str[i] == '/')
		{
			if (res[j - 1] != '/')
				res[j++] = str[i];
		}
		else
			res[j++] = str[i];
	while(j > 1 && res[j - 1] == '/')
		j--;
	res[j] = '\0';
	printf("%s\n", res);
	return 0;
}

