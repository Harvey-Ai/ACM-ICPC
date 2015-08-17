#include <iostream>
using namespace std;

#define MOD 1000000007
int arr[2005];
int C[2005][2005];

void getC()
{
	for(int i = 0;i < 2005;i++)
		C[i][0] = 1;
	C[0][0] = 0;
	
	for(int i = 1;i < 2005;i++)
	{
		C[i][0] = 1;
		for(int j = 1;j < i;j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		C[i][i] = 1;
	}
}

int main()
{
	int n, h;
	getC();
	cin >> n >> h;

	for(int i = 0;i < n;i++)
		cin >> arr[i];

	for(int i = 0;i < n;i++)
		if (arr[i] > h)
		{
			cout << 0 << endl;
			return 0;
		}

	cout << C[1][0] << " " << C[1][1] << endl;
	cout <<C[2][1] << endl;
	long long res = 1;
	for(int i = n - 1;i >= 1;i--)
	{
		if (h - arr[i - 1] + 1 < h - arr[i])
		{
			cout << 0 << endl;
			return 0;
		}
		res = (res * C[h - arr[i - 1] + 1][h - arr[i]]) % MOD;
	}

	cout << res << endl;
	return 0;
}
