/*
描述
你手中有些从右向左读的诗句，比如“rose red red a like is luve my O”。
现在为了阅读这些美妙的诗句，你要把这些语句反转成正常的从左到右，即“O my luve is like a red red rose”。
输入
每一行为原来从右向左读的诗句S。该诗句中不包含任何标点符号，单词间以空格隔开。每条诗句最多包含 50个单词，每个单词最多包含50个字符。
输出
每一行为正常的从左到右读的诗句。
样例输入
rose red red a like is luve my O
June in sprung newly That's
melodie the like is luve my O
tune in played sweetly That's
样例输出
O my luve is like a red red rose
That's newly sprung in June
O my luve is like the melodie
That's sweetly played in tune
*/


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char str[100][100];
	while(cin >> str[0])
	{
		int i = 1;
		char c;
		while(c = getchar(), c != '\n')
			cin >> str[i++];

		while(i--)
		{
			if (i == 0)
				cout << str[i] << endl;
			else
				cout << str[i] << " ";
		}
	}
	return 0;
}
