#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ConvertibleStrings {
	public:
		int graph[26][26];
		int used[26];
		string s1, s2;
		int res;
	void check()
	{
		int temp = 0;
		for(int i = 0;i < s1.size();i++)
			if (graph[s1[i] - 'A'][s2[i] - 'A'] == 0)
				temp++;
	//	int id1 = -1, id2 = -1;
		
		/*
		for(int i = 0;i < 26;i++)
			if (graph[0][i])
			{
				id1 = i;
				break;
			}
		for(int i = 0;i < 26;i++)
			if (graph['I' - 'A'][i])
			{
				id2 = i;
				break;
			}
		if (id1 == -1 || id2 == -1)
		{
			for(int i = 0;i < 26;i++)
				printf ("%d ", used[i]);
			putchar('\n');
		}
		//printf("A->%c I->%c %d\n", id1 + 'A', id2 + 'A', temp);
		*/
		if (temp < res)
			res = temp;
	}

	void dfs(int k)
	{
		if (k == 'I' - 'A' + 1)
		{
			check();
			return;
		}

		for(int i = 0;i <= 'I' - 'A';i++)
		{
			if (!used[i])
			{
				used[i] = 1;
				graph[k][i] = 1;
				dfs(k + 1);
				used[i] = 0;
				graph[k][i] = 0;
			}
		}
	}
	int leastRemovals(string A, string B) {
		s1 = A;
		s2 = B;
		for(int i = 0;i < 26;i++)
			for(int j = 0;j < 26;j++)
				graph[i][j] = 0;
		for(int i = 0;i < 26;i++)
			used[i] = 0;
		res = A.size();
		dfs(0);
		return res;

	}
};
