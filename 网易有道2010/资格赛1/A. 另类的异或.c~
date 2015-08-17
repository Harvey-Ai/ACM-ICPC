/*
描述 
对于普通的异或，其实是二进制的无进位的加法这里我们定义一种另类的异或A op B, op是一个仅由^组成的字符串，如果op中包含n个^，那么A op B表示A和B之间进行n+1进制的无进位的加法。
下图展示了3 ^ 5 和 4 ^^ 5的计算过程
0 1 1 (3) 
^   1 0 1 (5) 
--------- 
    1 1 0 (6) 

    0 1 1 (4) 
^^  0 1 2 (5) 
--------- 
    0 2 0 (6) 
输入 
第一行有一个正整数T, 表示下面共有T组测试数据。
接下来T行，每行有一组测试数据，是由空格隔开的三个部分组成：
A B 
C
A和C是两个十进制整数，B是一个字符串，由n个^组成
1 <= T <= 100, 0<=A,B<2^30, 1<=n<=1000 
输出 
每个测试数据输出一行，包含一个数字，即该数据的结果，用十进制表示。 
样例输入 
2
3 ^ 5
4 ^^ 5
*/


#include <stdio.h>
#include <string.h>
#define N 1005

int main()
{
	int ncase;
	int a, b;
	int temp1, temp2;
	int bb;
	int n;
	char op[N];
	int res;

	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d", &a);
		scanf("%s", op);
		scanf("%d", &b);

		res = 0;
		n = strlen(op);
		bb = 1;
		while(a || b)
		{
			temp1 = a % (n + 1);
			temp2 = b % (n + 1);
			res += ((temp1 + temp2) % (n + 1)) * bb;

			a /= (n + 1);
			b /= (n + 1);
			bb *= (n + 1);
		}
		printf("%d\n", res);
	}
	return 0;
}
