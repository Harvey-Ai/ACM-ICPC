/*
题目描述：
每个人有自己的lucky number，小A也一样。不过他的lucky number定义不一样。他认为一个序列中某些数出现的次数为n的话，都是他的lucky number。但是，现在这个序列很大，他无法快速找到所有lucky number。既然这样，他就想找到那些不是lucky number。
输入：
输入有两行.
第一行有n和m。n表示出现次数为n的是lucky number，m表示序列的长度。2<=n<=10,m<=10^6，m%n!=0。
第二行为序列元素，每个元素都是正整数。
输出：
输出那个不是lucky number的数。题目保证非lucky number只有一个。
样例输入：
2 5
1 1 2 2 3
样例输出：
3
*/

#include <iostream>
#include <map>
using namespace std;


map<int, int> luck;
int main()
{
	int n, m;
	int i, a;
	while(cin >> m >> n)
	{
		luck.clear();
		for(i = 0;i < n;i++)
		{
			cin >> a;
			if (luck.count(a) == 0)
				luck[a] = 1;
			else
				luck[a]++;
		}
		map<int, int>::iterator it;
		for(it = luck.begin();it != luck.end();it++)
			if (it->second != m)
			{
				cout << it->first << endl;
				break;
			}
	}
	return 0;
}

