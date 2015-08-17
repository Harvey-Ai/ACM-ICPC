/*
题目描述:
有一个半径为 1 米的圆,圆心位于(0,0)点。你和圆处在同一平面上,准备和这个圆一起玩
游戏。这个圆每过一分钟会随机移动一次,一共移动 t 次。 圆有一个移动距离限制参数 s,
每次圆心从(x1,y1)移动到(x2,y2)时总是满足:|x1-x2|<=s, |y1-y2|<=s。
每次圆移动完成后,你可以依次询问 k 个点是否在圆内,然后任意走到一个新的位置,结束
这个回合。你的目标是尽量让自己位于圆内,并且离圆心越近越好。 每个回合结束后, 若
你在圆的边界上或者圆外, 得 0 分; 若在圆内, 得分为(1-你到圆心的距离/圆的半径)。所
有 t 个回合结束后,每个回合的平均得分就是你对于该测试点的原始得分。
交互:
你的程序应当读写标准输入输出,以便与测试库交互。交互方式如下:
首先,你的程序应从标准输入读入三个数 t, s, k,分别表示总回合数、圆心移动的距离限
制,以及每回合你可以询问的点数。1<=t<=100, 0 < s < 1, 1<=k<=10。
接下来,你应当分 k 行给出各个询问点的坐标——每行两个数 x 和 y,即询问坐标为(x,y)
的点。每次询问一个点之后,你的程序应当从标准输入读入 一个数 a,1 表示询问点在圆上
或者圆的边界上,0 表示在圆外。
再接下来,你的程序应当往标准输出写两个数 x 和 y,表示你要走到的新位置的坐标。
完成所有 t 个回合之后,你的程序应当自行退出,否则将按超时处理。
程序举例:
下面是一个示例程序(省略了 include),它能正确的与测试库进行交互,尽管它的得分可
能不高:
int main()
{
int t, k;
float s;
scanf(“%d%f%d”, &t, &s, &k);
for(int i = 0; i < t; i++)
{
101for(int j = 0; j < k; j++)
{
int ans = 0;
printf(“0.%d 0.%d\n”, rand(), rand());
fflush(stdout);
scanf(“%d”, &ans); // 1 表示仍然在圆里或圆的边界上,0 表示在圆外
}
printf(“0.%d 0.%d\n”, rand(), rand());
}
}
注意,你的程序应当像上面的程序一样,在每次读取新的输入之前调用 fflush(stdout),
以确保这之前输出的内容立即被送入测试库(而不是留在输出缓冲区中)。另外,你的程序
应能独立编译,不能依赖于任何其他外部文件(包括测试库)
*/


#include <stdio.h>
#include <math.h>
#define MAXNUM 150
#define ESP 1e-9

struct point
{
	double x, y;
};

struct point query[MAXNUM];
struct point inBound[MAXNUM];
struct point hit[MAXNUM];

int addQuery(int inNum, int newNum)
{
	struct point temp;
	int queryNum = 0;
	int i, j, k;

	// add query point
	for(i = 0;i < inNum;i++)
		for(j = 0;j < newNum;j++)
		{
			temp.x = (inBound[i].x + hit[j].x) / 2;
			temp.y = (inBound[i].y + hit[j].y) / 2;
			for(k = 0;k < queryNum;k++)
				if ((fabs)(temp.x - query[k].x) <= ESP &&
					(fabs)(temp.y - query[k].y) <= ESP)
					break;
			if (k >= queryNum)
				query[queryNum++] = temp;
		}
	// add hit point
	for(j = 0;j < newNum;j++)
		inBound[j + inNum] = hit[j];

	return queryNum;
}

int main()
{
	int i, j;
	int t, k;
	int inNum;
	int hitNum;
	int queryNum;
	double s;
	struct point heart;
	struct point res;
	
	scanf("%d %lf %d", &t, &s, &k);

	heart.x = heart.y = 0;
	for(i = 0;i < t;i++)
	{
		inNum = 1;
		inBound[0] = heart;
		query[0] = heart;
		//four top point
		query[1].x = heart.x - s;
		query[1].y = heart.y + s;
		query[2].x = heart.x - s;
		query[2].y = heart.y - s;
		query[3].x = heart.x + s;
		query[3].y = heart.y - s;
		query[4].x = heart.x + s;
		query[4].y = heart.y + s;

		queryNum = 5;
		hitNum = 0;
		for(j = 0;j < k;j++)
		{
			int ans = 0;
			if (j >= queryNum)
			{
				queryNum = addQuery(inNum, hitNum);
				inNum += hitNum;
				hitNum = 0;
			}

			printf("%lf %lf\n", query[j].x, query[j].y);
			fflush(stdout);
			scanf("%d", &ans); // 1±íÊŸÈÔÈ»ÔÚÔ²Àï»òÔ²µÄ±ßœçÉÏ£¬0±íÊŸÔÚÔ²Íâ
			if (ans == 1)
			{
				hit[hitNum] = query[j];
				hitNum++;
			}
		}
		if (hitNum)
		{
			for(j = 0;j < hitNum;j++)
				inBound[j + inNum] = hit[j];
			inNum += hitNum;
		}
		res.x = res.y = 0;
		for(j = 0;j < inNum;j++)
		{
			res.x += inBound[j].x;
			res.y += inBound[j].y;
		}
		res.x /= inNum;
		res.y /= inNum;
		printf("%lf %lf\n", res.x, res.y);
	}
	return 0;
}
