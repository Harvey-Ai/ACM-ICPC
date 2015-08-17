/*
题目描述：
    如果A，B是C的父母亲，则A，B是C的parent，C是A，B的child，如果A，B是C的（外）祖父，祖母，则A，B是C的grandparent，C是A，B的grandchild，如果A，B是C的（外）曾祖父，曾祖母，则A，B是C的great-grandparent，C是A，B的great-grandchild，之后再多一辈，则在关系上加一个great-。
输入：
    输入包含多组测试用例,每组用例首先包含2个整数n（0<=n<=26）和m（0<m<50）, 分别表示有n个亲属关系和m个问题, 然后接下来是n行的形式如ABC的字符串，表示A的父母亲分别是B和C，如果A的父母亲信息不全，则用-代替，例如A-C,再然后是m行形式如FA的字符串,表示询问F和A的关系。
    当n和m为0时结束输入。
输出：
    如果询问的2个人是直系亲属，请按题目描述输出2者的关系，如果没有直系关系，请输出-。
    具体含义和输出格式参见样例.
样例输入：
3 2
ABC
CDE
EFG
FA
BE
0 0
样例输出：
great-grandparent
-
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, m;
	int i, j, k;
	int g[40][40];
	char str[100];

	while(cin >> n >> m, m || n)
	{
		memset(g, -1, sizeof(g));
		for(i = 0;i < n;i++)
		{
			cin >> str;
			if (str[1] != '-')
				g[str[1] - 'A'][str[0] - 'A'] = 1;
			if (str[2] != '-')
				g[str[2] - 'A'][str[0] - 'A'] = 1;
		}

		for(k = 0;k < 26;k++)
			for(i = 0;i < 26;i++)
			{
				if (i == k)
					continue;
				for(j = 0;j < 26;j++)
				{
					if (j == i || j == k)
						continue;
					if (g[i][k] != -1 && g[k][j] != -1 && (g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j]))
						g[i][j] = g[i][k] + g[k][j];
				}
			}


		for(i = 0;i < m;i++)
		{
			cin >> str;
			if (g[str[0] - 'A'][str[1] - 'A'] != -1)
			{
				if (g[str[0] - 'A'][str[1] - 'A'] == 1)
					cout << "parent" << endl;
				else if (g[str[0] - 'A'][str[1] - 'A'] >= 2)
				{
					for(j = 0;j < g[str[0] - 'A'][str[1] - 'A'] - 2;j++)
						cout << "great-";
					cout << "grandparent" << endl;
				}
			}
			else if (g[str[1] - 'A'][str[0] - 'A'] != -1)
			{
				if (g[str[1] - 'A'][str[0] - 'A'] == 1)
					cout << "child" << endl;
				else if (g[str[1] - 'A'][str[0] - 'A'] >= 2)
				{
					for(j = 0;j < g[str[1] - 'A'][str[0] - 'A'] - 2;j++)
						cout << "great-";
					cout << "grandchild" << endl;
				}
			}
			else
				cout << "-" << endl;
		}
	}
	return 0;
}
