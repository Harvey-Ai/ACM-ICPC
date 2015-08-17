#include <string>
#include <vector>
#include <iostream>
using namespace std;

class FoxAndGomoku {
	public:
	string win(vector <string> board) {
	
		int m = board.size();
		int n = board[0].size();	
		for(int i = 0;i < m;i++)
		{
			int ac = 0;
			for(int j = 0;j < n;j++)
			{
				if (board[i][j] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}

		for(int i = 0;i < n;i++)
		{
			int ac = 0;
			for(int j = 0;j < m;j++)
			{
				if (board[j][i] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}

		for(int j = 0;j < n;j++)
		{
			int ac = 0;
			for(int k = 0;j + k < n && k < m;k++)
			{
				if (board[k][j + k] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}

		for(int i = 0;i < m;i++)
		{
			int ac = 0;
			for(int k = 0;i + k < m && k < n;k++)
			{
				if (board[i + k][k] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}

		for(int j = 0;j < n;j++)
		{
			int ac = 0;
			for(int k = 0;k < m && j - k >= 0;k++)
			{
				if (board[k][j - k] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}

		for(int i = 0;i < m;i++)
		{
			int ac = 0;
			for(int k = 0;(i + k) < m && (n - 1 - k) >= 0;k++)
			{
				if (board[i + k][n - 1 - k] == 'o')
					ac++;
				else
					ac = 0;
				if (ac >= 5)
					return "found";
			}
		}
		return "not found";
	}
};
