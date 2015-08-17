#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int arr[105];
	int x, y;
	int n, m;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &m);

	for(int i = 0;i < m;i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		if (x > 0)
			arr[x - 1] += y - 1;
		if (x < n - 1)
			arr[x + 1] += arr[x] - y;
		arr[x] = 0;
	}
	for(int i = 0;i < n;i++)
		printf("%d\n", arr[i]);
	return 0;
}
