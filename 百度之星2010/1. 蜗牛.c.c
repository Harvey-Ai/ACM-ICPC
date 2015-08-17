/*
题目描述:
一只蜗牛某天早晨掉进了深为 L 尺的井中。蜗牛每天白天可以向上爬若干尺,晚上休息时会
向下滑若干尺。蜗牛一旦到达井口或井底,便不再下滑。
假设蜗牛每天向上爬的尺数均为不超过 10 的正整数,而下滑的尺数为不超过 5 的正整数。
蜗牛在第 N 天白天里(含第 N 天白天结束时)爬出了井,你的任务是统计有多少种可能的爬升
/下滑情况。 对于两种爬升/下滑情况,当存在对应的白天上爬或者晚上下滑的尺数不同时,
即视为不同的情况。
输入格式:
第一行:井深 L。其中 L 为正整数,且 L<=100;
第二行:爬出的天数 N。其中 N 为正整数,且 N<=300
输出格式:
输出一个正整数,为可能的爬升/下滑情况总数。如不可能在 N 天白天里(含第 N 天白天结束
时)爬出深为 L 的井,则应输出 0。
样例:
输入:
27
3
输出:
6
解释:
输入指明井深为 27。蜗牛掉下去后,在第 3 天白天爬出了井。一共有 6 种可能的上升/下滑
情况组合:
( 9, -1) (10, -1) 10 8+9+10=27
(10, -1) ( 9, -1) 10 9+8+10=27
(10, -1) (10, -1)
9 9+9+ 9=27
(10, -1) (10, -1) 10 9+9+10>27 (第 3 天白天未结束时,爬出了井)
(10, -1) (10, -2) 10 9+8+10=27
(10, -2) (10, -1) 10 8+9+10=27
样例 2
输入:
5
4
输出:
5033
样例 3
输入:
42
12
输出:
3106744105061936231
*/


#include <stdio.h>
#include <string.h>
#define MAXDAY 350
#define MAXL 150
#define MAXSTRLEN 800

void IntAddition(char *augend, char *addend, char *sum)
{
	int cAug[MAXSTRLEN] = {0};//ÓÃÀŽŽæŽ¢±»ŒÓÊýµÄÕûÐÍÊý×é
	int cAdd[MAXSTRLEN] = {0};//ÓÃÀŽŽæŽ¢ŒÓÊýµÄÕûÐÍÊý×é
	int cSum[MAXSTRLEN] = {0};//ÓÃÀŽŽæŽ¢ÁœÊýÖ®ºÍµÄÕûÐÍÊý×é
	int lenAug = strlen(augend), lenAdd = strlen(addend);//±»ŒÓÊýºÍŒÓÊý×Ö·ûŽ®µÄ³€¶È
	int lenMin = lenAug < lenAdd ? lenAug : lenAdd;//ÁœžöŒÓÊýµÄ³€¶ÈÖÐµÄœÏÐ¡Öµ
	int i;

	//ÄæÐòžŽÖÆŒÓÊýºÍ±»ŒÓÊýµœÕûÐÍÊý×é£šÒòÎªŒÓ·šÔËËãÊÇŽÓµÍÎ»¿ªÊŒ£©
	for (i=0; i<lenAug; i++)
		cAug[i] = augend[lenAug-1-i] - '0';
	for (i=0; i<lenAdd; i++)
		cAdd[i] = addend[lenAdd-1-i] - '0';

	int carry = 0;//œøÎ»
	int s = 0; //ÁœÊýÖ®ºÍ

	for (i=0; i<lenMin; i++)//ŒÓ·šÔËËã¹ý³Ì
	{
		s = cAug[i] + cAdd[i] + carry;//ÁœžöŒÓÊýºÍœøÎ»Ö®ºÍ×÷Îªµ±Ç°Î»µÄºÍ
		cSum[i] = s % 10;//ŽæŽ¢µ±Ç°Î»
		carry = s / 10;//»ñÈ¡œøÎ»
	}

	//ŽŠÀíŒÓÊý»ò±»ŒÓÊý³¬³ö³€¶ÈlenMinµÄ²¿·Ö
	while (i < lenAug)
	{
		s = cAug[i] + carry;
		cSum[i] = s % 10;
		carry = s / 10;
		i++;
	}

	while (i < lenAdd)
	{
		s = cAdd[i] + carry;
		cSum[i] = s % 10;
		carry = s / 10;
		i++;
	}

	if (carry > 0)//ŽŠÀí×îºóÒ»žöœøÎ»
		cSum[i++] = carry;

	int j;
	for (j=0; j<i; j++)//ÄæÐòŽæŽ¢ÁœÊýÖ®ºÍµœ×Ö·ûŽ®sum
		sum[j] = cSum[i-1-j] + '0';
	sum[i] = '\0';
}

char dp[MAXDAY][MAXL][MAXSTRLEN];
char res[MAXSTRLEN];
int main()
{
	int i, j, k1, k2;
	int n, l;

	while(scanf("%d %d", &l, &n) != EOF)
	{
		for(i = 0;i < MAXDAY;i++)
			for(j = 0;j < MAXL;j++)
				strcpy(dp[i][j], "0");

		strcpy(dp[0][0], "1");
		// first step
		for(i = 1;i <= 10;i++)
			strcpy(dp[1][i], "1");

		// next n - 1 step
		for(i = 2;i <= n;i++)
			for(j = 0;j < l;j++)
				for(k1 = -5;k1 <= -1;k1++)
				{
					if (j + k1 < 0)
						continue;
					for(k2 = 1;k2 <= 10;k2++)
						IntAddition(dp[i][j + k1 + k2], dp[i - 1][j], dp[i][j + k1 + k2]);
				}

		strcpy(res, "0");
		for(k1 = l;k1 <= l + 9;k1++)
			IntAddition(res, dp[n][k1], res);

		printf("%s\n", res);
	}
	return 0;
}
