#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct suffixType
{
	int index;
	string str;
};

bool cmp(const suffixType &a, const suffixType &b)
{
	if (a.str < b.str)
		return 1;
	else
		return 0;
}

class SuffixArrayDiv2 {
	public:
	string smallerOne(string s) {
		suffixType suffArr[55];
		for(int i = 0;i < s.size();i++)
		{
			suffArr[i].str = s.substr(i);
			suffArr[i].index = i;
		}

		int rawSort[55];
		sort(suffArr, suffArr + s.size(), cmp);
		for(int i = 0;i < s.size();i++)
			rawSort[i] = suffArr[i].index;

		for(int i = 0;i < s.size();i++)
		{
			char c = s[i];
			for(int j = c - 1;j >= 'a';j--)
			{
				s[i] = j;

				for(int k = 0;k < s.size();k++)
				{
					suffArr[k].str = s.substr(k);
					suffArr[k].index = k;
				}

				sort(suffArr, suffArr + s.size(), cmp);
				int flag = 1;
				for(int k = 0;k < s.size();k++)
					if (rawSort[k] != suffArr[k].index)
					{
						flag = 0;
						break;
					}

				if (flag)
					return "Exists";
			}
			s[i] = c;
		}
		return "Does not exist";
	}
};
