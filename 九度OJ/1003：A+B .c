/*
题目描述：
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。
输入：
输入包含多组数据数据，每组数据占一行，由两个整数A和B组成（-10^9 < A,B < 10^9）。
输出：
请计算A+B的结果，并以正常形式输出，每组数据占一行。
样例输入：
-234,567,890 123,456,789
1,234 2,345,678
样例输出：
-111111101
2346912
*/


#include <iostream>
using namespace std;

int main()
{
	char str1[100], str2[100], ss1[100], ss2[100];
	int i, j;

	while(cin >> str1 >> str2)
	{
		for(i = 0, j = 0;str1[i] != '\0';i++)
			if (str1[i] >= '0' && str1[i] <= '9' || str1[i] == '-')
				ss1[j++] = str1[i];
		ss1[j] = '\0';

		for(i = 0, j = 0;str2[i] != '\0';i++)
			if (str2[i] >= '0' && str2[i] <= '9'|| str2[i] == '-')
				ss2[j++] = str2[i];
		ss2[j] = '\0';

		int flag1,  flag2;
		flag1 = flag2 = 0;
		int num1 = 0;
		i = 0;
		if (ss1[i] == '-')
		{
			flag1 = 1;
			i++;
		}
		for(;ss1[i] != '\0';i++)
		{
			num1 *= 10;
			num1 += ss1[i] - '0';
		}

		int num2 = 0;
		i = 0;
		if (ss2[i] == '-')
		{
			flag2 = 1;
			i++;
		}
		for(;ss2[i] != '\0';i++)
		{
			num2 *= 10;
			num2 += ss2[i] - '0';
		}
		if (flag1) num1 = -num1;
		if (flag2) num2 = -num2;
		cout << num1 + num2 << endl;
	}
	return 0;
}
