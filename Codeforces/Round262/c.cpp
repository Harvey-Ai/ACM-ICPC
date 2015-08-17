#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

long long arr[100005];
int main()
{
	long long n, m, w;
	cin >> n >> m >> w;
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	long long high = 1000100001, low = 1;

	long long res = -1;
	while(low <= high)
	{
		long long mid = (low + high) / 2;

		long long days = 0;
		queue<long long> waterQ;
		long long waterDays[1000005];
		memset(waterDays, 0, sizeof(waterDays));
		long long sum = 0;

		for(long long i = 0;i < n && days <= m;i++)
		{
			while(!waterQ.empty() && i - waterQ.front() + 1 > w)
			{
				sum -= waterDays[waterQ.front()];
				waterQ.pop();
			}

			if (arr[i] + sum < mid)
			{
				days += mid - arr[i] - sum;
				waterQ.push(i);
				waterDays[i] = mid - arr[i] - sum;
				sum += waterDays[i];
			}
		}
		if (days > m)
			high = mid - 1;
		else
		{
			if (res == -1 || res < mid)
				res = mid;
			low = mid + 1;
		}
	}
	cout << res << endl;
	return 0;
}
