/*
描述
一个数如果从左往右读和从右往左读数字是相同的，则称这个数是回文数，如121，1221，15651都是回文数。给定位数n，找出所有既是回文数又是素数的n位十进制数。（注：不考虑超过整型数范围的情况）。
输入
位数n,其中1<=n<=9。
输出
第一行输出满足条件的素数个数。
第二行按照从小到大的顺序输出所有满足条件的素数，两个数之间用一个空格区分。
样例输入
1
样例输出
4
2 3 5 7
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int prime[100005];
int pnum;
int n;
char str[100];
int num;
int res[100000];

int getp()
{
	int i, j;
	bool flag[100005];
	memset(flag, 0, sizeof(flag));
	for(i = 2;i < 100001;i++)
		for(j = 2;j * j <= i;j++)
			if (i % j == 0)
			{
				flag[i] = 1;
				break;
			}
	pnum = 0;
	for(i = 2;i < 100001;i++)
		if(!flag[i])
			prime[pnum++] = i;
// 	cout << pnum << endl;
}

int check(int a)
{
	if (a == 1)
		return 0;
	for(int i = 0;i < pnum && a > prime[i];i++)
		if (a % prime[i] == 0)
			return 0;
	return 1;
}

int dfs(int pos)
{
//	cout << pos << n << endl;
	int i;
	if (pos == (n + 1) / 2)
	{
		for(i = pos;i < n;i++)
			str[i] = str[n - i - 1];

	//	str[n] = '\0';
	//	cout << pos << " " << str << endl;
		int temp = 0;
		for(i = 0;i < n;i++)
		{
			temp *= 10;
			temp += str[i] - '0';
		}
		//cout << temp << endl;
		if (check(temp))
			res[num++] = temp;
		return 0;
	}
	int first;
	if (pos == 0)
		first = 1;
	else
		first = 0;
	for(i = first;i < 10;i++)
	{
		str[pos] = i + '0';
		dfs(pos + 1);
	}
}

int main()
{
	getp();
//	cout << prime[pnum - 1] << endl;
	cin >> n;
	num = 0;
		//cout << "fda " << endl;
	dfs(0);
	sort(&res[0], &res[num]);
	cout << num << endl;
	for(int i = 0;i < num;i++)
		cout << res[i] << " ";
	cout << endl;
	//	if (num == 0)
	//		cout << 0 << endl;
	return 0;
}
