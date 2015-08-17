#include <iostream>
#include <cstdio>
using namespace std;
int arr[500005];
int leftFlag[500005];

int main()
{
	int n;
	cin >> n;

	long long sum = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	if (sum % 3 || n < 3)
	{
		cout << 0 << endl;
		return 0;
	}

	long long sum1 = 0;
	for(int i = 0;i < n;i++)
	{
		sum1 += arr[i];
		if (sum1 == sum / 3)
			leftFlag[i] = 1;
	}
	for(int i = 1;i < n;i++)
		leftFlag[i] += leftFlag[i - 1];

	long long res = 0;
	long long sum2 = 0;
	for(int i = n - 1;i >= 2;i--)
	{
		sum2 += arr[i];
		if (sum2 == sum / 3)
			res += leftFlag[i - 2];
	}

	cout << res << endl;
	return 0;
}
