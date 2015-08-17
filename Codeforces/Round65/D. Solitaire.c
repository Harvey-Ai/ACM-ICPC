#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;


string rank[15] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
string suit[5] = {"C", "D", "H", "S"};

int ans1i, ans1j, ans2i, ans2j;

int check(string str[100][100], int m, int n)
{
	int ret[100][100];
	int used[500];
	char st;
	int flag = 0;
	int i, j, k, l;
	int ok = 0;

	memset(ret, 0, sizeof(ret));
	for(i = 2;i < m;i++)
		for(j = 2;j < n;j++)
		{
			flag = 1;
			st = str[i - 2][j - 2][1];
			memset(used, 0, sizeof(used));
			for(k = i - 2;k <= i;k++)
			{
				for(l = j - 2;l <= j;l++)
					if (used[str[k][l][0]] > 0)
					{
						flag = 0;
						break;
					}
					else
						used[str[k][l][0]]++;
				if (flag == 0)
					break;
			}
			if (flag == 1)
			{
				ret[i][j] = 1;
				continue;
			}
			flag = 1;
			for(k = i - 2;k <= i;k++)
			{
				for(l = j - 2;l <= j;l++)
					if (str[k][l][1] > st)
					{
						flag = 0;
						break;
					}
				if (flag == 0)
					break;
			}
		}

//	if (str[4][2] == "JD" && str[2][7] == "7H")
//		printf("%d %d\n", ret[4][2], ret[4][7]);
	for(i = 2;i < m;i++)
	{
		for(j = 2;j < n;j++)
		{
			if (ret[i][j])
			{
				for(k = i + 3;k < m;k++)
				{
					for(l = 2;l < n;l++)
						if (ret[k][l])
						{
							ok = 1;
							ans1i = i - 1;
							ans1j = j - 1;
							ans2i = k - 1;
							ans2j = l - 1;
							break;
						}
					if (ok)
						break;
				}
				if (ok)
					break;
			//	if (str[4][2] == "JD" && str[2][7] == "7H" && i == 4 && j == 2)
			//		printf("ok %d %d %d\n", 2, j + 3, ret[4][7]);
				for(l = j + 3;l < n;l++)
				{
					for(k = 2;k < m;k++)
						if (ret[k][l])
						{
							ok = 1;
							ans1i = i - 1;
							ans1j = j - 1;
							ans2i = k - 1;
							ans2j = l - 1;
							break;
						}
					if (ok)
						break;
				}
				if (ok)
					break;
			}
			if (ok)
				break;
		}
		if (ok)
			break;
	}

	return ok;
}

int main()
{
	int m, n;
	int rk, st, rk2, st2;
	int pi1, pj1, pi2, pj2;
	int i, j;
	int flag;
	string arr[100][100];
	set <string> used;
	cin>>m>>n;
	

	pi1 = pj1 = pi2 = pj2 = -1;
	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
		{
			cin>>arr[i][j];
			if (arr[i][j] != "J1" && arr[i][j] != "J2")
				used.insert(arr[i][j]);
			if (arr[i][j] == "J1")
			{
				pi1 = i;
				pj1 = j;
			}
			if (arr[i][j] == "J2")
			{
				pi2 = i;
				pj2 = j;
			}
		}

	flag = 0;
	for(rk = 0;rk < 13;rk++)
	{
		for(st = 0;st < 4;st++)
		{
			if (pi1 != -1)
			{
				arr[pi1][pj1] = rank[rk] + suit[st];
				if (used.find(arr[pi1][pj1]) != used.end())
					continue;
			}
			
			for(rk2 = 0;rk2 < 13;rk2++)
			{
				for(st2 = 0;st2 < 4;st2++)
				{
					if (pi1 != -1 && rk == rk2 && st == st2)
						continue;
					if (pi2 != -1)
					{
						arr[pi2][pj2] = rank[rk2] + suit[st2];
						if (used.find(arr[pi2][pj2]) != used.end())
							continue;
					}

			//		if (arr[pi1][pj1] == "JD" && arr[pi2][pj2] == "7H")
			//			printf("%d\n", check(arr, m, n));
					if (check(arr, m, n))
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				break;
		}
		if (flag)
			break;
	}

	if (flag)
	{
		printf("Solution exists.\n");
		if (pi1 == -1 && pi2 == -1)
			printf("There are no jokers.\n");
		else if (pi1 != -1 && pi2 != -1)
			printf("Replace J1 with %s and J2 with %s.\n", arr[pi1][pj1].c_str(), arr[pi2][pj2].c_str());
		else if (pi2 != -1)
			printf("Replace J2 with %s.\n", arr[pi2][pj2].c_str());
		else if (pi1 != -1)
			printf("Replace J1 with %s.\n", arr[pi1][pj1].c_str());

		printf("Put the first square to (%d, %d).\n", ans1i, ans1j);
		printf("Put the second square to (%d, %d).\n", ans2i, ans2j);
	}
	else
		printf("No solution.\n");

	return 0;
}
