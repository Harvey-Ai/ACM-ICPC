#include <iostream>
using namespace std;

int main()
{
	int icase, ncase;
	int i, n;
	int xx, min, sum;
	int arr[1005];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);

		xx = 0;
		sum = 0;
		min = 1000005;
		for(i = 0;i < n;i++)
		{
			scanf("%d", &arr[i]);
			xx ^= arr[i];
			sum += arr[i];
			if (min > arr[i])
				min = arr[i];
		}

		if (xx)
			printf("Case #%d: NO\n", icase);
		else
			printf("Case #%d: %d\n", icase, sum - min);
	}
	return 0;
}
