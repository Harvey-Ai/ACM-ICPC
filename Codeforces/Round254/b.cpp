#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 1000;
int uN, vN; // u, v数目，要初始化！！！
bool g[MAXN][MAXN]; // g[i][j] 表示xi与yj相连
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check
bool SearchPath(int u){
	int v;
	for(v = 0; v < vN; v++)
		if(g[u][v] && !chk[v])
		{
			chk[v] = true;
			if(yM[v] == -1 || SearchPath(yM[v]))
			{
				yM[v] = u; xM[u] = v;
				return true ;
			}
		}
	return false ;
}
int MaxMatch(){
	int u, ret = 0 ;
	memset(xM, -1, sizeof (xM));
	memset(yM, -1, sizeof (yM));
	for(u = 0; u < uN; u++)
		if(xM[u] == -1){
			memset(chk, false, sizeof (chk));
			if(SearchPath(u)) ret++;
		}
	return ret;
}

int main()
{
	memset(g, 0, sizeof(g));
	int n, m;
	cin >> n >> m;
	uN = vN = n;
	for(int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;b--;
		g[a][b] = 1;
	}
	int matched = MaxMatch();
//	cout << matched << endl;
	double res = pow(2, matched);
	printf("%.0f\n", res);
	return 0;
}
