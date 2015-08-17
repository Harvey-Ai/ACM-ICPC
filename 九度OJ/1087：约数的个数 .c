/*
题目描述：
输入n个整数,依次输出每个数的约数的个数
输入：
输入的第一行为N，即数组的个数(N<=1000)
接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
当N=0时输入结束。
输出：
可能有多组输入数据，对于每组输入数据，
输出N行，其中每一行对应上面的一个数的约数的个数。
样例输入：
5
1 3 4 6 12
样例输出：
1
2
3
4
6
*/


/*
#include <iostream>
using namespace std;

//int primes[100005];
//int flag[100005];
long long a;
long long j;
int i, n, res;


int main()
{
	while(cin >> n, n != 0)
	{
		for(i = 0;i < n;i++)
		{
			cin >> a;
			res = 0;
			for(j = 1; j * j < a;j++)
				if (a % j == 0 && a > j)
					res += 2;
			
			if (j * j == a)
				res++;
			cout << res << endl;
		}
	}
	return 0;

}
*/

#include <stdio.h>

int main()
{
	int n;
	int i;
	int res;
	int j, a;
	
	while(scanf("%d", &n)!=EOF)
	{
		if (n == 0)
			break;
		for(i = 0;i < n;i++)
		{
			res = 0;
			scanf("%d", &a);
			for(j = 1;j * j < a;j++)
				if (a % j == 0)
					res += 2;
			if (j * j == a)
				res++;
			printf("%d\n", res);
		}
	}
	return 0;
}
