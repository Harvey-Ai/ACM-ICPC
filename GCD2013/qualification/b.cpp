#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int ncase;
	int m, n;
	int grass[105][105];
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(int icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &n, &m);

	
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				scanf("%d", &grass[i][j]);

		int ok = 1;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
			{
				int ok1 = 1, ok2 = 1;
				for(int k = 0;k < n;k++)
					if (grass[k][j] > grass[i][j])
						ok1 = 0;
				for(int k = 0;k < m;k++)
					if (grass[i][k] > grass[i][j])
						ok2 = 0;
				
				ok &= (ok1 | ok2);
			}
		if (ok)
			printf("Case #%d: YES\n", icase);
		else
			printf("Case #%d: NO\n", icase);
	}
	return 0;
}
