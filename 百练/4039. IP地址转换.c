/*
描述
IP地址总是由4个0-255的数字以"."隔开的形式来显示给用户，例如192.168.0.1。在计算机中，一个IP地址用4字节来依次存储其从右到左的4个数字部分，每个字节（8比特）以2进制的形式存储相应的IP地址数字，请你实现一个从IP地址的显示格式到计算机存储格式的转换。

输入
每行输入一个IP地址，如果输入为-1，结束输入
输出
每行输出一个IP地址在计算机存储中以二进制表示的4字节内容
样例输入
192.168.0.1
255.255.0.0
1.0.0.1
-1
样例输出
11000000101010000000000000000001
11111111111111110000000000000000
00000001000000000000000000000001
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[100];
	char res[100];
	int pos, num;
	int i, k, j;
	while(cin>>str)
	{
		if (strcmp(str, "-1") == 0)
			break;

		k = 0;
		pos = 0;
		for(i = 0;str[i] != '\0';i++)
			if (str[i] == '.')
			{
				num = 0;
				int temp = 1;
				for(j = i - 1;j >= pos;j--)
				{
					num += (str[j] - '0') * temp;
					temp *= 10;
				}
				//cout << num << endl;
				for(j = 0;j < 8;j++)
				{
					if (num & 128)
						res[k++] = '1';
					else
						res[k++] = '0';
					num <<= 1;
				}
				pos = i + 1;
			}
		int temp = 1;
		num = 0;
		for(j = i - 1;j >= pos;j--)
		{
			num += (str[j] - '0') * temp;
			temp *= 10;
		}
		for(j = 0;j < 8;j++)
		{
			if (num & 128)
				res[k++] = '1';
			else
				res[k++] = '0';
			num <<= 1;
		}
		res[k] = '\0';
		cout << res << endl;
	}
	return 0;
}
