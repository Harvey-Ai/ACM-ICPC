#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int ncase;
	cin >> ncase;

	for(int icase = 1;icase <= ncase;icase++)
	{
		char board[5][5];
		for(int i = 0;i < 4;i++)
			scanf("%s", board[i]);
		int r, c;
		for(int i = 0;i < 4;i++)
			for(int j = 0;j < 4;j++)
				if (board[i][j] == 'T')
				{
					r = i;
					c = j;
				}
		int win = 0;
		board[r][c] = 'X';
		for(int i = 0;i < 4;i++)
		{
			int ok = 1;
			for(int j = 1;j < 4;j++)
				if (board[i][j] != board[i][j - 1])
				{
					ok = 0;
					break;
				}
			if (ok && board[i][0] != '.') win = board[i][0];
		}
		for(int i = 0;i < 4;i++)
		{
			int ok = 1;
			for(int j = 1;j < 4;j++)
				if (board[j][i] != board[j - 1][i])
				{
					ok = 0;
					break;
				}
			if (ok && board[0][i] != '.') win = board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != '.')
			win = board[0][0];
		if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != '.')
			win = board[0][3];

		board[r][c] = 'O';
		for(int i = 0;i < 4;i++)
		{
			int ok = 1;
			for(int j = 1;j < 4;j++)
				if (board[i][j] != board[i][j - 1])
				{
					ok = 0;
					break;
				}
			if (ok && board[i][0] != '.') win = board[i][0];
		}
		for(int i = 0;i < 4;i++)
		{
			int ok = 1;
			for(int j = 1;j < 4;j++)
				if (board[j][i] != board[j - 1][i])
				{
					ok = 0;
					break;
				}
			if (ok && board[0][i] != '.') win = board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != '.')
			win = board[0][0];
		if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != '.')
			win = board[0][3];

		if (win == 0)
		{
			int end = 1;
			for(int i = 0;i < 4;i++)
				for(int j = 0;j < 4;j++)
				{
					if (board[i][j] == '.')
						end = 0;
				}
			if (end)
				cout << "Case #" << icase << ": Draw" << endl;
			else
				cout << "Case #" << icase << ": Game has not completed" << endl;
		}
		else
			cout << "Case #" << icase << ": " << char(win) << " won" << endl;
	}
	return 0;
}
