#include <iostream>
#include <cstdio>
using namespace std;

long long res = 0;

void dfs(long long a)
{
	if (a == 1)
		return;
/*	if (a % 3 == 0)
	{
		res += a * a * 2 / 9;
		dfs(a / 3);
		dfs(a * 2 / 3);
	}
	else if (a % 2 == 0)
	{
		res += a * a / 4;
		dfs(a / 2);
		dfs(a / 2);
	}
	else
	{
		res += a - 1;
		dfs(a - 1);
	}
*/
	long long k;
	for(k = 2;k * k <= a;k++)
		if (a % k == 0)
		{
			res += (a / k) * (a - a / k);
			dfs(a / k);
			dfs(a - a / k);
			break;
		}
	if (k * k > a)
	{
		res += a - 1;
		dfs(a - 1);
	}
}

int main()
{

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	int ncase;
	cin >> ncase;
	for(int icase = 0;icase < ncase;icase++)
	{
		
		//cout << icase << endl;
		res = 0;
		int n;
		cin >> n;
		dfs(n);
		printf("%lld\n", res);
	}

	return 0;
}
