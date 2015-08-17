#include <iostream>
using namespace std;
#define MOD 1000000007

void extgcd(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(!b)
	{	
d=a;	x=1;	y=0;
	}
	else
	{
extgcd(b,a%b,d,y,x);
		y = (y - x*(a/b)) % MOD;
	}
}

long long mod(long long x,long long n)
{
	return (x%n+n)%n;
}
long long inv(long long a,long long n)
{
	long long d,x,y;
	extgcd(a,n,d,x,y);
	return d==1 ? mod(x,n) : -1;
}

long long fact(long long r, long long n)
{
	int i;
	long long res = 1;
	for(i = r;i <= n;i++)
		res = (i * res) % MOD;
	return res;
}

// C(2n -1 , n);
long long cal(int n)
{
	long long res;
	res = fact(n, 2 * n - 1);
	res = (res * inv(fact(1, n), MOD)) % MOD;
	return res;
}

int main()
{
	int n;
	long long res;
	cin>>n;
	res = cal(n);
	cout<<(2 * res - n) % MOD;
	return 0;
}
