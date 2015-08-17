/*
题目描述：
    每天第一个到机房的人要把门打开，最后一个离开的人要把门关好。现有一堆杂乱的机房签到、签离记录，请根据记录找出当天开门和关门的人。
输入：
    测试输入的第一行给出记录的总天数N ( N> 0 )，下面列出了N天的记录。 
    每天的记录在第一行给出记录的条目数M (M > 0 )，下面是M行，每行的格式为 

    证件号码 签到时间 签离时间 

    其中时间按“小时:分钟:秒钟”（各占2位）给出，证件号码是长度不超过15的字符串。
输出：
    对每一天的记录输出1行，即当天开门和关门人的证件号码，中间用1空格分隔。 
    注意：在裁判的标准测试输入中，所有记录保证完整，每个人的签到时间在签离时间之前，且没有多人同时签到或者签离的情况。
样例输入：
3
1
ME3021112225321 00:00:00 23:59:59
2
EE301218 08:05:35 20:56:35
MA301134 12:35:45 21:40:42
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
样例输出：
ME3021112225321 ME3021112225321
EE301218 MA301134
SC3021234 CS301133

*/

#include <iostream>
#include <cstring>
using namespace std;

struct tt
{
	char card[100], tm1[100], tm2[100];
};

int main()
{
	int ncase;
	int i, n;
	struct tt p[500];
	char comeT[100], goT[100], first[100], end[100];
	cin >> ncase;

	while(ncase--)
	{
		cin >> n;
		for(i = 0;i < n;i++)
			cin >> p[i].card >> p[i].tm1 >> p[i].tm2;

		strcpy(first, p[0].card);
		strcpy(comeT, p[0].tm1);
		for(i = 1;i < n;i++)
			if (strcmp(comeT, p[i].tm1) > 0)
			{
				strcpy(first, p[i].card);
				strcpy(comeT, p[i].tm1);
			}

		strcpy(end, p[0].card);
		strcpy(goT, p[0].tm2);
		for(i = 1;i < n;i++)
			if (strcmp(goT, p[i].tm2) < 0)
			{
				strcpy(end, p[i].card);
				strcpy(goT, p[i].tm2);
			}
		cout << first << " " << end << endl;
	}
	return 0;
}
