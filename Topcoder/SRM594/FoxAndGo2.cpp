#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstring>
using namespace std;
class FoxAndGo2 {
	public:
		vector <string> board2;
		int visited[100][100];
		int used[100][100];
		int emptySet[100][100];
		int adjSet[100];
		int emptyUsed[100][100];
		int emptyId;

		int inBound(int r, int c)
		{
			return r >= 0 && r < board2.size() && c >= 0 && c < board2[0].size();
		}

		void killAll(int r, int c)
		{
			board2[r][c] = '.';
			if (inBound(r + 1, c) && board2[r + 1][c] == 'o')
				killAll(r + 1, c);
			if (inBound(r - 1, c) && board2[r - 1][c] == 'o')
				killAll(r - 1, c);
			if (inBound(r, c + 1) && board2[r][c + 1] == 'o')
				killAll(r, c + 1);
			if (inBound(r, c - 1) && board2[r][c - 1] == 'o')
				killAll(r, c - 1);
		}


		void dfs(int r, int c)
		{
			visited[r][c] = 1;
			if (inBound(r + 1, c) && board2[r + 1][c] == '.' && !emptyUsed[r + 1][c])
			{
				emptyUsed[r + 1][c] = 1;
				adjSet[emptySet[r + 1][c]] ++;
			}
			if (inBound(r - 1, c) && board2[r - 1][c] == '.' && !emptyUsed[r - 1][c])
			{
				emptyUsed[r - 1][c] = 1;
				adjSet[emptySet[r - 1][c]] ++;
			}
			if (inBound(r, c + 1) && board2[r][c + 1] == '.' && !emptyUsed[r][c + 1])
			{
				emptyUsed[r][c + 1] = 1;
				adjSet[emptySet[r][c + 1]] ++;
			}
			if (inBound(r, c - 1) && board2[r][c - 1] == '.' && !emptyUsed[r][c - 1])
			{
				emptyUsed[r][c - 1] = 1;
				adjSet[emptySet[r][c - 1]] ++;
			}

			if (inBound(r + 1, c) && !visited[r + 1][c] && board2[r + 1][c] == 'o')
				dfs(r + 1, c);
			if (inBound(r - 1, c) && !visited[r - 1][c] && board2[r - 1][c] == 'o')
				dfs(r - 1, c);
			if (inBound(r, c + 1) && !visited[r][c + 1] && board2[r][c + 1] == 'o')
				dfs(r, c + 1);
			if (inBound(r, c - 1) && !visited[r][c - 1] && board2[r][c - 1] == 'o')
				dfs(r, c - 1);
		}

		int dfsE(int r, int c)
		{
			int ESum = 1;
			used[r][c] = 1;
			emptySet[r][c] = emptyId;
			if (inBound(r + 1, c) && !used[r + 1][c] && board2[r + 1][c] == '.')
				ESum += dfsE(r + 1, c);
			if (inBound(r - 1, c) && !used[r - 1][c] && board2[r - 1][c] == '.')
				ESum += dfsE(r - 1, c);
			if (inBound(r, c + 1) && !used[r][c + 1] && board2[r][c + 1] == '.')
				ESum += dfsE(r, c + 1);
			if (inBound(r, c - 1) && !used[r][c - 1] && board2[r][c - 1] == '.')
				ESum += dfsE(r, c - 1);
			return ESum;
		}

		int maxKill(vector <string> board) {
			board2 = board;

			int oSum = 0;
			for(int i = 0;i < board2.size();i++)
				for(int j = 0;j < board2[i].size();j++)
					if (board2[i][j] == 'o')
						oSum++;
			int flag = 1;
			while(flag)
			{
				memset(used, 0, sizeof(used));
				memset(visited, 0, sizeof(visited));
				vector<int> emptySize;
				emptySize.clear();
				emptyId = 0;
				flag = 0;
				for(int i = 0;i < board2.size();i++)
					for(int j = 0;j < board2[i].size();j++)
						if (board2[i][j] == '.' && !used[i][j])
						{
							int ESize = dfsE(i, j);
						//	cddout << ESize << endl;
							emptySize.push_back(ESize);
							emptyId ++;
						}
				cout << "=============" << endl;
				for(int i = 0;i < board2.size();i++)
					for(int j = 0;j < board2[i].size();j++)
						if (board2[i][j] == 'o' && !visited[i][j])
						{
							memset(adjSet, 0, sizeof(adjSet));
							memset(emptyUsed, 0, sizeof(emptyUsed));
							int adjLive = 0;
							dfs(i, j);
							for(int k = 0;k < emptyId;k++)
								if (adjSet[k] == emptySize[k])
									adjLive ++;	
						
							if (adjLive < 2)
							{
								flag = 1;
								killAll(i, j);
							}
						}
			}
			int newSum = 0;
			for(int i = 0;i < board2.size();i++)
				for(int j = 0;j < board2[i].size();j++)
				if (board2[i][j] == 'o')
					newSum++;
			return oSum - newSum;
		}
};
