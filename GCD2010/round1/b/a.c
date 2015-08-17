#include <iostream>
#include <string>
#include <set>
using namespace std;

#define N 105
#define MAX 105

int main()
{
	string dir[N * N];
	string temp;
	char createDir[MAX];
	int i, j, k;
	int m, n;
	int cnt;
	int icase, ncase;
	set <string> dirSet;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		dirSet.clear();
		scanf("%d %d", &n, &m);
		for(i = 0;i < n;i++)
		{
			cin>>dir[i];
			dirSet.insert(dir[i]);
		}
		
		cnt = n;
		for(i = 0;i < m;i++)
		{
			scanf("%s", createDir);
			for(j = 1; createDir[j] !='\0';j++)
				if (createDir[j] == '/')
				{
					temp = string(createDir, j);
					if (dirSet.find(temp) == dirSet.end())
					{
						dirSet.insert(temp);
						cnt++;
					}
				}
			temp = string(createDir, j);
			if (dirSet.find(temp) == dirSet.end())
			{
				dirSet.insert(temp);
				cnt++;
			}
		}
		printf("Case #%d: %d\n", icase, cnt - n);

	}
}
