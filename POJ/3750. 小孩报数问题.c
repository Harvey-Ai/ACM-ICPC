/*
Description

有N个小孩围成一圈，给他们从1开始依次编号，现指定从第W个开始报数，报到第S个时，该小孩出列，然后从下一个小孩开始报数，仍是报到S个出列，如此重复下去，直到所有的小孩都出列（总人数不足S个时将循环报数），求小孩出列的顺序。
Input

第一行输入小孩的人数N（N<=64） 
接下来每行输入一个小孩的名字(人名不超过15个字符) 
最后一行输入W,S (W < N)，用逗号","间隔
Output

按人名输出小孩按顺序出列的顺序，每行输出一个人名
Sample Input

5
Xiaoming
Xiaohua
Xiaowang
Zhangsan
Lisi
2,3
Sample Output

Zhangsan
Xiaohua
Xiaoming
Xiaowang
Lisi

*/


#include <stdio.h>
#include <string.h>

char name[100][100];
int isIn[100];

int main()
{
	int i, p, a, b, num, n;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%s", name[i]);
	scanf("%d,%d", &a, &b);

	memset(isIn, 0, sizeof(isIn));

	for(i = 0, p = a - 1;i < n;i++)
	{
		for(num = 0;;p++)
		{
			if (p >= n)
				p -= n;
			if (isIn[p] == 0)
				num++;
			if (num >= b)
				break;
		}
		isIn[p] = 1;
		printf("%s\n", name[p]);
		p++;
	}
	return 0;
}
