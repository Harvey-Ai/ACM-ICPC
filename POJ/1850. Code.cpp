/*
Description

Transmitting and memorizing information is a task that requires different coding systems for the best use of the available space. A well known system is that one where a number is associated to a character sequence. It is considered that the words are made only of small characters of the English alphabet a,b,c, ..., z (26 characters). From all these words we consider only those whose letters are in lexigraphical order (each character is smaller than the next character). 

The coding system works like this: 
•	The words are arranged in the increasing order of their length. 
•	The words with the same length are arranged in lexicographical order (the order from the dictionary). 
•	We codify these words by their numbering, starting with a, as follows: 
a - 1 
b - 2 
... 
z - 26 
ab - 27 
... 
az - 51 
bc - 52 
... 
vwxyz - 83681 
... 

Specify for a given word if it can be codified according to this coding system. For the affirmative case specify its code. 
Input

The only line contains a word. There are some constraints: 
•	The word is maximum 10 letters length 
•	The English alphabet has 26 characters. 
Output

The output will contain the code of the given word, or 0 if the word can not be codified.
Sample Input

bf
Sample Output

55
*/


#include <stdio.h>
int dp[26][10];
char str[11];
int main()
{
	int i,j,c,len,ind;
	for(i=0;i<26;i++)
		dp[i][9]=i+1;
	for(j=8;j>=0;j--)
	{
		dp[0][j]=dp[17+j][j+1]+1;
		for(i=1;i<26;i++)
			dp[i][j]=dp[i-1][j]+dp[17+j][j+1]-dp[i][j+1]+1;
	}
	while(scanf("%s",str)!=EOF)
	{
		len=0;
		while(str[len]!='\0')
			len++;
		ind=dp[str[0]-'a'][10-len];
		c=str[0]+1;
		for(i=11-len,j=1;j<len;i++,j++)
		{
			if(str[j-1]>=str[j])
				break;
			else
				ind+=dp[str[j]-'a'][i]-dp[c-'a'][i];
			c=str[j]+1;
		}
		if(j<len)
			printf("0\n");
		else
			printf("%d\n",ind);
	}
	return 0;
}
