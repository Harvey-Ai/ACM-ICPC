/*
题目描述：
    今天的上机考试虽然有实时的Ranklist，但上面的排名只是根据完成的题数排序，没有考虑每题的分值，所以并不是最后的排名。给定录取分数线，请你写程序找出最后通过分数线的考生，并将他们的成绩按降序打印。
输入：
    测试输入包含若干场考试的信息。每场考试信息的第1行给出考生人数N ( 0 < N < 1000 )、考题数M ( 0 < M < = 10 )、分数线（正整数）G；第2行排序给出第1题至第M题的正整数分值；以下N行，每行给出一名考生的准考证号（长度不超过20的字符串）、该生解决的题目总数m、以及这m道题的题号（题目号由1到M）。 
    当读入的考生人数为0时，输入结束，该场考试不予处理。
输出：
    对每场考试，首先在第1行输出不低于分数线的考生人数n，随后n行按分数从高到低输出上线考生的考号与分数，其间用1空格分隔。若有多名考生分数相同，则按他们考号的升序输出。
样例输入：
4 5 25
10 10 12 13 15
CS004 3 5 1 3
CS003 5 2 4 1 3 5
CS002 2 1 2
CS001 3 2 3 5
1 2 40
10 30
CS001 1 2
2 3 20
10 10 10
CS000000000000000001 0
CS000000000000000002 2 1 2
0
样例输出：
3
CS003 60
CS001 37
CS004 37
0
1
CS000000000000000002 20
*/


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct tt
{
	char name[100];
	int sum;
};

bool cmp(const struct tt a, const struct tt b)
{
	if (a.sum > b.sum)
		return 1;
	else if (a.sum < b.sum)
		return 0;
	else if (strcmp(a.name, b.name) < 0)
		return 1;
	else
		return 0;
}

int main()
{
	struct tt p[1005], p1[1005];
	int arr[20];
	int i, j;
	int m, n;
	int line;
	int cnt;
	int index;

	while(cin >> n, n)
	{
	//	cin >> m >> line;
		scanf("%d %d", &m, &line);
		for(i = 1;i <= m;i++)
			scanf("%d", &arr[i]);

		for(i = 0;i < n;i++)
		{
			scanf("%s", p[i].name);
		//	cin >> p[i].name;
			p[i].sum = 0;
		//	cin >> cnt;
			scanf("%d", &cnt);
			while(cnt--)
			{
				scanf("%d", &index);
			//	cin >> index;
				p[i].sum += arr[index];
			}
		}

		for(i = 0, j = 0;i < n;i++)
			if (p[i].sum >= line)
				p1[j++] = p[i];

		sort(&p1[0], &p1[j], cmp);
		
		printf("%d\n", j);
		for(i = 0;i < j;i++)
			printf("%s %d\n", p1[i].name, p1[i].sum);
	}
	return 0;
}
