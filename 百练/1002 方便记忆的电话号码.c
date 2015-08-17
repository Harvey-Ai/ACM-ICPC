/*
描述
英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。


输入
第一行是一个正整数n（n <= 100000），表示列表中的电话号码数。
其后n行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。
输出
输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。

如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
样例输入
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
样例输出
310-1010 2
487-3279 4
888-4567 3 
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct phoneNum
{
	string str;
	int count;
};

bool cmp(const struct phoneNum a, const struct phoneNum b)
{
	return a.str > b.str ? 0 : 1;
}

int main()
{
	int n;
	string num;
	char str[100];
	int i, j, k;
	map<string, int> dir;
	cin >> n;
	struct phoneNum resNums[100005];

	for(i = 0;i < n;i++)
	{
		cin >> str;
		num.clear();
		for(j = 0;str[j] != '\0';j++)
		{
			if (str[j] <= '9' && str[j] >= '0')
				num += str[j];
			else if (str[j] == 'A' || str[j] == 'B' || str[j] == 'C')
				num += "2";
			else if (str[j] == 'D' || str[j] == 'E' || str[j] == 'F')
				num += "3";
			else if (str[j] == 'G' || str[j] == 'H' || str[j] == 'I')
				num += "4";
			else if (str[j] == 'J' || str[j] == 'K' || str[j] == 'L')
				num += "5";
			else if (str[j] == 'M' || str[j] == 'N' || str[j] == 'O')
				num += "6";
			else if (str[j] == 'P' || str[j] == 'R' || str[j] == 'S')
				num += "7";
			else if (str[j] == 'T' || str[j] == 'U' || str[j] == 'V')
				num += "8";
			else if (str[j] == 'W' || str[j] == 'X' || str[j] == 'Y')
				num += "9";
		}
	//	cout << "fda " << num << endl;
		dir[num]++;
	}

	map<string, int>::iterator it = dir.begin();
	for(it =  dir.begin(), k = 0;it != dir.end();it++)
		if (it->second > 1)
		{
		//	cout << "fdsafds" << it->first << endl;
			resNums[k].count = it->second;
			resNums[k++].str = it->first;
		}

	sort(&resNums[0], &resNums[k], cmp);
	for(i = 0;i < k;i++)
		cout << resNums[i].str.substr(0, 3) << "-" << resNums[i].str.substr(3, 7) << " " << resNums[i].count << endl;
	if (k == 0)
		cout << "No duplicates." << endl;

	return 0;
}
