#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	char str[105];
	int len;
	int i, j;
	string s;
	int max;
	map <string, int> strNum;
	map<string, int>::iterator it;
	
	strNum.clear();
	scanf("%s", str);
	len = strlen(str);

	for(i = 0;i < len;i++)
	{
		s = "";
		for(j = i;j < len;j++)
		{
			s += str[j];
			strNum[s]++;
		}
	}

	max = 0;
	for(it = strNum.begin(); it != strNum.end();it++)
		if ((it->first).length() > max && it->second > 1)
			max = (it->first).length();

	printf("%d\n", max);
	return 0;
}

