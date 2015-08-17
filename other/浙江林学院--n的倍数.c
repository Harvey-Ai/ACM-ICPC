#include <stdio.h>
#include <string.h>
#define N 10005

struct node
{
	char c;
	int sum;
	int pre;
};

struct node stack[N];
int flag[N];
int main()
{
	int i, n, sum, pre, last;
	char res[N];
	while(scanf("%d", &n) != EOF)
	{
		if (n < 0)
			n = -n;
		if (n == 0)
		{
			printf("0\n");
			continue;
		}

		memset(flag, 0, sizeof(flag));
		stack[0].c = '1';
		stack[0].sum = 1 % n;
		stack[0].pre= -1;

		flag[stack[0].sum] = 1;
		pre = 0;
		last = 1;
		while(pre < last)
		{
			if (stack[pre]. sum == 0)
				break;
			else
			{
				sum = (stack[pre].sum * 10 ) % n;
				if (!flag[sum])
				{
					stack[last].c = '0';
					stack[last].sum = sum;
					stack[last++].pre = pre;
					flag[sum] = 1;
				}

				sum = (stack[pre].sum * 10 + 1) % n;
				if (!flag[sum])
				{
					stack[last].c = '1';
					stack[last].sum = sum;
					stack[last++].pre = pre;
					flag[sum] = 1;
				}
			}
			pre++;
		}

		for(i = 0;stack[pre].pre != -1;i++)
		{
			res[i] = stack[pre].c;
			pre = stack[pre].pre;
		}

		putchar('1');
		while(i--)
			putchar(res[i]);
		putchar('\n');
	}
	return 0;
}
