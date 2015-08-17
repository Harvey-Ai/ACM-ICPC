#include <stdio.h>

int main()
{
	int n;
	int i;
	int sum;
	scanf("%d", &n);
	sum = 1;
	for(i = 1;i <= n;i++)
		sum *= i;
	printf("%d\n", sum);
}
