#include <stdio.h>

mm[10] = {1, 5, 10, 50, 100, 500, 1000};
mmc[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int main()
{
	int a, cc;
	char c[10];
	int base1, base2;
	scanf("%d ", a);
	scanf("%s", c);
	if (c[0] == 'R')
		roman = 1;
	else
		base1 = convert(c);
	
	scanf("%s", num);
	for(i = 0;num[i] != '\0';i++)
	{
		res *= base1;
		res += (num[i] - '0');
	}

	if (roman == 0)
	{
		len = 0;
		while(res)
		{
			ans[len++] = res % base2 + '0';
			res / =base2;
		}
		ans[len] = '\0';
	}
	else
	{
		len = 0;
		p = 6;
		while(res)
		{
			while(res < mm[p])
				p--;
			ans[len++] = mmc[p];
			res /= mm[p];
		}
		ans[len]
	}
		


	}
	
}
