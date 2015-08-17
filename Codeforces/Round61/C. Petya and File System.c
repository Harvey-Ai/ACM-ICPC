#include <iostream>
using namespace std;

set <char *> fe;
map <char *, int> re;
void dfs(char *str)
{
	int i;
	for(i = 0;;*str != '\0' && *str != '\';str++)
		temp[i++] = *str;
	if (i == 0)
		return;
	temp[i] = '\0';

	if (fe.find(temp) != fe.end())
	{
		fe.insert(temp);
		re[temp] = 1;
	}
	else
		re[temp]++;
	dfs(str);
}

int main()
{
	char str[105];
	fe.clear();
	while(scanf("%s", str) != EOF)
		dfs(str);
	return 0;
}
