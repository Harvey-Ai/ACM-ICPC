#include <iostream>
using namespace std;
#define MOD 1000000009
#define typev long long

typev arr[300005];
int fib[300005];
int m, n;

int lowb(int t) { return t & (-t) ;}
void add(int i, typev v) {
	for ( ; i <= n; arr[i] = (v + arr[i]) % MOD, i += lowb(i));
}
typev sum(int i) {
	typev s = 0;
	for ( ; i > 0; s += arr[i], s %= MOD, i -= lowb(i));
	return s;
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i <= n;i++)
		arr[i] = 0;
	for(int i = 1;i <= n;i++)
	{
		typev a;
		cin >> a;
		add(i, a);
	}
	
	fib[1] = 1, fib[2] = 1;
	for(int i = 3;i <= n;i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

	for(int i = 0;i < m;i++)
	{
		int l, r;
		int query;
		cin >> query >> l >> r;
		if (query == 1)
		{
			for(int j = l;j <= r;j++)
				add(j, fib[j - l + 1]);
		}
		else
			cout << (sum(r) + MOD - sum(l - 1)) % MOD << endl;
	}
	return 0;
}
