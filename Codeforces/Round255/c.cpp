#include <iostream>
using namespace std;

int arr[100005];
int next[100005];
int pre[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << 2 << endl;
		return 0;
	}

	int prePos = 0;
	pre[0] = 0;
	for(int i = 1;i < n;i++)
	{
		if (arr[i] <= arr[i - 1])
		{
			for(int j = prePos;j <= i - 1;j++)
				next[j] = i - 1;
			prePos = i;
		}
		pre[i] = prePos;
	}
	for(int j = prePos;j < n;j++)
		next[j] = n - 1;

	int res = 1;
	for(int i = 0;i < n;i++)
	{
		int temp = 1;
		if (i == 0)
		{
			temp += next[1] - (1) + 1;
			res = res < temp ? temp : res;
		}
		else if (i == n - 1)
		{
			temp += n - 2 - pre[n - 2] + 1;
			res = res < temp ? temp : res;
		}
		else
		{
			int left = i - 1 - pre[i - 1] + 1;
			int right = next[i + 1] - (i + 1) + 1;

			if (arr[i + 1] - arr[i - 1] > 1)
				res = (left + right + 1) > res ? (left + right + 1) : res;
			res = (left + 1) > res ? (left + 1) : res;
			res = (right + 1) > res ? (right + 1) : res;	
		}
	}
	cout << res << endl;
	return 0;
}
