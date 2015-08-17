#include <stdio.h>

int main()
{
	char source[105];
	int i;
	int li, bi;
	li = bi = 0;
	scanf("%s", source);
	for(i = 0;source[i] != '\0';i++)
		if (source[i] >= 'a' && source[i] <= 'z')
			li++;
		else
			bi++;
	if (li >= bi)
	{
		for(i = 0;source[i] != '\0';i++)
			if (source[i] < 'a' || source[i] > 'z')
				source[i] = 'a' + source[i] - 'A';
	}
	else
	{
		for(i = 0;source[i] != '\0';i++)
			if (source[i] >= 'a' && source[i] <= 'z')
				source[i] = 'A' + source[i] - 'a';
	}
	printf("%s\n", source);

	return 0;
}
