#include <iostream>
using namespace std;

char str1[2][100] = {"our language is impossible to understand", 
"ejp mysljylc kd kxveddknmc re jsicpdrysi"};
char str2[2][100] = {"there are twenty six factorial possibilities",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"};
char str3[2][100] = {"so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv"};

char translate[26];
void init()
{
	int i;
	for(i = 0;str1[0][i] != '\0';i++)
		if (str1[0][i] != ' ')
			translate[str1[1][i] - 'a'] = str1[0][i];
	
	for(i = 0;str2[0][i] != '\0';i++)
		if (str2[0][i] != ' ')
			translate[str2[1][i] - 'a'] = str2[0][i];

	for(i = 0;str3[0][i] != '\0';i++)
		if (str3[0][i] != ' ')
			translate[str3[1][i] - 'a'] = str3[0][i];
}

int main()
{
	char str[1000];
	int i;
	int icase, ncase, j;
	init();
	
	translate['y' - 'a'] = 'a';
	translate['e' - 'a'] = 'o';
	translate['q' - 'a'] = 'z';
	translate['z' - 'a'] = 'q';

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	getchar();
	for(icase = 1;icase <= ncase;icase++)
	{
		cin.getline(str, 1000, '\n');
		printf("Case #%d: ", icase);
		for(j = 0;str[j] != '\0';j++)
			if (str[j] == ' ')
				putchar(str[j]);
			else
				putchar(translate[str[j] - 'a']);
		putchar('\n');
	}
	return 0;
}
