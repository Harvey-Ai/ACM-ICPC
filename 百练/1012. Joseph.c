/*
描述
The Joseph's problem is notoriously known. For those who are not familiar with the original problem: from among n people, numbered 1, 2, . . ., n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give us the message about the incident. For example when n = 6 and m = 5 then the people will be executed in the order 5, 4, 6, 2, 3 and 1 will be saved.

Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy. 

输入
The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
输出
The output file will consist of separate lines containing m corresponding to k in the input file.
样例输入
3
4
0
样例输出
5
30

*/

#include <iostream>
#include <cstring>
using namespace std;

 

int p[100];
int work(int k, int m)
{
	int i;
	int pos = 0;
	int sum = 2 * k;
	for(i = 0;i < k;i++)
	{
		pos = (pos + m - 1) % sum;
		if (pos < k)
			return 0;
		sum--;
	}
	return 1;
}

int main()
{
	int a;
	int ans;
	int ok, i;
	int c[15];
	for(a = 13;a > 0; a--)
	{
		ok = 0;
		for(i = 0;;i++)
		{
			for(ans = a + 1;ans <= a * 2;ans++)
			{
				memset(p, 0, sizeof(p));
				if (work(a, ans + i * 2 * a))
				{
					ok = 1;
					break;
				}
			}
			if (ok)
				break;
		}
		c[a] = ans + i * 2 * a;
	}
	while(cin >> a, a)
		cout << c[a] << endl;
	return 0;
}
