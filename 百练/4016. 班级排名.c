/*
描述
信息科学技术学院年终评定讲学金，需要对整个年级的学生按照平均分数进行排名.
要求:根据输入的学号和平均成绩，按照平均成绩降序输出学号
如果平均成绩相同，按照输入的顺序输出。
输入
第一行为N,表示输入N位学生的信息，接着的N行输入学生信息，1<=N<=500
学生信息的格式为：学号 平均成绩
学号的长度小于10，平均成绩在1-100之间.
输出
按照平均成绩降序输出学号，如果平均成绩相同，按照输入顺序输出
样例输入
	5
	10948001 80
	10948004 90
	10948101 95
	10948102 80
	10948209 90
样例输出
	10948101
	10948004
	10948209
	10948001
	10948102
*/

#include <stdio.h>
#include <stdlib.h>

struct student
{
	char num[30];
	int sc;
	int ind;
}ss[505];

int cmp(const void *a, const void *b)
{
	struct student *aa = (struct student *)a;
	struct student *bb = (struct student *)b;
	if (bb->sc != aa->sc)
		return bb->sc - aa->sc;
	else
		return aa->ind - bb->ind;
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%s %d", ss[i].num, &ss[i].sc);
		ss[i].ind = i;
	}
	qsort(ss, n, sizeof(ss[0]), cmp);
	for(i = 0;i < n;i++)
		printf("%s\n", ss[i].num);
	return 0;
}
