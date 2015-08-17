#include <stdio.h>
#include <string.h>

char *num[] = {"127", "128", "32767", "32768", "2147483647", "2147483648", "9223372036854775807", "9223372036854775808"};

int main()
{
	int i;
	int flag;
	char str[105];

	scanf("%s", str);
	if (str[0] == '-')
	{
		for(i = 0;str[i] != '\0';i++)
			str[i] = str[i + 1];
		flag = -1;
	}
	else
		flag = 1;
	
	if ((strlen(str) == 19 && (strcmp(str, num[7]) > 0 || strcmp(str, num[6]) > 0 && flag == 1))|| strlen(str) > 19)
		printf("BigInteger\n");
	else if ((strlen(str) == 10 && (strcmp(str, num[5]) > 0 || strcmp(str, num[4]) > 0 && flag == 1)) || strlen(str) > 10)
		printf("long\n");
	else if ((strlen(str) == 5 && (strcmp(str, num[3]) > 0 || strcmp(str, num[2]) > 0 && flag == 1)) || strlen(str) > 5)
		printf("int\n");
	else if ((strlen(str) == 3 && (strcmp(str, num[1]) > 0 || strcmp(str, num[0]) > 0 && flag == 1)) || strlen(str) > 3)
		printf("short\n");
	else
		printf("byte\n");
	return 0;

}
