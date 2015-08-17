#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
class LittleElephantAndIntervalsDiv2 {
	struct segment
	{
		int start, end;
	};
	public:
	int getNumber(int M, vector <int> L, vector <int> R) {
		segment segments[20];
		for(int i = 0;i < L.size();i++)
			if (L[i] < R[i])
			{
				segments[i].start = L[i];
				segments[i].end = R[i];
			}
			else
			{
				segments[i].start = R[i];
				segments[i].end = L[i];
			}
		int flag[101];
		for(int i = 0;i < 101;i++)
			flag[i] = 0;
		int cIndex = 1;

		for(int i = 0;i < L.size();i++)
		{
			for(int j = segments[i].start;j <= segments[i].end;j++)
				flag[j] = cIndex;
			cIndex++;
		}

		set<int> colors;
		for(int i = 1;i <= M;i++)
			if (flag[i] != 0)
				colors.insert(flag[i]);

		int res = 1;
		for(int i = 0;i < colors.size();i++)
			res *= 2;
		return res;
				
	}
};
