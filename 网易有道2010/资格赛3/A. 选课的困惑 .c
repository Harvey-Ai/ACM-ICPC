/*
描述   
小明打算本科毕业后申请出国，不过他想申请一个好学校，所有课程的加权平均分必须达到90分及以上。   现在小明已经修完所有的必修课，他想通过修一些选修课让课程加权平均分最终达到他的要求。一共有m门选修课可以随意选修，且他能很明确知道选修每个选修课能得到的分数，请问至少修多少门课才能达到他的要求？假设共有k门课程，其总的加权平均分的计算方法如下：    
	加权平均分=(成绩1*学分1+成绩2*学分2+……成绩k*学分k) / (学分1+学分2+……学分k)   
输入 
第一行包含一个正整数T，表示有T组测试数据。  每个测试数据第一行包含空格隔开的两个正整数n和m，表示小明已修完了n门必修课，还有m门选修课可供选择。  接下来有n行，每行包含空格隔开的一个实数ai和一个整数bi，分别表示小明第i门课的成绩以及第i门课的学分数  接下来有m行，每行包含空格隔开的一个实数cj和一个整数dj，分别表示小明第j门选修课可以获得的预期分数以及第j门选修课的学分数。 其中：  1<=T<=100, 1 <= n,m <= 100, 0 <= ai, cj <= 100, 1 <= bi, dj <= 5，所有的分数小数点后至多两位。
输出 
每组测试数据输出一行，如果可以达到要求，则输出一个整数k，表示小明至少要修的选修课数目，如果小明修完所有的选修课都不可能达到要求，则输出 Impossible   
样例输入   
2
3 4 
80.00 1
40.00 2
20.00 2
90.00 3
88.00 2
92.00 2
100.00 1
3 4 
62.00 1
70.00 1
80.00 1
99.00 2
100.00 2
100.00 2 
100.00 2
样例输出
Impossible
3 
*/

#include <stdio.h>
#include <stdlib.h>
#define N 105
#define ESP 0.00001

struct xuan
{
	double sc;
	int val;
};

int cmp(const void *a, const void *b)
{
	struct xuan *aa = (struct xuan *)a;
	struct xuan *bb = (struct xuan *)b;

	double ac = aa->sc * aa->val - 90.00 * aa->val;
	double bc = bb->sc * bb->val - 90.00 * bb->val;
	if (ac - bc > ESP)
		return -1;
	else
		return 1;
}

int main()
{
	struct xuan lession[N];
	double score;
	int val;
	double a;
	int b;
	int ncase;
	int i;
	int n, m;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d %d", &n, &m);
		score = val = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%lf %d", &a, &b);
			score += a * b;
			val += b;
		}
		for(i = 0;i < m;i++)
		{
			scanf("%lf %d", &lession[i].sc, &lession[i].val);
			if (lession[i].sc - 90.00 < -ESP)
			{
				i--;
				m--;
			}
		}
		qsort(lession, m, sizeof(lession[0]), cmp);

	//	for(i = 0;i < m;i++)
	//		printf("%lf %d\n", lession[i].sc, lession[i].val);
	
		if (score - 90.00 * val < -ESP)
		{
			for(i = 0;i < m;i++)
			{
				score += lession[i].sc * lession[i].val;
				val += lession[i].val;

				if (score - 90.00 * val > ESP)
					break;
			}
			if (i >= m)
				printf("Impossible\n");
			else			
				printf("%d\n", i + 1);
		}
		else
			printf("0\n");
	}
	return 0;
}
