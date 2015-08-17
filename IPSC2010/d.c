#include <stdio.h>
#include <math.h>

int gcd(int x, int y)
{
	int t;
	if (!x || !y) return x>y?x:y;//存在0，则返回较大数
	for (t; t=x%y; x=y, y=t);
	return y;
}

void extgcd(int a,int b,int *d,int *x,int *y)
{
	if(b)
	{	
	*d=a;	*x=1;	*y=0;
	}
	else
	{
	extgcd(b,a%b,d,y,x);
		(*y)-=(*x)*(a/b);
	}
}

int check(int a, int b, int c, int flag1, int flag2)
{
	int x, y;
	int tempx, tempy;

	extgcd(a,b,&c,&x,&y);

	tempx = x;
	tempy = y;
	if ((tempx <= 0 && flag1 < 0 || tempx >= 0 && flag1 > 0)  && (tempy <= 0 && flag2 < 0 || tempy >= 0 && flag2 > 0))
		return 1;

	while(1)
	{
		tempx -= b;
		tempy += a;
		if ((tempx <= 0 && flag1 < 0 || tempx >= 0 && flag1 > 0)  && (tempy <= 0 && flag2 < 0 || tempy >= 0 && flag2 > 0))
			return 1;
		if (tempx < 0 && tempy > 0)
			break;
	}

	tempx = x;
	tempy = y;
	while(1)
	{
		tempx += b;
		tempy -= a;
		if ((tempx <= 0 && flag1 < 0 || tempx >= 0 && flag1 > 0)  && (tempy <= 0 && flag2 < 0 || tempy >= 0 && flag2 > 0))
			return 1;
		if (tempx > 0 && tempy < 0)
			break;
	}
	return 0;
}

int main()
{
	int flag;
	int N, c1, g1, c2, g2;
	int gg, d1, d2;
	int ncase;
	int flag1, flag2;
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d %d %d %d %d", &N, &c1, &g1, &c2, &g2);

		if (N == 0)
		{
			printf("PRINCE\n");
			continue;
		}
		if (N < c1 - 1 && N < c2 - 1)
		{
			printf("DRAGON\n");
			continue;
		}
		if (c1 - g1 <= 0 && c2 - g2 <= 0)
		{
			d1 = abs(c1 - g1);
			d2 = abs(c2 - g2);
			gg = gcd(d1, d2);

			if ((N <= c1 && (c1 - N) % gg == 0 && check(d1, d2, c1 - N, 1, 1)) ||
				(N <= c2 && (c2 - N) % gg == 0 && check(d1, d2, c2 - N, 1, 1)))
				printf("DRAW\n");
			else
				printf("DRAGON\n");
			continue;
		}
		if (c1 - g1 == 0)
		{
			if (c2 - g2 > 0)
			{
				if (((N + g2) % (c2 - g2) == 0 && N >= c2) ||
					((N - c1) % (c2 - g2) == 0 && N >= c1))
					printf("PRINCE\n");
				else if (((N - c1 + 1) % (c2 - g2) == 0 && N >= c1 - 1) ||
						((N - c2 + 1) % (c2 - g2) == 0 && N >= c2 - 1))
					printf("DRAW\n");
				else
					printf("DRAGON\n");

			}
			else
			{
				if (N == c1 - 1 || N == c2 - 1)
					printf("DRAW\n");
				else
					printf("DRAGON\n");
			}	
			continue;
		}
		if (c2 - g2 == 0)
		{
			if (c1 - g1 > 0)
			{
				if (((N + g1) % (c1 - g1) == 0 && N >= c1) ||
					(N - c2) % (c1 - g1) == 0 && N >= c2)
					printf("PRINCE\n");
				else if (((N - c1 + 1) % (c1 - g1) == 0 && N >= c1 - 1) ||
						((N - c2 + 1) % (c1 - g1) == 0 && N >= c2 - 1))
					printf("DRAW\n");
				else
					printf("DRAGON\n");
			}
			else
			{
				if (N == c1 - 1 || N == c2 - 1)
					printf("DRAW\n");
				else
					printf("DRAGON\n");
			}
			continue;
		}
		d1 = abs(c1 - g1);
		d2 = abs(c2 - g2);
		if (c1 - g1 < 0)
			flag1 = -1;
		else
			flag1 = 1;
		if (c2 - g2 < 0)
			flag2 = -1;
		else
			flag2 = 1;

		flag = -1;
		gg = gcd(d1, d2);

		if (((N + g1) % gg == 0 && check(d1, d2, N + g1, flag1, flag2) && N >= c1 && flag1 > 0) ||
			 ((N + g2) % gg == 0 && check(d1, d2, N + g1, flag1, flag2) && N >= c2 && flag2 > 0))
			flag = 1;
		else if ((N >= c1 - 1 && (N - c1 + 1) % gg && check(d1, d2, N - c1 + 1, flag1, flag2)) ||
				(N >= c2 - 1 && (N - c2 + 1) % gg && check(d1, d2, N - c2 + 1, flag1, flag2)))
			flag = 2;
		else
			flag = 3;

		switch(flag)
		{
			case 1:
				printf("PRINCE\n");
				break;
			case 2:
				printf("DRAW\n");
				break;
			case 3:
				printf("DRAGON\n");
				break;
			default:
				break;
		}
	}
	return 0;
}
