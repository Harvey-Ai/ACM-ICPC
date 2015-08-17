/*
描述
若某个月13号恰好是星期五，则这一天被称为黑色星期五。已知某年的一月一日是星期w，并且这一年是闰年，
求出这一年所有13号那天是星期5的月份，按从小到大的顺序输出月份数字。(w=1..7)
输入
输入有多组，每组一行且为一个整数w, 指该年的一月一日是星期w。（1<=w<=7）
输出
每组数据输出一行，从小到大输出具有黑色星期五的月份，月份与月份之间用空格隔开。若没有月份具有黑色星期五，则输出NULL
样例输入
1
样例输出
9 12
*/

#include <stdio.h>

int monthDay(int n)
{
	if (n == 2)
		return 29;
	if (n <= 7)
	{
		if (n % 2 == 1)
			return 31;
		else
			return 30;
	}
	else
	{
		if (n % 2 == 0)
			return 31;
		else
			return 30;
	}
}

int main()
{
	int i;
	int ansNum;
	int ans[100];
	int wd;

	while(scanf("%d", &wd) != EOF)
	{
		wd--;
		ansNum = 0;
		for(i = 1;i < 13;i++)
		{
			if ((wd + 13 - 1) % 7 == 4)
				ans[ansNum++] = i;
			wd = (wd + monthDay(i)) % 7;
		}
		for(i = 0;i < ansNum;i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}
