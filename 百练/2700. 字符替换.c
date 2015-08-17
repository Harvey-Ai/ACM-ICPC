/*
描述
把一个字符串中特定的字符用给定的字符替换,得到一个新的字符串.
输入
输入有多行,第一行是要处理的字符串的数目n.
其余个行每行由三个字符串组成,第一个字符串是待替换的字符串,字符串长度小于等于30个字符;
第二个字符串是一个字符,为被替换字符;
第三个字符串是一个字符,为替换后的字符.
输出
有多行,每行输出对应的替换后的字符串.
样例输入
1
hello-how-are-you o O
样例输出
hellO-hOw-are-yOu
*/


#include <iostream>
using namespace std;

int main()
{
	int ncase;
	int i;
	char old, neww;
	char str[10000];
	cin >> ncase;

	while(ncase--)
	{
		cin >> str;
		cin >> old >> neww;

		for(int i = 0;str[i] != '\0';i++)
			if (str[i] == old)
				str[i] = neww;
		cout << str << endl;
	}
	return 0;
}
