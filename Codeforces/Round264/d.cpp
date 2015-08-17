#include <iostream>
#include <cstring>
using namespace std;

int dp[1005][1005];
int pre[1005][1005];

int arr1[1005];
int arr2[1005];

int lcs(int *arr1, int *arr2, int n1, int n2)
{
	memset(dp, 0, sizeof(dp));
	for(int i = 0;i < n1;i++)
		for(int j = 0;j < n2;j++)
		{
			int k = 0;
			dp[i + 1][j + 1] = dp[i][j + 1];
			if (dp[i + 1][j + 1] < dp[i + 1][j])
			{
				dp[i + 1][j + 1] = dp[i + 1][j];
				k = 1;
			}
			if (arr1[i] == arr2[j] && dp[i + 1][j + 1] < dp[i][j] + 1)
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				k = 2;
			}
			pre[i + 1][j + 1] = k;
		}

	int pos1 = n1, pos2 = n2;
	int arr3[1005];
	int num = 0;
	while(pos1 > 0 && pos2 > 0)
	{
		if (pre[pos1][pos2] == 2)
		{
			arr3[num++] = arr1[pos1 - 1];
			pos1--;pos2--;
		}
		else if (pre[pos1][pos2] == 1)
			pos2--;
		else
			pos1--;
	}

	for(int i = num - 1;i >= 0;i--)
		arr1[num - i - 1] = arr3[i];
	return num;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0;i < n;i++)
		cin >> arr1[i];

	int res = n;
	for(int i = 1;i < k;i++)
	{
		for(int j = 0;j < n;j++)
			cin >> arr2[j];
		res = lcs(arr1, arr2, res, n);
		for(int j = 0;j < res;j++)
			cout << arr1[j] << " ";
		cout << endl;
	}

	cout << res << endl;
	return 0;
	
}
