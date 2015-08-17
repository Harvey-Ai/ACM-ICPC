/*
Description

Mrs. Deli is running the delicatessen store "Deli Deli". Last year Mrs. Deli has decided to expand her business and build up an online store. She has hired a programmer who has implemented the online store.

Recently some of her new online customers complained about the electronic bills. The programmer had forgotten to use the plural form in case that an item is purchased multiple times. Unfortunaly the programmer of Mrs. Deli is on holiday and now it is your task to implement this feature for Mrs. Deli. Here is a description how to make the plural form:

If the word is in the list of irregular words replace it with the given plural.
Else if the word ends in a consonant followed by "y", replace "y" with "ies".
Else if the word ends in "o", "s", "ch", "sh" or "x", append "es" to the word.
Else append "s" to the word.
Input

The first line of the input file consists of two integers L and N (0 ≤ L ≤ 20, 1 ≤ N ≤ 100). The following L lines contain the description of the irregular words and their plural form. Each line consists of two words separated by a space character, where the first word is the singular, the second word the plural form of some irregular word. After the list of irregular words, the following N lines contain one word each, which you have to make plural. You may assume that each word consists of at most 20 lowercase letters from the English alphabet ('a' to 'z').

Output

Print N lines of output, where the ith line is the plural form of the ith input word.

Sample Input

3 7
rice rice
spaghetti spaghetti
octopus octopi
rice
lobster
spaghetti
strawberry
octopus
peach
turkey
Sample Output

rice
lobsters
spaghetti
strawberries
octopi
peaches
turkeys

*/

#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int main()
{
	int i,l,len,n;
	char str1[1000],str2[1000];
	map<string,string> list;
	scanf("%d%d",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%s%s",str1,str2);
		list[str1]=str2;
	}
	while(l--)
	{
		scanf("%s",str1);
		len=strlen(str1);
		if(list[str1]=="\0")
		{
			if(str1[len-1]=='y'&&str1[len-2]!='a'&&str1[len-2]!='e'&&str1[len-2]!='i'&&str1[len-2]!='o'&&str1[len-2]!='u')
			{
				str1[len-1]='i';
				str1[len]='e';
				str1[len+1]='s';
				str1[len+2]='\0';
			}
			else
			{
				if(str1[len-1]=='o'||str1[len-1]=='s'||str1[len-1]=='x'||str1[len-2]=='s'&&str1[len-1]=='h'||str1[len-2]=='c'&&str1[len-1]=='h')
				{
					str1[len]='e';
					str1[len+1]='s';
					str1[len+2]='\0';
				}
				else
				{
					str1[len]='s';
					str1[len+1]='\0';
				}
			}
			printf("%s\n",str1);
		}
		else
			printf("%s\n",list[str1].c_str());
	}
	return 0;
}
