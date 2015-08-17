#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	if (b > a)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	int b;
	double n;
	int com;
	int pd, pg;
	int ncase;
	int icase;

	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%lf %d %d", &n, &pd, &pg);

		b = 0;
		if ((pd == 0 && pg == 100) || ((pd < 100 && pd > 0) && (pg == 0 || pg == 100)) || (pd == 100 && pg == 0))
			b = 1;

		com = gcd(pd, 100);

		if (n < 100 / com)
			b = 1;

		if (b == 0)
			printf("Case #%d: Possible\n", icase);
		else
			printf("Case #%d: Broken\n", icase);
	}

	return 0;
}
