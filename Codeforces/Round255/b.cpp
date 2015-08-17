#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;

	int wV[26];
	int maxWV = -1;
	for(int i = 0;i < 26;i++)
	{
		cin >> wV[i];
		if (maxWV < wV[i])
			maxWV = wV[i];
	}

	int res = 0;
	for(int i = 0;i < str.size();i++)
		res += wV[str[i] - 'a'] * (i + 1);

	for(int i = 0;i < k;i++)
		res += maxWV * (str.size() + 1 + i);
	cout << res << endl;

	return 0;
}
