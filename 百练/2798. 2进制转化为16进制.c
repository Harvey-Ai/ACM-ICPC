/*
描述
输入一个2进制的数，要求输出该2进制数的16进制表示。
在16进制的表示中，A-F表示10-15
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个以0和1组成的字符串，字符串长度至少是1，至多是10000
输出
n行，每行输出对应一个输入。
样例输入
2
100000
111
样例输出
20
7
*/


#include <iostream>
#include <string>
using namespace std;

string work(string a)
{
	if (a == "0000") return "0";
	if (a == "0001") return "1";
	if (a == "0010") return "2";
	if (a == "0011") return "3";
	if (a == "0100") return "4";
	if (a == "0101") return "5";
	if (a == "0110") return "6";
	if (a == "0111") return "7";
	if (a == "1000") return "8";
	if (a == "1001") return "9";
	if (a == "1010") return "A";
	if (a == "1011") return "B";
	if (a == "1100") return "C";
	if (a == "1101") return "D";
	if (a == "1110") return "E";
	if (a == "1111") return "F";
}

int main()
{
	int n;
	int ind;
	
	cin >> n;
	string str;
	string res;

	while(n--)
	{
		cin >> str;
		while (str.length() % 4 != 0)
			str.insert(0, 1, '0');

		res = "";
		ind = 0;
		while(ind < str.length())
		{
			string temp = str.substr(ind, 4);
			res += work(temp);
			ind += 4;
		}
		cout << res << endl;
	}
	return 0;
}
