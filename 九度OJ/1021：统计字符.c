/*
题目描述：
    统计一个给定字符串中指定的字符出现的次数。
输入：
    测试输入包含若干测试用例，每个测试用例包含2行，第1行为一个长度不超过5的字符串，第2行为一个长度不超过80的字符串。注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。当读到'#'时输入结束，相应的结果不要输出。
输出：
    对每个测试用例，统计第1行中字符串的每个字符在第2行字符串中出现的次数，按如下格式输出：
    c0 n0
    c1 n1
    c2 n2
    ... 
    其中ci是第1行中第i个字符，ni是ci出现的次数。
样例输入：
I
THIS IS A TEST
i ng
this is a long test string
#
样例输出：
I 2
i 3
  5
n 2
g 2

*/

#include <iostream>
using namespace std;

int main()
{
	char str[1000], ss[1000];
	int i, j;
	while(cin.getline(str, 1000, '\n'))
	{
		if (str[0] == '#')
			break;
		cin.getline(ss, 1000, '\n');
		
		for(i = 0;str[i] != '\0';i++)
		{
			int cnt = 0;
			for(j = 0;ss[j] != '\0';j++)
				if (str[i] == ss[j])
					cnt++;
			cout << str[i] << " " << cnt << endl;
		}
	}
	return 0;
}
