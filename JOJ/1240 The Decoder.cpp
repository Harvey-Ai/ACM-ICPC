#include <stdio.h>
int main()
{
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
		{
			printf("%c",c);
			continue;
		}
		if(c<=38)
			printf("%c",c+88);
		else
			printf("%c",c-7);
	}
	return 0;
}