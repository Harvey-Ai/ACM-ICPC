#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 1000000005;
int resx, resy, res;

int rev(int num)
{
	int temp = num;
	int num2 = 0;
	while(temp)
	{
		num2 *= 10;
		num2 += temp % 10;
		temp /= 10;
	}
	return num2;
}

pair<int, int> pp(int a, int b)
{
	int g = __gcd(a, b);
	return make_pair(a / g, b / g);
}

void work(int x, int y, int c)
{
	int i, j;
	int luck = 0;

	resx = resy = -1;
	map <pair <int , int >, int> mx, my;
	mx.clear();
	my.clear();

	for(j = 1;j <= y;j++)
		my[pp(j, rev(j))]++;

	for(i = 1, j = y;i <= x && j >= 1;i++)
	{
		mx[pp(i, rev(i))]++;
		luck += my[pp(rev(i), i)];

		while(j >= 1 && luck - mx[pp(rev(j), j)] >= c)
		{
			luck -= mx[pp(rev(j), j)];
			my[pp(j, rev(j))]--;
			j--;
		}

		if (luck >= c && (resx == -1 || i * j <= resx * resy))
		{
			resx = i;
			resy = j;
		}
	}
}

int main()
{
	int maxX, maxY, w;

	scanf("%d %d %d", &maxX, &maxY, &w);
	work(maxX, maxY, w);

	if (resx > 0 && resy > 0)
		printf("%d %d\n", resx, resy);
	else
		printf("-1\n");
	return 0;
}
