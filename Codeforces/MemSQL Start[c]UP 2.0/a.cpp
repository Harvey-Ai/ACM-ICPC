#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

	a = "00000" + a;
	b = "00000" + b;
	
	for(int i = 2;i < a.size();i++)
		if (a[i] == '1' && a[i - 1] == '1')
		{
			a[i - 2] = '1';
			a[i] = '0';
			a[i - 1] = '0';
		}
	for(int i = 2;i < b.size();i++)
		if (b[i] == '1' && b[i - 1] == '1')
		{
			b[i - 2] = '1';
			b[i] = '0';
			b[i - 1] = '0';
		}

	for(int i = a.size() - 1;i > 0;i--)
		if (a[i] > '0' && a[i - 1] > '0')
		{
			a[i] -= 1;
			a[i - 1] -= 1;
			a[i - 2] += 1;
		}

	for(int i = b.size() - 1;i > 0;i--)
		if (b[i] > '0' && b[i - 1] > '0')
		{
			b[i] -= 1;
			b[i - 1] -= 1;
			b[i - 2] += 1;
		}

	int h1 = -1, h2 = -1;
	int pos1 = 0, pos2 = 0;
	while(h1 == h2)
	{
		h1 = -1, h2 = -1;
		while(pos1 < a.size() && a[pos1] == '0')
			pos1++;
		while(pos2 < b.size() && b[pos2] == '0')
			pos2++;

		if (pos1 < a.size())
			h1 = a.size() - 1 - pos1;
		if (pos2 < b.size())
			h2 = b.size() - 1 - pos2;

		pos1++, pos2++;
		if (h1 != h2 || (h1 == h2 && h1 == -1))
			break;
	}

	if (h1 > h2)
		cout << ">" << endl;
	else if (h1 == h2)
		cout << "=" << endl;
	else
		cout << "<" << endl;

    return 0;
}
