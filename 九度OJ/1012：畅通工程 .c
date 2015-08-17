/*
题目描述：
    某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入：
    测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
    注意:两个城市之间可以有多条道路相通,也就是说
    3 3
    1 2
    1 2
    2 1
    这种输入也是合法的
    当N为0时，输入结束，该用例不被处理。
输出：
    对每个测试用例，在1行里输出最少还需要建设的道路数目。
样例输入：
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
样例输出：
1
0
2
998

*/

#include <iostream>
#include <cstring>
using namespace std;

int g[1005][1005];
int used[1005];
int n;

int dfs(int p)
{
	for(int i = 1;i <= n;i++)
		if (i != p && !used[i] && g[p][i])
		{
			used[i] = 1;
			dfs(i);
		}
}

int main()
{
	int i, m;
	int a, b;
	while(cin >> n, n)
	{
		memset(g, 0, sizeof(g));
		cin >> m;
		for(i = 0; i < m;i++)
		{
			cin >> a >> b;
			g[a][b] = g[b][a] = 1;

		}

		int res = 0;
		memset(used, 0, sizeof(used));
		
		for(i = 1;i <= n;i++)
			if (!used[i])
			{
				used[i] = 1;
		//		cout << i << endl;
				res++;
				dfs(i);
			}
		cout << res - 1 << endl;
	}
	return 0;
}
