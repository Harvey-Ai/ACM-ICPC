#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int d, len, q;
	int i, j, k, l;
	char str[5005][20];
	int bit[20][26];
	char ma[20000];
	int res;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d %d %d", &len, &d, &q);

	for(i = 0;i < d;i++)
		scanf("%s", str[i]);

	for(i = 0;i < q;i++)
	{
		scanf("%s", ma);

		memset(bit, 0, sizeof(bit));
		for(j = 0, l = 0;ma[j] != '\0';j++)
		{
			if (ma[j] == '(')
			{
				for(j = j + 1;ma[j] != ')';j++)
					bit[l][ma[j] - 'a'] = 1;
			}
			else
				bit[l][ma[j] - 'a'] = 1;
			l++;
		}
		res = 0;
		for(j = 0;j < d;j++)
		{
			for(k = 0;k < len;k++)
				if (bit[k][str[j][k] - 'a'] != 1)
					break;
			if (k >= len)
				res++;
		}
		printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}
