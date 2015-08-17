#include <iostream>
#include <string>
using namespace std;

string mStr[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;

//	cout << mStr[1].size() << endl;
	for(int i = 0;i < 8;i++)
	{
	//	cout << i << "fdafd " << mStr[i].size() << " " << n << endl;
		if (mStr[i].size() != n)
			continue;

		int ok = 1;
		for(int j = 0;j < n;j++)
			if (str[j] != mStr[i][j] && str[j] != '.')
			{
	//			cout << i <<  " ccc" << str[j] << " " << mStr[i][j] << endl;
				ok = 0;
				break;
			}
	//	cout << i << " " << ok << endl;
		if (ok)
		{
			cout << mStr[i] << endl;
			break;
		}
	}
	return 0;
}

