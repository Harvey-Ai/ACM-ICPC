/*
描述
在著名的unix系统中，使用了一种简洁高效的时间表示方法，即：
将1970年1月1日0点作为“unix纪元”的原点，从1970年1月1日开始经过的秒数存储为一个32位整数

请编写一个程序，帮助把一个unix时间辍，转换成形如"YYYY-mm-dd HH:ii:ss"的格式，其中的字母分别代表
YYYY	4 位数字完整表示的年份
mm	数字表示的月份，有前导零的 2 位数字
dd	月份中的第几天，有前导零的2位数字
HH	小时，24 小时格式，有前导零
ii	有前导零的分钟数
ss	秒数，有前导零
输入
输入数据有若干行，每行包含一个整数t，(0<=t<2^31)
输出
对每一行输入数据，输出一行，为形如“YYYY-mm-dd HH:ii:ss”格式的时间
样例输入
10
1234567890
样例输出
1970-01-01 00:00:10
2009-02-13 23:31:30
*/


#include <stdio.h>
#define MI 60
#define HH (MI * 60)
#define DD (HH * 24)
#define BMM (DD * 31)
#define SMM (DD * 30)
#define BRMM (DD * 29)
#define SRMM (DD * 28)
#define YEAR (BMM * 7 + SMM * 4 + BRMM)
#define RYEAR (BMM * 7 + SMM * 4 + SRMM)

int main()
{
	char str[100];
	int len;
	int s;
	int yy, mm, dd, hh, mi, ss;
	int temp;
	while(scanf("%d", &s) != EOF)
	{
		temp = s;
		yy = 1970;
		while(temp >= 0)
		{
			if (yy % 4 && yy % 100 != 0)
				temp -= RYEAR;
			else
				temp -= YEAR;
			yy++;
		}
		yy--;
		if (yy % 4 && yy % 100 != 0)
			temp += RYEAR;
		else
			temp += YEAR;
		mm = 1;
		while(temp >= 0)
		{
			if (mm == 2)
			{
				if (yy % 4 && yy % 100 != 0)
					temp -= BRMM;
				else
					temp -= SRMM;
			}
			else if ((mm % 2 && mm < 7) || (mm % 2 == 0 && mm > 7))
				temp -= BMM;
			else
				temp-=SMM;
			mm++;
		}
		mm--;
		if (mm == 2)
		{
			if (yy % 4 && yy % 100 != 0)
				temp += BRMM;
			else
				temp += SRMM;
		}
		else if ((mm % 2 && mm < 7) || (mm % 2 == 0 && mm > 7))
			temp += BMM;
		else
			temp += SMM;
		dd = 1;
		while (temp >= 0)
		{
			temp -= DD;
			dd++;
		}
		dd--;
		temp += DD;
		hh = 0;
		while (temp >= 0)
		{
			temp -= HH;
			hh++;
		}
		hh--;
		temp += HH;
		mi = 0;
		while(temp >= 0)
		{
			temp -= MI;
			mi++;
		}
		mi--;
		temp += MI;
		ss = temp;
		sprintf(str, "%d-", yy);
		len = 5;
		if (mm < 10)
			sprintf(str + len, "0%d-", mm);
		else
			sprintf(str + len, "%d-", mm);
		len += 3;
		if (dd < 10)
			sprintf(str + len, "0%d ", dd);
		else
			sprintf(str + len, "%d ", dd);
		len += 3;
		if (hh < 10)
			sprintf(str + len, "0%d:", hh);
		else
			sprintf(str + len, "%d:", hh);
		len += 3;
		if (mi < 10)
			sprintf(str + len, "0%d:", mi);
		else
			sprintf(str + len, "%d:", mi);
		len += 3;
		if (ss < 10)
			sprintf(str + len, "0%d", ss);
		else
			sprintf(str + len, "%d", ss);
		len += 3;
		str[len] = '\0';
		printf("%s\n", str);
	}
}
