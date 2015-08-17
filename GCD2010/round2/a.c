#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[150][150];
int check(int midI, int midJ, int n)
{
	int i, j;
	int temp[5];
	int num;
	int k;

	for(i = 0;i < 2 * n - 1;i++)
		for(j = 0;j < 2 * n - 1;j++)
		{
			num = 0;
			if (arr[i][j] != -1)
				temp[num++] = arr[i][j];
			if ((2 * midI - i) < 2 * n - 1 && (2 * midI - i) >= 0 && arr[2 * midI - i][j] != -1)
				temp[num++] = arr[2 * midI - i][j];
			if ((2 * midJ - j) < 2 * n - 1 && (2 * midJ - j) >= 0 && arr[i][2 * midJ - j] != -1)
				temp[num++] = arr[i][2 * midJ - j];
			if ((2 * midI - i) < 2 * n - 1 && (2 * midI - i) >= 0 && (2 * midJ - j) >= 0 && (2 * midJ - j) < 2 * n - 1 && arr[2 * midI - i][2 * midJ - j] != -1)
				temp[num++] = arr[2 * midI - i][2 * midJ - j];
			sort(&temp[0], &temp[num]);
			for(k = 1;k < num;k++)
				if (temp[k] != temp[0])
					return 0;
		}
	return 1;
}
int main()
{
	int ncase;
	int n;
	int head, num;
	int icase;
	int i, j;
	int min;
	int ll;
	
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);

		for(i = 0;i < 2 * n - 1;i++)
		{
			head = abs(n - 1 - i);
			num = n - abs(n - 1 - i);
			for(j = 0;j < head;j++)
				arr[i][j] = -1;
			scanf("%d", &arr[i][head]);
			num--;
			for(j = head + 1;num > 0;j++)
			{
				arr[i][j] = -1;
				scanf("%d", &arr[i][++j]);
				num--;
			}
			for(;j < 2 * n - 1;j++)
				arr[i][j] = -1;
		}

		min = 100000000;
		for(i = 0;i < 2 * n - 1;i++)
			for(j = 0;j < 2 * n - 1;j++)
			{
				if (check(i, j, n))
				{
					ll = j + abs(n - 1 - i);
					if (abs(n - 1 - i) + 2 * n - 2 - j > ll)
						ll = abs(n - 1 - i) + 2 * n - 2 - j;
					if (ll <  i + abs(n - 1 - j))
						ll =  i + abs(n - 1 - j);
					if (ll < abs(n - 1 - j) + 2 * n - 2 - i)
						ll = abs(n - 1 - j) + 2 * n - 2 - i;
					if (ll * 2 + 1 < min)
					{
						min = ll * 2 + 1;
					}
				
				}
			}
		min = (min + 1) / 2;
		min =  min * min - n * n;
		printf("Case #%d: %d\n", icase, min);
	}
	return 0;
}
