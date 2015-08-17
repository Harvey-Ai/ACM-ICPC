#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, k, s;
	while(cin >> n >> k >> s, n || k || s)
	{
		int arr[156][11];
		memset(arr, 0, sizeof(arr));
		arr[0][0] = 1;

		for(int i = 1;i <= n;i++)
		{
			for(int j = s;j >= i;j--)
				for(int l = 1;l <= k;l++)
					arr[j][l] += arr[j - i][l - 1];
		}
		cout << arr[s][k] << endl;
	}

	return 0;
}
