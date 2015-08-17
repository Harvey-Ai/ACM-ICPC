/*
Description

You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language. Fortunately, you have a dictionary to help you understand them.
Input

Input consists of up to 100,000 dictionary entries, followed by a blank line, followed by a message of up to 100,000 words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line. Each word in the input is a sequence of at most 10 lowercase letters.
Output

Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as "eh".
Sample Input

dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
Sample Output

cat
eh
loops
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map<string, string> strMap;
int main()
{
	char str1[15], str2[15], str[15];
	char c;
	while(c = getchar(), c != '\n')
	{
		scanf("%s %s", str1, str2);
        str1[strlen(str1) + 1] = '\0';
		for(int i = strlen(str1);i > 0;i--)
			str1[i] = str1[i - 1];
		str1[0] = c;
		strMap[string(str2)] = string(str1);
        getchar();
	}

	while(scanf("%s", str) != EOF)
		if (strMap.find(string(str)) != strMap.end())
            printf("%s\n", strMap[string(str)].c_str());
		else
            printf("eh\n");

	return 0;
}
