#include <iostream>
using namespace std;

#define MOD 1000000007
int in[500005];
int arr[500005], arr2[500005];
long long a[105];

int Lowbit(int t)
{
      return t & ( t ^ ( t - 1 ) );
}

void pplus(int pos, int num, int n) 
{ 
      while(pos <= n) 
      { 
            in[pos] = (in[pos] + num) % MOD;
            pos += Lowbit(pos); 
      } 
}

long long Sum(int end)
{
      long long sum = 0;
      while(end > 0)
      {
          sum += in[end];
		  sum %= MOD;
          end -= Lowbit(end);
      } 
      return sum; 
} 


int main()
{
	int ncase;
	int icase;
	int i, j;
	int m, n;
	long long x, y, z;
	long long res;
	long long temp;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %lld %lld %lld",&n, &m, &x, &y, &z);

		for(i = 0;i < m;i++)
			scanf("%lld", &a[i]);

		for(i = 0;i < n;i++)
		{
			arr[i] = a[i % m];
			arr2[i] = arr[i];
			a[i % m] = (x * a[i % m] + y * (i + 1)) % z;
		}
		sort(&arr2[0], &arr2[n]);
		res = 0;

	//	for(i = 0;i < n;i++)
	//		printf("%d ", arr[i]);
	//	putchar('\n');
		memset(in, 0, sizeof(in));
		for(i = 0;i < n;i++)
		{
			j = lower_bound(arr2, arr2 + n, arr[i]) - arr2;
			temp = Sum(j);
			res += temp + 1;
			res %= MOD;
			pplus(j + 1, temp + 1, n);
		//	printf("res %d\n", res);
		}
	//	res = (res + MOD) % MOD;
		printf("Case #%d: %lld\n", icase, res);
	}
	return 0;
}
