#include <iostream>
using namespace std;

int flag[10000005];
int ff[10000005];

int rotate(int a)
{
	if (a < 10)
		return a;

	int b = a % 10;
	a = a / 10;
	
	int c = 1;
	while(c <= a)
		c *= 10;
	a = a + b * c;
	return a;
}


int init()
{
	memset(flag, 0, sizeof(flag));
	int i;
	for(i = 1;i < 2000005;i++)
	{
		int a = i;
		while (!flag[a])
		{
			int b = rotate(a);
			flag[a] = b;
			if (b == i)
				break;
			a = b;
		}
	}
}

int main()
{
	//freopen("1.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	
	int res;
	int icase, ncase;
	int i, aa, bb;

	init();
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &aa, &bb);
		memset(ff, 0, sizeof(ff));

		res = 0;
		for(i = aa;i <= bb;i++)
		{
			if (!ff[i])
			{
				int sum = 1;
				int a = flag[i];
				ff[i] = 1;
				while(!ff[a])
				{
					if (a >= aa && a <= bb)
						sum++;
					ff[a] = 1;
					a = flag[a];
				}
				res += (sum * (sum - 1)) / 2;
			}
		}
		printf("Case #%d: %d\n", icase, res);
	}
	return 0;
}
