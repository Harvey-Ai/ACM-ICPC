#include <stdio.h>

int main()
{
	int i;
	int subLen, len;
	char str[500];
	scanf("%s", str);

	len = 0;
	for(i = 0;str[i] != '\0' && str[i] != '@';i++)
	{
		if (!((str[i] >='a' && str[i] <= 'z') ||
			(str[i] >='A' && str[i] <= 'Z') ||
			(str[i] >='0' && str[i] <= '9') ||
			str[i] =='_'))
			break;
		len++;
	}
	if (str[i] != '@' || len < 1 || len > 16)
	{
		printf("NO\n");
		return 0;
	}
	else
		i++;

	len = 0;
	while(1)
	{
		subLen = 0;
		for(;str[i] != '\0' && str[i] != '.' && str[i] != '/';i++)
		{
			if (!((str[i] >='a' && str[i] <= 'z') ||
				(str[i] >='A' && str[i] <= 'Z') ||
				(str[i] >='0' && str[i] <= '9') ||
				str[i] =='_'))
				break;
			subLen++;
		}
		if (subLen < 1 || subLen > 16 ||
			!(str[i] == '\0' || str[i] == '.' || str[i] == '/'))
		{
			printf("NO\n");
			return 0;
		}
		if  (str[i] =='/' || str[i] == '\0')
		{
			len += subLen;
			break;
		}
		else
			i++;
		len += subLen + 1;
	}
	if (len < 1 || len > 32)
	{
		printf("NO\n");
		return 0;
	}

	if (str[i] == '\0')
	{
		printf("YES\n");
		return 0;
	}
	else
		i++;

	len = 0;
	for(;str[i] != '\0';i++)
	{
		if (!((str[i] >='a' && str[i] <= 'z') ||
			(str[i] >='A' && str[i] <= 'Z') ||
			(str[i] >='0' && str[i] <= '9') ||
			str[i] =='_'))
			break;
		len++;
	}
	if (str[i] != '\0' || len < 1 || len > 16)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
