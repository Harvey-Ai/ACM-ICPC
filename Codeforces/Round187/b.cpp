#include <iostream>
#include <cstdio>
using namespace std;

int arr[100005];
int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < n;i++)
		cin >> arr[i];

	int shiftSize = 0;
	for(int i = 0;i < m;i++)
	{
		int t;
		cin >> t;

	//	printf("0:%d, shift%d\n", arr[0], shiftSize);
		if (t == 1)
		{
			int v, x;
			cin >> v >> x;
			arr[v - 1] = x - shiftSize;
		}
		else if (t == 2)
		{
			int y;
			cin >> y;
			shiftSize += y;
		}
		else if (t == 3)
		{
			int q;
			cin >> q;
			cout << arr[q - 1] + shiftSize << endl;
		}
	}
	return 0;
}
