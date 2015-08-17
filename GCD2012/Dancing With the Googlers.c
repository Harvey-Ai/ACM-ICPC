#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int i;
	int icase, ncase;
	int n, s, p;
	int arr[1000];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d", &n, &s, &p);

		int res = 0;
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		for(i = 0;i < n;i++)
		{
			a = arr[i] / 3;
			int left = arr[i] - a * 3;
			if (left == 1)
			{
				if (a + 1 >= p)
					res++;
			}
			else if (left == 2)
			{
				if (a + 1 >= p)
					res++;
				else if (a + 2 >= p && s)
				{
					
					s--;
					res++;
				}
			}
			else if (left == 0)
			{
				if (a >= p)
					res++;
				else if (a + 1 >= p && s && a - 1 >= 0)
				{
					s--;
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", icase, res);
	}
	return 0;
}
