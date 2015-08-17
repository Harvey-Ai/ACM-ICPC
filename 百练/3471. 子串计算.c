/*
描述
给出一个01字符串（长度不超过100），求其每一个子串出现的次数。
输入
输入包含多行，每行一个字符串。
输出
对每个字符串，输出它所有出现次数在1次以上的子串和这个子串出现的次数，输出按字典序排序。
样例输入
10101
样例输出
0 2
01 2
1 3
10 2
101 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mulStr
{
	char ss[105];
	int time;
}ans[1000];

struct mulStr relAns[10005];

int cmp(const void *a, const void *b)
{
	struct mulStr *aa = (struct mulStr *)a;
	struct mulStr *bb = (struct mulStr *)b;
	return strcmp(aa->ss, bb->ss);
}

char save[105];

int main()
{
	int i, j, l, w;
	int len, ansNum;
	int relNum;
	char str[105];

	while(scanf("%s", str) != EOF)
	{
		len = strlen(str);
		relNum = 0;

		for(l = 1;l < len;l++)
		{
			ansNum = 0;
			for(i = l - 1;i < len;i++)
			{
				for(j = 0;j < l;j++)
					save[j] = str[i - l + 1 + j];
				save[l] = '\0';

				for(w = 0;w < ansNum;w++)
					if (strcmp(save, ans[w].ss) == 0)
					{
						ans[w].time++;
						break;
					}
				if (w >= ansNum)
				{
					strcpy(ans[ansNum].ss, save);
					ans[ansNum].time = 1;
					ansNum++;
				}
			}

			for(w = 0;w < ansNum;w++)
				if (ans[w].time > 1)
				{
					strcpy(relAns[relNum].ss ,ans[w].ss);
					relAns[relNum].time = ans[w].time;
					relNum++;
				}
		}
	
		qsort(relAns, relNum, sizeof(relAns[0]), cmp);
		for(i = 0;i < relNum;i++)
			printf("%s %d\n", relAns[i].ss, relAns[i].time);
	}
	return 0;
}
