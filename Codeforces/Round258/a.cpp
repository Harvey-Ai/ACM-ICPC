#include <iostream>
using namespace std;

int main()
{
	int arr[105][105];
	
	for(int i = 0;i < 105;i++)
		arr[i][0] = arr[0][i] = 0;

	int n, m;
	cin >> n >> m;

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			if (arr[i - 1][j - 1] == 1)
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}

	cout << (arr[n][m] == 0 ? "Malvika" : "Akshat")  << endl;
	return 0;
}
