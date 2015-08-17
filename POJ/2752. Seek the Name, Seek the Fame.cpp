/*
Description

The little cat is so famous, that many couples tramp over hill and dale to Byteland, and asked the little cat to give names to their newly-born babies. They seek the name, and at the same time seek the fame. In order to escape from such boring job, the innovative little cat works out an easy but fantastic algorithm: 

Step1. Connect the father's name and the mother's name, to a new string S. 
Step2. Find a proper prefix-suffix string of S (which is not only the prefix, but also the suffix of S). 

Example: Father='ala', Mother='la', we have S = 'ala'+'la' = 'alala'. Potential prefix-suffix strings of S are {'a', 'ala', 'alala'}. Given the string S, could you help the little cat to write a program to calculate the length of possible prefix-suffix strings of S? (He might thank you by giving your baby a name:) 
Input

The input contains a number of test cases. Each test case occupies a single line that contains the string S described above. 

Restrictions: Only lowercase letters may appear in the input. 1 <= Length of S <= 400000. 
Output

For each test case, output a single line with integer numbers in increasing order, denoting the possible length of the new baby's name.
Sample Input

ababcababababcabab
aaaaa
Sample Output

2 4 9 18
1 2 3 4 5
*/


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

char str[400005];
int strLen;
int next[400005];

void getNext()
{
	int k = -1;
	next[0] = -1;

	for(int i = 1;i < strLen;i++)
	{
		while(k >= 0 && str[i] != str[k + 1])
			k = next[k];

		if (str[i] == str[k + 1])
			k++;
		next[i] = k;
	}
}

int main()
{
	while(scanf("%s", str) != EOF)
	{
		strLen = strlen(str);
		getNext();

		vector<int> ans;
		int k = next[strLen - 1];
		
		while(k != -1)
		{
			ans.push_back(k + 1);
			k = next[k];
		}

		for(int i = ans.size() - 1;i >= 0;i--)
			cout << ans[i] << " ";
		cout << strLen << endl;
	}
	return 0;
}
