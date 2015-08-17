/*
描述
判断一个由a-z这26个字符组成的字符串中哪个字符出现的次数最多
输入
第1行是测试数据的组数n，每组测试数据占1行，是一个由a-z这26个字符组成的字符串
每组测试数据之间有一个空行，每行数据不超过1000个字符且非空
输出
n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数，中间是一个空格。
如果有多个字符出现的次数相同且最多，那么输出ascii码最小的那一个字符
样例输入
2
abbccc

adfadffasdf
样例输出
c 3
f 4
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int flag[40];
	int i;
	int max, id;
	char str[5000];
	cin >> n;
	while(n--)
	{
		cin >> str;
		for(i = 0;i < 26;i++)
			flag[i] = 0;
		for(i = 0;str[i] != '\0';i++)
			flag[str[i] - 'a']++;
		max = flag[0];
		id = 0;
		for(i = 0;i < 26;i++)
			if (max < flag[i])
			{
				id = i;
				max = flag[i];
			}
		cout<< (char)(id + 'a') << " " << flag[id] << endl;
	}
	return 0;
}
