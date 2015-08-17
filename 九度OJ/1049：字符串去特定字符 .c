/*
题目描述：
输入字符串s和字符c，要求去掉s中所有的c字符，并输出结果。
输入：
测试数据有多组，每组输入字符串s和字符c。
输出：
对于每组输入,输出去除c字符后的结果。
样例输入：
heallo
a
样例输出：
hello
*/


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char str[1000];
	int i, j;
	char ss[1000];

	while(cin.getline(str, 1000, '\n'))
	{
		char c = getchar();
		getchar();

		for(j = 0, i = 0;str[i] != '\0';i++)
			if (str[i] != c)
				ss[j++] = str[i];
		ss[j] = '\0';
		cout << ss << endl;
	}
	return 0;
}

