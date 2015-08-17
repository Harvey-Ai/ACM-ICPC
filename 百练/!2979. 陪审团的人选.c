#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int bbyte[25];

void initByte()
{
	bbyte[0] = 0;
	bbyte[1] = 1;
	for(int i = 2;i < 22;i++)
		bbyte[i] = bbyte[i - 1] << 1;
}

int getByteIndex(int a)
{
	for(i = 0;i < 22;i++)
		if (a > bbyte[i])
			return i - 1;
}
int main()
{
	int sum1, sum2, sum11, sum22;
	int index1, index2;
	int set[205], set2[205];
	int dp[205][805];
	int arr[205], brr[205];
	int m, n;
	int i, j, k;
	int icase = 1;

	while(cin >> n >> m, m && n)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][400] = 1;
		arr[0] = brr[0] = 0;
		for(i = 1;i <= n;i++)
		{
			cin >> arr[i] >> brr[i];
			for(j = m;j > 0;j--)
				for(k = 0;k < 801;k++)
				{
					int last = k - arr[i] + brr[i];
					if (last >= 0 && last < 801 && (dp[j - 1][last] || (j == 1 && j == 400)))
					{
						int temp = getByteIndex(dp[j][k]);
						if (dp[j][k] == 0 || arr[temp] + brr[temp] < arr[i] + brr[i])
							dp[j][k] = dp[j - 1][last] | bbyte[i];
					}
				}
		}
		for(i = 0;i < 401;i++)
			if (dp[m][i + 400] || dp[m][400 - i])
				break;
	//	cout << dp[m][402] << endl;
	//	cout << i << endl;
		index1 = dp[m][i + 400];
		index2 = dp[m][400 - i];
		sum1 = 0; sum2 = 0;
		sum11 = 0; sum22 = 0;
		memset(set, 0, sizeof(set));
		memset(set2, 0, sizeof(set2));

	//	cout << dp[m][index1] << endl;
		if (dp[m][index1])
			for(i = 21;i > 0;i--)
			{
				if (index1 & bbyte[i])
				{
					sum1 += arr[dp[i][index1]];
				sum2 += brr[dp[i][index1]];
				set[dp[i][index1]] = 1;
				index1 -= arr[dp[i][index1]] - brr[dp[i][index1]];
			//	cout << "fdsa dsaf " << endl;
			}

		if (dp[m][index2])
			for(i = m;i > 0;i--)
			{
				sum11 += arr[dp[i][index2]];
				sum22 += brr[dp[i][index2]];
				set2[dp[i][index2]] = 1;
				index2 -= arr[dp[i][index2]] - brr[dp[i][index2]];
				cout << dp
			}

		if (sum1 + sum2 > sum11 + sum22)
		{
			cout << "Jury #" << icase++ << endl; 
			cout << "Best jury has value " << sum1 << " for prosecution and value " << sum2 << " for defence:" << endl;
			for(i = 1;i <= n;i++)
				if (set[i])
					cout << " " << i;
		}
		else
		{
			cout << "Jury #" << icase++ << endl; 
			cout << "Best jury has value " << sum11 << " for prosecution and value " << sum22 << " for defence:" << endl;
			for(i = 1;i <= n;i++)
				if (set2[i])
					cout << " " << i;
		}
		cout << endl;
	}
	return 0;
}
