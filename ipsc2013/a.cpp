#include <iostream>
#include <cstdio>
using namespace std;

int den[20] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int ncase;
	int res[20];
	scanf("%d", &ncase);
	//cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		int e, c;
		scanf("%d %d", &e, &c);
		//cin >> e >> c;

		int money = e * 100 + c;

		for(int i = 0;i < 13;i++)
		{
			res[i] = money / den[i];
			money = money % den[i];
		}
		for(int i = 12;i >= 0;i--)
			printf("%d ", res[i]);
		putchar('\n');
	}
	return 0;
}
