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
int blen, elen;
int strSize;
int wPos;
string res, ans;
string pStr;
int getA;

void dfs(int pos, char last, int lastLen)
{
	int i;
	int temp;
	int flag;
	if (lastLen == elen)
	{
		if (wPos != strSize - 1)
		{
			if (last != pStr[wPos + 1])
			{
				if (wPos >= 1 && res[0] != pStr[wPos - 1] && (pStr[wPos - 1] != 'B' || blen > 1))
					res.insert(0, "B");
				else
				{
					temp = blen - 1;
					flag = 0;
					for(i = 1;i < res.size();i++)
						if (res[i] != res[i - 1] && temp + (res[i - 1] == 'B' ? -1 : 1) > 0)
						{
							res.insert(i, "B");
							flag = 1;
							break;
						}
						else
							temp = temp + (res[i] == res[i - 1] ? -1 : 1);
					if (!flag)
					{
						if (lastLen == 1 && last == 'B')
							res.insert(res.size(), "W");
						else
							res.insert(res.size(), "B");
					}
				}
			}
			else
				res.erase(res.end() - 1);
		}
		if (getA == -1 || ans.length() > res.length())
		{
			getA = 1;
			printf("ans %d res %d\n", ans.length(), res.length());
			cout<<"res=="<<res<<endl;
			ans = res;
		}
		else if (ans > res && ans.length() == res.length())
		{
			getA = 1;
			ans = res;
		}
	}
	else if (lastLen < elen)
	{
		if (last == 'B')
		{
			res += "W";
			dfs(pos + 1, 'W', lastLen + 1);
		}
		else
		{
			res += "B";
			dfs(pos + 1, 'B', lastLen + 1);
		}
	}
	else if (lastLen > elen)
	{
		if (lastLen <= 1)
			return;
		if (last == 'B')
		{
			res += "B";
			dfs(pos + 1, 'B', lastLen - 1);
		}
		else
		{
			res += "W";
			dfs(pos + 1, 'W', lastLen - 1);
		}
	}

}


class SquareSeries
{
public:
string completeIt(string pattern, int lastLength)
{
	int i;
	int len;
	string a, b;
	strSize = pattern.size();
	pStr = pattern;

	for(i = 0;i < pattern.size();i++)
		if (pattern[i] == '?')
		{
			wPos = i;
			break;
		}

	a = pattern.substr(0, wPos);
	b = pattern.substr(wPos + 1, pattern.size() - wPos - 1);

	len = 1;
	for(i = 1;i < wPos;i++)
	{
		if (pattern[i] != pattern[i - 1])
			len++;
		else
			len--;
		if (len <= 0)
			return "...";
	}
	blen = len;

	len = lastLength;
	for(i = pattern.size() - 2;i > wPos;i--)
	{
		if (pattern[i + 1] != pattern[i])
			len--;
		else
			len++;
		if (len <= 0)
			return "...";
	}
	elen = len;

	if (wPos == pattern.size() - 1 && blen == lastLength && pattern.size() > 1)
	{
		ans = pattern.substr(0, pattern.size() - 1);
		return ans;
	}

	printf("blen %d elen%d\n", blen, elen);
	ans = "";
	res = "";

	getA = -1;
	printf("%d %d\n", blen, elen);
	res += "W";
	if (wPos == 0)
		dfs(wPos + 1, 'W', 1);
	else if ('W' != pattern[wPos - 1])
		dfs(wPos + 1, 'W', blen + 1);
	else if (blen - 1 > 0)
		dfs(wPos + 1, 'W', blen - 1);

	cout<<"if ans="<<(ans == "")<<endl;
	cout<<"ffff"<<ans<<endl;
	res = "";
	res += "B";
	if (wPos == 0)
		dfs(wPos + 1, 'B', 1);
	else if ('B' != pattern[wPos - 1])
		dfs(wPos + 1, 'B', blen + 1);
	else if (blen - 1 > 0)
		dfs(wPos + 1, 'B', blen - 1);

	return a + ans + b;
}
}; 
