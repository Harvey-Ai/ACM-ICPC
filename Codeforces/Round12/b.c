#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	char aa = *((char *)a);
	char bb = *((char *)b);
	return aa > bb ? 1 : -1;
}

int main()
{
	int pos, len;
	char temp;
	char str1[20], str2[20];
	scanf("%s %s", str1, str2);

	len = strlen(str1);
	qsort(str1, len, sizeof(str1[0]), cmp);

	for(pos = 0;str1[pos] == '0' && str1[pos] != '\0';pos++);

	if (str1[pos] != '\0')
	{
		temp = str1[0];
		str1[0] = str1[pos];
		str1[pos] = temp;
	}

	if (strcmp(str1, str2) == 0)
		printf("OK\n");
	else
		printf("WRONG_ANSWER\n");

	return 0;
}
