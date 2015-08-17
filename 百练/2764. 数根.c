/*
描述
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根。如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。

比如，对于24来说，把2和4相加得到6，由于6是一位数，因此6是24的数根。再比如39，把3和9加起来得到12，由于12不是一位数，因此还得把1和2加起来，最后得到3，这是一个一位数，因此3是39的数根。
输入
输入包括一些正整数(小于101000)，每个一行。输入的最后一行是0，表示输入的结束，这一行不用处理。
输出
对每个正整数，输出它的数根。每个结果占据一行。
样例输入
24
39
0
样例输出
6
3
*/


#include <iostream>
#include <string>
using namespace std;

void add(string &a, char b)
{
	int flag = b - '0';
	int i;

//	cout << flag << endl;
	for(i = 0;i < a.length();i++)
	{
		a[i] += flag;
		flag = 0;
		if (a[i] > '9')
		{
			a[i] -= 10;
			flag = 1;
		}
		if (flag == 0)
			break;
	}
	if (flag == 1)
		a.append(string("1"));
}

int main()
{
	string str;
	string temp;
	int i;

	while(cin>>str)
	{
		if (str == "0")
			break;
		else
		{
			while(str.length() > 1)
			{
			//	cout << "str len" << str.length() << endl;
				temp = "0";
				for(i = 0;i < str.length();i++)
				{
					add(temp, str[i]);
			//		cout << temp << endl;
				}
			//	cout << temp << endl;
				str = temp;
			}
			cout << str <<endl;
		}
	}
	return 0;
}
