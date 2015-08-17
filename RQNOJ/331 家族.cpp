/*
题目描述
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
输入格式
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Ai和Bi具有亲戚关系。
接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出格式
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。

样例输入
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

样例输出
Yes
Yes
No
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int uSet[5005];

void makeSet()
{
	memset(uSet, -1 , sizeof(uSet));
}

int getF(int u)
{
	int root = u;
	while(uSet[root] >= 0)
		root = uSet[root];

	while(u != root)
	{
		int temp = uSet[u];
		uSet[u] = root;
		u = temp;
	}
	
	return root;
}

void merge(int u, int v)
{
	int rootU = getF(u);
	int rootV = getF(v);
	if (rootV != rootU)
	{
		uSet[rootV] += uSet[rootU];
		uSet[rootU] = rootV;
	}
}

int main()
{
	int n, m, q;
	makeSet();
	cin >> n >> m >> q;

	for(int i = 0;i < m;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		merge(a, b);
	}

	for(int i = 0;i < q;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		if (getF(a) == getF(b))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
