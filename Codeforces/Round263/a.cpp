#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

long long arr[300005];

struct cmp
{
	cmp()
	{
	}
	bool operator()(long long a, long long b)
	{
		if (a < b)
			return 1;
		else
			return 0;
	}
};
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%I64d", &arr[i]);

	priority_queue<long long, vector<long long>, cmp> pQ;

	for(int i = 0;i < n;i++)
		pQ.push(arr[i]);

	long long res = 0;
	while(!pQ.empty())
	{
		long long a = pQ.top();
		res += a;
		pQ.pop();
		if (!pQ.empty())
		{
			long long b = pQ.top();
			pQ.pop();
			res += b;
			pQ.push(a + b);
		}
	}

	cout << res << endl;
	return 0;
}
