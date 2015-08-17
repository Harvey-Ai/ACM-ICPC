/*
描述
两个十进制非负整数M和N，计算二者的差，既M-N。
M、N最多可以是长度为200位的整数。
输入
多组数据，每组数据先是一行表示M，然后一行表示N。M和N开头均无冗余的0。
输出
每行一个数，表示M-N，开头不能有冗余的0，既不能输出05这样的数，而应该直接输出5。
样例输入
9999
4567
0
1
样例输出
5432
-1
*/


#include <iostream>
#include <cstring>
using namespace std;

void distract(char *s1, char *s2)
{
	int equal = 0;
	char res[500];
	int i, j;
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1 > len2)
		equal = 1;
	else
		if (len1 < len2)
			equal = -1;
		else
		{
			for(i = 0;i < len1;i++)
				if (s1[i] != s2[i])
					break;
			if (s1[i] > s2[i]) equal = 1;
			else if (s1[i] < s2[i]) equal = -1;
		}

	//cout << s1 << endl << s2 << endl;
	//cout << equal << endl;
	if (equal == 0)
	{
		cout << "0" << endl;
		return;
	}
	if (equal == -1)
	{
		char *s = s1;
		s1 = s2;
		s2 = s;

		int len = len1;
		len1 = len2;
		len2 = len;
	}

	int borrow = 0;
	
	for(i = len1 - 1, j = len2 - 1;i >= 0;i--, j--)
	{
		int wei = s1[i] - borrow;
		if (j >= 0)
			wei -= s2[j];
		else
			wei -= '0';
		borrow = 0;
		while (wei < 0)
		{
			borrow++;
			wei += 10;
		}
		res[i] = wei + '0';
	}

	if (equal == -1)
		cout << "-";

	for(i = 0;i < len1;i++)
		if (res[i] != '0')
			break;

	for(;i < len1;i++)
		cout << res[i];
	cout << endl;
}

int main()
{
	char str1[500], str2[500];

	while(cin >> str1 >> str2)
		distract(str1, str2);
	return 0;
}
