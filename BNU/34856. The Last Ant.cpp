#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, l;
	char dir[25];
    int	pos[25];

	while(cin >> n >> l, n || l)
	{
		for(int i = 0;i < n;i++)
			cin >> dir[i] >> pos[i];
		int timeSum = 0;
		int antNum = n;
		int lastIndex = -1;
		while(antNum > 0)
		{
			int flag[25];
			memset(flag, 0, sizeof(flag));
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
				{
					if (i == j)
						continue;
					if (dir[i] != dir[j]  && pos[i] == pos[j])
						flag[i] = flag[j] = 1;
				}
			for(int i = 0;i < n;i++)
				if (flag[i])
					dir[i] = (int)'R' + 'L' - dir[i];

			for(int i = 0;i < n;i++)
				if (dir[i] == 'R')
					pos[i]++;
				else
					pos[i]--;
			
			lastIndex = -1;
			for(int i = 0;i < n;i++)
				if (pos[i] == 0 || pos[i] == l)
				{
					antNum--;
					if (lastIndex == -1 || dir[i] == 'L')
						lastIndex = i + 1;
				}
			timeSum++;
		}

		cout << timeSum << " " << lastIndex << endl;
	}

	return 0;
}
