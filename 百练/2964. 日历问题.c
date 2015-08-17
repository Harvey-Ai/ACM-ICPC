/*
描述
在我们现在使用的日历中, 闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年。例如：1700, 1800, 1900 和 2100 不是闰年，而 1600, 2000 和 2400是闰年。 给定从公元2000年1月1日开始逝去的天数，你的任务是给出这一天是哪年哪月哪日星期几。
输入
输入包含若干行，每行包含一个正整数，表示从2000年1月1日开始逝去的天数。输入最后一行是−1, 不必处理。可以假设结果的年份不会超过9999。
输出
对每个测试样例，输出一行，该行包含对应的日期和星期几。格式为“YYYY-MM-DD DayOfWeek”, 其中 “DayOfWeek” 必须是下面中的一个： "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" 或 "Saturday“。
样例输入
1730 
1740 
1750 
1751 
-1
样例输出
2004-09-26 Sunday 
2004-10-06 Wednesday 
2004-10-16 Saturday 
2004-10-17 Sunday
*/


#include <iostream>
using namespace std;
int main()
{
	int days;
	int month;
	int year;
	int weekday;
	int run;
	int monthOver;

	while(cin >> days, days != -1)
	{
		weekday = (days % 7 + 5 ) % 7;
		days += 1;
		year = 2000;
		run = 0;
		// year
		while(1)
		{
			if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
			{
				//cout << year << "run" << endl;
				if (days - 366 > 0)
					days -= 366;
				else
				{
					run = 1;
					break;
				}
			}
			else
			{
				if (days - 365 > 0)
					days -= 365;
				else
					break;
			}
			year++;
		}
		// month
		month = 1;
		monthOver = 0;
		if (days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && run == 1)
		{
			if (days - 29 > 0)
			{
				month++;
				days -= 29;
			}
			else
				monthOver = 1;
		}
		else if (monthOver == 0 && run == 0)
		{
			if (days - 28 > 0)
			{
				month++;
				days -= 28;
			}
			else
				monthOver = 1;
		}
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 30 > 0)
		{
			month++;
			days -= 30;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 30 > 0)
		{
			month++;
			days -= 30;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 30 > 0)
		{
			month++;
			days -= 30;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 30 > 0)
		{
			month++;
			days -= 30;
		}
		else
			monthOver = 1;
		if (monthOver == 0 && days - 31 > 0)
		{
			month++;
			days -= 31;
		}
		else
			monthOver = 1;
		cout << year << "-";
		if (month < 10)
			cout << "0" << month;
		else
			cout << month;
		if (days < 10)
			cout << "-0" << days;
		else
			cout << "-" << days;
		switch (weekday)
		{
			case 0 : { cout << " Monday" << endl; break;};
			case 1 : { cout << " Tuesday" << endl; break;};
			case 2 : { cout << " Wednesday" << endl; break;};
			case 3 : { cout << " Thursday" << endl; break;};
			case 4 : { cout << " Friday" << endl; break;};
			case 5 : { cout << " Saturday" << endl; break;};
			case 6 : { cout << " Sunday" << endl; break;};
		}
	}
	return 0;
}
