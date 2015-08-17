/*
问题描述
度度熊有一台服务器，用于处理另外两台机器对它的请求。这两台机器在从1开始的每个整数时刻都会向服务器分别发出0个或多个请求。每个时刻，服务器都会响应其中一台机器的请求，第i个时刻会将该机器在第i时刻和之前所有没有响应的请求全部响应。对于每个请求，定义它的处理时间为请求发出的时刻到服务器响应它的时刻。如果机器发出某个请求的时刻服务器正好在响应这台机器，则这个请求的处理时间为0。
度度熊已经知道了从第1个时刻到第n个时刻中每个时刻机器向服务器的请求数，其中第i个时刻第一台机器向服务器发出了pi个请求，第二台机器向服务器发出了qi个请求。这些请求必须在n + 1个时刻全部处理完，请告诉度度熊最坏情况下所有请求的处理时间之和是多少。
输入描述
输入包含一组数据。
输入的第一行包含一个整数n，表示请求的时刻数。
接下来n行描述所有的请求，其中第 i 行包含两个整数 pi qi ，分别表示第 i 个时刻第一台和第二台机器发送的请求数。
输出描述
输出一行，包含一个整数，表示最坏情况下所有请求处理时间之和。
样例输入
4
6 3
0 0
0 5
0 0
样例输出
24
提示
对于所有测试数据，1 ≤ n ≤ 3000，0 ≤ pi, qi ≤ 1000。

*/


#include <stdio.h>

int ta[3005], tb[3005];
int sumA[3005], sumB[3005];
int work[3005];
int main()
{
	int n;
	int sum;
	int i;
	int res, wa, wb, tempa, tempb;

	
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%d %d", &ta[i], &tb[i]);

	sumA[0] = ta[0];
	sumB[0] = tb[0];
	for(i = 1;i < n;i++)
	{
		sumA[i]  = sumA[i - 1] + ta[i];
		sumB[i]  = sumB[i - 1] + tb[i];
	}

	for(i = n;i >= 0;i--)
		if (sumA[i - 1] > sumB[i - 1])
			work[i] = 0;
		else
			work[i] = 1;

	res = 0;
	wa = sumA[0];
	wb = sumB[0];
	tempa = 0;
	tempb = 0;
	for(i = 1;i <= n;i++)
	{
		tempa += wa;
		tempb += wb;
		if (work[i] == 0)
		{
			res += tempa;
			tempa = 0;
			wa = 0;

			wb += tb[i];
		}
		else
		{
			res += tempb;
			tempb = 0;
			wb = 0;

			wa += ta[i];
		}
	}

	printf("%d\n", res);
	return 0;
}
