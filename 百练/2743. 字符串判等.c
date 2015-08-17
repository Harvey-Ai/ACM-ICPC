/*
描述
判断两个由大小写字母和空格组成的字符串在忽略大小写和压缩掉空格后是否相等
输入
第1行是测试数据的组数n，每组测试数据占2行，第1行是第一个字符串s1，第2行是第二个字符串s2。
每组测试数据之间有一个空行，每行数据不超过100个字符（注意字符串的长度可能为0）
输出
n行，相等则输出YES，否则输出NO
样例输入
3

a A bb BB ccc CCC
Aa BBbb CCCccc

a              dfadf              fasdf
adasddfsfsaf
样例输出
YES
YES
NO
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	char str1[1000], str2[1000];
	char ss1[1000], ss2[1000];
	int i, j, n;

	cin >> n;
	while(n--)
	{
		getchar();
		cin.getline(str1, 1000, '\n');
		cin.getline(str2, 1000, '\n');
		for(i = 0, j = 0;str1[i] != '\0';i++)
			if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
				ss1[j++] = str1[i] ;
		ss1[j] = '\0';
		for(i = 0, j = 0;str2[i] != '\0';i++)
			if ((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z'))
				ss2[j++] = str2[i];
		ss2[j] = '\0';

		for(i = 0;ss1[i] != '\0';i++)
			if (ss1[i] >= 'A' && ss1[i] <= 'Z')
				ss1[i] = 'a' + ss1[i] - 'A';
		for(i = 0;ss2[i] != '\0';i++)
			if (ss2[i] >= 'A' && ss2[i] <= 'Z')
				ss2[i] = 'a' + ss2[i] - 'A';

		if (strcmp(ss1, ss2) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
