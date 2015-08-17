#include <stdio.h>
#define N 1000000

int arr[N][2];
int main()
{
	int i, j, cnt, n, temp, p;

	scanf("%d", &n);
	if (n == 0)
	{
		printf("0\n");
		return 0;
	}

	arr[0][0] = arr[0][1] = 0;
	cnt = 1;
	p = 0;
	while(1)
	{
		temp = arr[p][0] + arr[p][1] + 1;
		if (temp == n)
			break;
		arr[cnt][0] = temp;
		arr[cnt][1] = arr[p][1] + 1;
		cnt++;
		temp = arr[p][0] - arr[p][1] - 1;
		if (temp == n)
			break;
		arr[cnt][0] = temp;
		arr[cnt][1] = arr[p][1] + 1;
		cnt++;

		p++;
	}
	printf("%d\n", arr[p][1] + 1);
	return 0;
}
