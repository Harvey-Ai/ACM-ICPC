/*
题目描述：
    Excel可以对一组纪录按任意指定列排序。现请你编写程序实现类似功能。
    对每个测试用例，首先输出1行“Case i:”，其中 i 是测试用例的编号（从1开始）。随后在 N 行中输出按要求排序后的结果，即：当 C=1 时，按学号递增排序；当 C=2时，按姓名的非递减字典序排序；当 C=3 
时，按成绩的非递减排序。当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。
输入：
    测试输入包含若干测试用例。每个测试用例的第1行包含两个整数 N (N<=100000) 和 C，其中 N 是纪录的条数，C 是指定排序的列号。以下有N行，每行包含一条学生纪录。每条学生纪录由学号（6位数字，同组测试中没有重复的学号）、姓名（不超过8位且不包含空格的字符串）、成绩（闭区间[0, 100]内的整数）组成，每个项目间用1个空格隔开。当读到 N=0 时，全部输入结束，相应的结果不要输出。
输出：
    对每个测试用例，首先输出1行“Case i:”，其中 i 是测试用例的编号（从1开始）。随后在 N 行中输出按要求排序后的结果，即：当 C=1 时，按学号递增排序；当 C=2时，按姓名的非递减字典序排序；当 C=3 
时，按成绩的非递减排序。当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。
样例输入：
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
0 0
样例输出：
Case 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Case 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Case 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;


struct tt
{
	char id[10], name[10];
	int score;
};

bool cmp1(const struct tt &a, const struct tt &b)
{
	if (strcmp(a.id, b.id) < 0)
		return 1;
	else
		return 0;
}

bool cmp2(const struct tt &a, const struct tt &b)
{
	int temp = strcmp(a.name, b.name);
	if (temp < 0)
		return 1;
	else if (temp > 0)
		return 0;
	else if (strcmp(a.id, b.id) < 0)
		return 1;
	else
		return 0;
}

bool cmp3(const struct tt &a, const struct tt &b)
{
	if (a.score < b.score)
		return 1;
	else if (a.score > b.score)
		return 0;
	else if (strcmp(a.id, b.id) < 0)
		return 1;
	else
		return 0;
}


int main()
{
	int n, c;
	int i;
	int icase = 1;
	struct tt student[100005];

	while(scanf("%d %d", &n, &c), n)
	{
		for(i = 0;i < n;i++)
			scanf("%s %s %d", student[i].id, student[i].name, &student[i].score);

		switch(c)
		{
			case 1:
				sort(&student[0], &student[n], cmp1);
				break;
			case 2:
				sort(&student[0], &student[n], cmp2);
				break;
			case 3:
				sort(&student[0], &student[n], cmp3);
		}

		printf("Case %d:\n", icase++);
		for(i = 0;i < n;i++)
			printf("%s %s %d\n", student[i].id, student[i].name, student[i].score);
	}
	return 0;
}
