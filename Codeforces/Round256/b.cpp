#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int checkSub(string a, string b)
{
	if (b.size() > a.size())
		return 0;

	int posA = 0, posB = 0;
	for(;posA < a.size();posA++)
	{
		if (b[posB] == a[posA])
			posB++;
		if (posB == b.size())
			return 1;
	}
	return 0;
}

int main()
{
	string s, t;
	cin >> s >> t;

	int isSubStr;
	isSubStr = checkSub(s, t);
	if (isSubStr)
	{
		cout << "automaton" << endl;
		return 0;
	}

	int sct[256], tct[256];
	memset(sct, 0, sizeof(sct));
	memset(tct, 0, sizeof(tct));
	for(int i = 0;i < s.size();i++)
		sct[s[i]]++;
	for(int i = 0;i < t.size();i++)
		tct[t[i]]++;

	for(int i = 0;i < 256;i++)
		if (sct[i] < tct[i])
		{
			cout << "need tree" << endl;
			return 0;
		}
	
	if (s.size() > t.size())
	{
		cout << "both" << endl;
		return 0;
	}
	else
		cout << "array" << endl;
	return 0;
}
