#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int next[50004];

void getNext()
{
	int k = -1;
	next[0] = -1;

	for(int i = 1;i < str1.size();i++)
	{
		while(k >= 0 && str1[i] != str1[k + 1])
			k = next[k];
		if (str1[i] == str1[k + 1])
			k++;

		next[i] = k;
	}
}

int main()
{
	while(cin >> str1 >> str2)
	{
		getNext();
		int k = -1;
		
		for(int i = 0;i < str2.size();i++)
		{
			while(k >= 0 && str2[i] != str1[k + 1])
				k = next[k];

			if (str2[i] == str1[k + 1])
				k++;

			if (k == str1.size())
				k = next[str1.size() - 1];
		}
		if (k == -1)
			cout << 0 << endl;
		else
			cout << str1.substr(0, k + 1) << " " << k + 1 << endl;
	}
	return 0;
}
