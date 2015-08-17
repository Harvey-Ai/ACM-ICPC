/*
描述
给出两个不大于65535的非负整数，判断其中一个的16位二进制表示形式，是否能由另一个的16位二进制表示形式经过循环左移若干位而得到。

循环左移和普通左移的区别在于：最左边的那一位经过循环左移一位后就会被移到最右边去。比如：
1011 0000 0000 0001 经过循环左移一位后，变成 0110 0000 0000 0011, 若是循环左移2位，则变成 1100 0000 0000 0110
输入
第一行是个整数n, 0 < n < 300000,表示后面还有n行数据
后面是n行，每行有两个不大于65535的非负整数
输出
对于每一行的两个整数，输出一行，内容为YES或NO
样例输入
4
2 4
9 18
45057 49158
7 12
样例输出
YES
YES
YES
NO
*/

#include <stdio.h>

void convert(int n, char *str)
{
	int i = 0;
	while(n)
	{
		str[i++] = (n & 0x01) + '0';
		n>>=1;
	}
	while(i < 16)
		str[i++] = '0';
	str[16] = '\0';
}
int main()
{
	int i, j, len, a, b;
	char str1[40], str2[40];
	int ncase;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d %d", &a, &b);
		convert(a, str1);
		convert(b, str2);

		len = 16;
		for(i = len - 1;i >= 0;i--)
		{
			for(j = len - 1;j >= 0;j--)
				if (str2[j] != str1[(i + 1 + j)%len])
					break;
			if (j < 0)
				break;
		}
		if (i >= 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
