/*
描述
现在有一个仅由小写字母组成的字符串S，假定将字母a,b,c...z依次编号为1,2,3...26，现在要在S中找到所有长度为m的且字母编号和为q的子串。

输入
第一行输入N，表示测试数据的个数，以下N行每行包含一个测试数据
一行测试数据由三部分组成：字符串S(长度不超过100)、m（m小于S的长度）、q。
输出
输出符合条件的子串个数
后面每行输出一个相应的子串
样例输入
1
abcabc 3 6
样例输出
4
abc
bca
cab
abc
*/


/*
#include <iostream>
using namespace std;

int s, q;
char str[200];
char temp[200];

void dfs(int pos, int sum, int ppos)
{
//	cout << pos << " " << ppos << " " << sum << endl;
	if (ppos == s && sum == q)
	{
		temp[s] = '\0';
		cout << temp << endl;
		return;
	}
	if (str[pos] == '\0')
		return;
	if (ppos > s || (ppos == s && sum > q))
	{
	//	cout << ppos << " " << sum << endl;
		return;
	}
	if (sum > q || (sum == q && ppos < s))
	{
	//	cout << ppos << " " << sum << endl;
		return;
	}
	temp[ppos] = str[pos];
	dfs(pos + 1, sum + str[pos] - 'a' + 1, ppos + 1);
	//if (pos == 0)
	//cout << pos << " " << sum << endl;
	dfs(pos + 1, sum, ppos);
	//	if (pos == 0)
	//cout << pos << " " << sum << endl;
}

int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		cin >> str;
		cin >> s >> q;
		dfs(0, 0, 0);
	}
	return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
	int ncase;
	int s, q;
	int cnt;
	int i;
	char str[200];
	char res[200][200];
	char *posB, *posE, *p;
	cin >> ncase;

	while(ncase--)
	{
		cin >> str;
		cin >> s >> q;
		posB = &str[0];posE = &str[s - 1];
		int sum = 0;
		cnt = 0;
		for(p = posB;p <= posE;p++)
			sum += *p - 'a' + 1;
		if (sum == q)
		{
			for(i = 0, p = posB;p <= posE;p++,i++)
				res[cnt][i] = *p;
			res[cnt++][i] = '\0';
		}
		posB++;posE++;
		for(;*posE != '\0';posE++, posB++)
		{
			sum -= *(posB - 1) - 'a' + 1;
			sum += *posE - 'a' + 1;
			//cout << *(posB - 1) << " " << *posE << " " << sum << endl;
			if (sum == q)
			{	
				for(i = 0, p = posB;p <= posE;p++,i++)
					res[cnt][i] = *p;
				res[cnt++][i] = '\0';
			}
		}
		cout << cnt << endl;
		for(i = 0;i < cnt;i++)
			cout << res[i] << endl;
	}
	return 0;
}
