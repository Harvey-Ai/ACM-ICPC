/*
Problem Description
  Now you get a number N, and a M-integers set, you should find out how many integers which are small than N, that they can divided exactly by any integers in the set. For example, N=12, and M-integer set is {2,3}, so there is another set {2,3,4,6,8,9,10}, all the integers of the set can be divided exactly by 2 or 3. As a result, you just output the number 7.
 

Input
  There are a lot of cases. For each case, the first line contains two integers N and M. The follow line contains the M integers, and all of them are different from each other. 0<N<2^31,0<M<=10, and the M integer are non-negative and won’t exceed 20.
 

Output
  For each case, output the number.
 

Sample Input
12 2
2 3
 

Sample Output
7
*/


#include <stdio.h>
#define N 15

int chose[N], arr[N];
int m, n;
long long ans;

int gcd(int a, int b)
{
	int aa = a, bb = b, temp;
	while(bb)
	{
		temp = aa;
		aa = bb;
		bb = temp % bb;
	}
	return aa;
}

void cal1(int chos, int depth, int cnt, int op)
{
	int i, temp = 1;
	if (cnt == chos)
	{
		for(i = 0;i < chos;i++)
		{
			temp *= chose[i] / gcd(temp, chose[i]);
			if (temp >= n)
				break;
		}
		if (temp >= n)
			return;
		ans += (n - 1) / temp;
		return;
	}
	chose[cnt] = arr[depth];
	cal1(chos, depth + 1, cnt + 1, op);

	if (m - depth - 1 >= chos - cnt)
		cal1(chos, depth + 1, cnt, op);
}

void cal2(int chos, int depth, int cnt, int op)
{
	int i, temp = 1;
	if (cnt == chos)
	{
		for(i = 0;i < chos;i++)
		{
			temp *= chose[i] / gcd(temp, chose[i]);
			if (temp >= n)
				break;
		}
		if (temp >= n)
			return;
		ans -= (n - 1) / temp;
		return;
	}
	chose[cnt] = arr[depth];
	cal2(chos, depth + 1, cnt + 1, op);

	if (m - depth - 1 >= chos - cnt)
		cal2(chos, depth + 1, cnt, op);
}

int main()
{
	int i;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(i = 0;i < m;i++)
		{
			scanf("%d", &arr[i]);
			if (arr[i] >= n || arr[i] == 0)
			{
				i--;
				m--;
			}
		}

		ans = 0;
		for(i = 0;i < m;i++)
		{
			if (i & 0x01)
				cal2(i + 1, 0, 0, i);
			else
				cal1(i + 1, 0, 0, i);
		}

		printf("%lld\n", ans);
	}
	return 0;
}
