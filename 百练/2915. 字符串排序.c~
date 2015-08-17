/*
描述
先输入你要输入的字符串的个数。然后换行输入该组字符串。每个字符串以回车结束，每个字符串少于一百个字符。如果在输入过程中输入的一个字符串为“stop”，也结束输入。
然后将这输入的该组字符串按每个字符串的长度，由小到大排序，按排序结果输出字符串。
输入
字符串的个数，以及该组字符串。每个字符串以‘\n’结束。如果输入字符串为“stop”，也结束输入.
输出
将输入的所有字符串按长度由小到大排序输出(如果有“stop”，不输出“stop”)。

样例输入
5
sky is grey
cold
very cold
stop
3
it is good enough to be proud of
good
it is quite good
样例输出
cold
very cold
sky is grey
good
it is quite good
it is good enough to be proud of
*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct ss
{
	char str[1000];
};

bool cmp(const struct ss a, const struct ss b)
{
	if (strlen(a.str) <= strlen(b.str))
		return 1;
	else
		return 0;
}

int main()
{
	struct ss strins[100];
	int n;
	int i;
	while(cin >> n)
	{
		getchar();
		for(i = 0;i < n;i++)
		{
			cin.getline(strins[i].str, 1000, '\n');
			if (strcmp(strins[i].str, "stop") == 0)
			{
				n = i;
				break;
			}
		}
	//	cout << n << endl;
		sort(&strins[0], &strins[n], cmp);
		for(i = 0;i < n;i++)
			cout << strins[i].str << endl;
	}
	return 0;
}
