#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class Algrid
{
public:
vector <string> makeProgram(vector <string> output)
{
	vector <string> innput;
	int i, j;
	char a1, a2;
	innput.push_back(output[0]);

	for(i = 1;i < output.size();i++)
	{
		innput.push_back("");
		innput[i].resize(output[i].size());
		innput[i][output[i].size() - 1] = output[i][output[i].size() - 1];

		for(j = output[i].size() - 1;j > 0;j--)
		{
			a2 = innput[i][j];
			a1 = output[i][j - 1];

			if (output[i - 1][j - 1] == 'W' && output[i - 1][j] == 'W')
			{
				innput[i][j] = a2;
				innput[i][j - 1] = a1;
			}
			if (output[i - 1][j - 1] == 'W' && output[i - 1][j] == 'B')
			{
				if (a1 == 'B' || a2 == 'B')
				{
					innput.clear();
					return innput;
				}
				else
					innput[i][j - 1] = innput[i][j] = '?';
			}
			if (output[i - 1][j - 1] == 'B' && output[i - 1][j] == 'W')
			{
				if (a1 == 'W' || a2 == 'W')
				{
					innput.clear();
					return innput;
				}
				else
					innput[i][j - 1] = innput[i][j] = '?';
			}
			if (output[i - 1][j - 1] == 'B' && output[i - 1][j] == 'B')
			{
				innput[i][j - 1] = a2;
				innput[i][j] = a1;
			}
		}
		replace(innput[i].begin(), innput[i].end(), '?','B');
	}
	return innput;
}
}; 

