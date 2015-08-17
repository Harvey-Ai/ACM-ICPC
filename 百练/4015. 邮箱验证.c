/*
描述
POJ 注册的时候需要用户输入邮箱，验证邮箱的规则包括：
1)有且仅有一个'@'符号
2)'@'和'.'不能出现在字符串的首和尾
3)'@'之后至少要有一个'.'，并且'@'不能和'.'直接相连
满足以上3条的字符串为合法邮箱，否则不合法，
编写程序验证输入是否合法
输入
输入包含若干行，每一行为一个代验证的邮箱地址，长度小于100
输出
每一行输入对应一行输出
如果验证合法，输出 YES
如果验证非法：输出 NO
样例输入
    .a@b.com
    pku@edu.cn
    cs101@gmail.com
    cs101@gmail
样例输出
    NO
    YES
    YES
    NO
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[1000];
	int i;
	int aCount;
	int posA, posD;

	while(cin >> str)
	{
		aCount = 0;
		for(i = 0;str[i] != '\0';i++)
			if (str[i] == '@')
				aCount++;
		if (aCount != 1)
		{
			cout << "NO" << endl;
			continue;
		}

		if (str[0] == '@' || str[strlen(str) - 1] == '@' || str[0] == '.' || str[strlen(str) - 1] == '.')
		{
			cout << "NO" << endl;
			continue;
		}

		posA = -1;
		posD = -1;
		for(i = 0;str[i] != '\0';i++)
			if (str[i] == '@')
				posA = i;
			else if (str[i] == '.')
				posD = i;

		if (posA > posD || posA == -1 || posD == -1)
		{
			cout << "NO" << endl;
			continue;
		}
		for(i = 0;str[i] != '\0';i++)
			if (str[i] == '@' && str[i + 1] == '.' || str[i] == '.' && str[i + 1] == '@')
			{
				cout << "NO" << endl;
				break;
			}

		if (str[i] == '\0')
			cout << "YES" << endl;
	}
	return 0;
}
