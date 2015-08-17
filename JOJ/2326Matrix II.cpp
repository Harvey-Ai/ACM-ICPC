#include <iostream>
using namespace std;
int main()
{
	int n,m,i,j,max;
	bool a[1000];
	while(cin>>n>>m)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];

		