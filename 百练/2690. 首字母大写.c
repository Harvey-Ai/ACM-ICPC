/*
描述
对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
输入
输入一行：待处理的字符串（长度小于80）。
输出
输出一行：转换后的字符串。
样例输入
if so, you already have a google account. you can sign in on the right.
样例输出
If So, You Already Have A Google Account. You Can Sign In On The Right.
*/


#include <iostream>
using namespace std;

int main()
{
	char str[1000];
	cin.getline(str, 100, '\n');

	int flag = 0;
	for(int i = 0;str[i] != '\0';i++)
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n')
		{
			if (!flag)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] = str[i] - 'a' + 'A';
				flag = 1;
			}
		}
		else
			flag = 0;
	cout << str << endl;
	return 0;
}
