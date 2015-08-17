/*
题目描述：
    读入两个不超过25位的火星正整数A和B，计算A+B。需要注意的是：在火星上，整数不是单一进制的，第n位的进制就是第n个素数。例如：地球上的10进制数2，在火星上记为“1,0”，因为火星个位数是2进制的；地球上的10进制数38，在火星上记为“1,1,1,0”，因为火星个位数是2进制的，十位数是3进制的，百位数是5进制的，千位数是7进制的……
输入：
    测试输入包含若干测试用例，每个测试用例占一行，包含两个火星正整数A和B，火星整数的相邻两位数用逗号分隔，A和B之间有一个空格间隔。当A或B为0时输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出1行，即火星表示法的A+B的值。
样例输入：
1,0 2,1
4,2,0 1,2,0
1 10,6,4,2,1
0 0
样例输出：
1,0,1
1,1,1,0
1,0,0,0,0,0
*/

#include <iostream>
using namespace std;

int quan[100], prime[100];
char res[100];
int init()
{
	int num, i, j;
	prime[0] = 2;
	num = 1;
	i = 3;
	while(num < 30)
	{
		for(j = 2;j * j <= i;j++)
			if (i % j == 0)
				break;
		if (j * j > i)
			prime[num++] = i;
		i++;
	}
	quan[0] = 1;

	for(i = 1;i < 30;i++)
		quan[i] = quan[i - 1] * prime[i - 1];
}

void covert(int a)
{
//	cout << a << endl;
	int i, j;
	for(i = 0;i < 30;i++)
		if (a < quan[i])
			break;

	i--;
//	cout << i << endl;
	for(j = 0;i >= 0;i--)
	{
		res[j++] = a / quan[i] + '0';
		a = a % quan[i];
	}
	res[j] = '\0';
//	cout << res << endl;

	cout << (char)(res[0]);
	for(i = 1;i < j;i++)
		cout << "," << (char)(res[i]);
	cout << endl;
}

int main()
{
	char str1[100], str2[100], ss1[100], ss2[100];
	int i, j;
	init();

	while(cin >> str1 >> str2)
	{
		if (strcmp(str1, "0") == 0 && strcmp(str2, "0") == 0)
			break;

		for(i = 0, j = 0;str1[i] != '\0';i++)
			if (str1[i] != ',')
				ss1[j++] = str1[i];
		ss1[j] = '\0';

		for(i = 0, j = 0;str2[i] != '\0';i++)
			if (str2[i] != ',')
				ss2[j++] = str2[i];
		ss2[j] = '\0';

		int num1 = 0;
		for(j = 1, i = strlen(ss1) - 1;i >= 0;i--,j++)
		{
			f
			num1 += (ss1[i] - '0') * quan[j - 1];
		}

		int num2 = 0;
		for(j = 1, i = strlen(ss2) - 1;i >= 0;i--,j++)
		{
		//	cout << (ss2[i] - '0') << " " << quan[j - 1] << endl;
			num2 += (ss2[i] - '0') * quan[j - 1];
		}

		//cout << num1 << " " << num2 << endl;
		covert(num1 + num2);
	//	cout << res << endl;
	}
	return 0;
}
