#include <iostream>
using namespace std;

char str[1000];
int dfs(int pos, int &next)
{
	int value;
	int nextPos;
	int flag = 0;
	int nav = 0;
	if (str[pos] == '!')
	{
		nav = 1;
		pos++;
	}
	if (str[pos] == '(')
	{
		flag = 1;
		value = dfs(pos + 1, nextPos);
	}
	else if (str[pos] == 'V')
	{
		nextPos = pos + 1;
		value = 1;
	}
	else if (str[pos] == 'F')
	{
		nextPos = pos + 1;
		value = 0;
	}
	if (str[nextPos] == ')' && flag)
		nextPos++;
	next = nextPos;
	if (nav)
		value = 1 - value;

	if (str[nextPos] == '&')
	{
	//	if (pos == 3)
	//		cout << "fd11sa " <<endl;
		value &= dfs(nextPos + 1, nextPos);
		next = nextPos;
	}
	else if (str[nextPos] == '|')
	{
		
	//	if (pos == 3)
	//		cout << "fdsa " <<endl;
		value |= dfs(nextPos + 1, nextPos);
		next = nextPos;
	}
	cout << pos << " " << value << endl;
	return value;
}

int main()
{
	int ncase = 1;
	char ss[10000];
	while(cin.getline(str, 1000, '\n'))
	{
		int i, j;
		for(i = 0, j = 0;str[i] != '\0';i++)
			if (str[i] != ' ')
				ss[j++] = str[i];
		ss[j] = '\0';
		strcpy(str, ss);
		str[j] = '\0';
	//	cout << str << endl;
		int temp;
		if (dfs(0, temp))
			cout << "Expression " << ncase++ << ": V" << endl;
		else
			cout << "Expression " << ncase++ << ": F" << endl;
	}
	return 0;
}
