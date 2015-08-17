#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[200005];
int main()
{
	long long n;
	cin >> n;
	
	for(int i = 0; i < n;i++)
		scanf("%I64d", &arr[i]);
	sort(arr, arr + n);

	if (arr[n - 1] == arr[0])
	{
		long long ways = (n *  (n - 1)) / 2;
		cout << 0 << " " << ways << endl;
	}
	else
	{
		long long lNum = 1, bNum = 1;
		for(int i = 1;i < n;i++)
			if (arr[i] == arr[i - 1])
				lNum++;
			else
				break;
		for(int i = n - 2;i >= 0;i--)
			if (arr[i] == arr[i + 1])
				bNum++;
			else
				break;
		cout << arr[n - 1] - arr[0] << " " << bNum * lNum << endl;
	}
	return 0;
}
