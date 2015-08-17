#include <stdio.h>
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int i, n, temp;
	int sum;
	int common;
	int a, b;
	scanf("%d", &n);
	sum = 0;
	for(i = 2;i < n;i++)
	{
		temp = n;
		while(temp)
		{
			sum += temp % i;
			temp /= i;
		}
	}
	common = gcd(sum, n - 2);
	a = sum / common;
	b = (n - 2) / common;
	printf("%d/%d\n", a, b);
}
