#include <stdio.h>
#include <string.h>

char str[10000];

char delims[] = "!.?";
char *result = NULL;

int getlen(char *ss)
{
	int i;
	for(i = 0;ss[i] == ' ';i++);
	return strlen(ss + i);
}

int main()
{
	int len;
	int ll;
	int res;
	int flag;

	scanf("%d", &len);
	getchar();
	gets(str);

	res = 0;
	flag = 0;
	ll = 0;
	result = strtok(str, delims);

	while(result != NULL)
	{
		if (getlen(result) + 1 > len)
			flag = 1;
		if (ll + strlen(result) + 1 > len)
		{
			res++;
			ll = getlen(result) + 1;
		}
		else
			ll += strlen(result) + 1;
        result = strtok(NULL, delims);
    }
	res++;

	if (flag)
		printf("Impossible\n");
	else
		printf("%d\n", res);
	return 0;
}
