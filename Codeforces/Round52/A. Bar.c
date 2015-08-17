#include <stdio.h>
#include <string.h>

char acl[30][30] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int nu(char s[])
{
	int i;
	int res = 0;
	for(i = 0;s[i] != '\0';i++)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int main()
{
	int i, j, n;
	int num;
	char ss[150];
	int res;
	scanf("%d", &n);

	res = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%s", ss);
		if (ss[0] >= '0' && ss[0] <= '9')
		{
			num = nu(ss);
			if (num < 18)
				res++;
		}
		else
		{
			for(j = 0;j < 11;j++)
				if (strcmp(ss, acl[j]) == 0)
				{
					res++;
					break;
				}
		}
	}
	printf("%d\n", res);
	return 0;
}
