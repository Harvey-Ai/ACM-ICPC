#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int ncase;
	int i, j;
	char arr[10][10];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(int icase = 1;icase <= ncase;icase++)
	{
		for(i = 0;i < 4;i++)
			scanf("%s", arr[i]);
		getchar();

//		for(i = 0;i < 4;i++)
//			printf("%s\n", arr[i]);
		int winX = 0, winO = 0;
		for(i = 0;i < 4;i++)
		{
			for(j = 0;j < 4;j++)
				if (arr[i][j] != 'T' && arr[i][j] != 'O')
					break;
			if (j == 4)
				winO = 1;
			for(j = 0;j < 4;j++)
				if (arr[i][j] != 'T' && arr[i][j] != 'X')
					break;
			if (j == 4)
				winX = 1;

			for(j = 0;j < 4;j++)
				if (arr[j][i] != 'T' && arr[j][i] != 'O')
					break;
			if (j == 4)
				winO = 1;
			for(j = 0;j < 4;j++)
				if (arr[j][i] != 'T' && arr[j][i] != 'X')
					break;
			if (j == 4)
				winX = 1;
		}
		if (winO | winX == 0)
		{
			for(j = 0;j < 4;j++)
				if (arr[j][j] != 'O' && arr[j][j] != 'T')
					break;
			if (j == 4)
				winO = 1;
			for(j = 0;j < 4;j++)
				if (arr[j][j] != 'X' && arr[j][j] != 'T')
					break;
			if (j == 4)
				winX = 1;

			for(j = 3;j >= 0;j--)
				if (arr[3 - j][j] != 'O' && arr[3 - j][j] != 'T')
					break;
			if (j == -1)
				winO = 1;
			for(j = 3;j >= 0;j--)
				if (arr[3 - j][j] != 'X' && arr[3 - j][j] != 'T')
					break;
			if (j == -1)
				winX = 1;
		}
		if (winO)
			printf("Case #%d: O won\n", icase);
		else if (winX)
			printf("Case #%d: X won\n", icase);
		else
		{
			int com = 1;
			for(i = 0;i < 4;i++)
			{
				for(j = 0;j < 4;j++)
					if (arr[i][j] == '.')
					{
						com = 0;
						break;
					}
				if (com == 0)
					break;
			}
			if (com)
				printf("Case #%d: Draw\n", icase);
			else
				printf("Case #%d: Game has not completed\n", icase);
		}
		getchar();
	}
	return 0;
}
