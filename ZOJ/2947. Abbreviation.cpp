/*
When a Little White meets another Little White:

Little White A: (Surprised) !
Little White B: ?
Little White A: You Little White know "SHDC"? So unbelievable!
Little White B: You are little white! Little white is you! What is "SHDC" you are talking about?
Little White A: Wait... I mean "Super Hard-disc Drive Cooler".
Little White B: I mean "Spade Heart Diamond Club"... Duck talks with chicken -_-//
Little White A: Duck... chicken... faint!
------quote from qmd of Spade6 in CC98 forum.

Sometimes, we write the abbreviation of a name. For example IBM is the abbreviation for International Business Machines. A name usually consists of one or more words. A word begins with a capital letter ('A' - 'Z') and followed by zero or more lower-case letters ('a' - 'z'). The abbreviation for a name is the word that consists of all the first letters of the words.

Now, you are given two names and asked to decide whether their abbreviations are the same.

Input

Standard input will contain multiple test cases. The first line of the input is a single integer T which is the number of test cases. And it will be followed by T consecutive test cases.

There are four lines for each case.
The first line contains an integer N (1 <= N <= 5), indicating the number of words in the first name.
The second line shows the first name.
The third line contains an integer M (1 <= M <= 5), indicating the number of words in the second name.
The fourth line shows the second name.
Each name consists of several words separated by space. Length for every word is less than 10. The first letter for each word is always capital and the rest ones are lower-case.
Output

Results should be directed to standard output. The output of each test case should be a single line. If two names' abbreviations are the same, output "SAME", otherwise output "DIFFERENT".

Sample Input

3
4
Super Harddisc Drive Cooler
4
Spade Heart Diamond Club
3
Shen Guang Hao
3
Shuai Ge Hao
3
Cai Piao Ge
4
C P C S
Sample Output

SAME
SAME
DIFFERENT
*/

#include <stdio.h>
int main()
{
	char str1[10][12],str2[10][12];
	int i,m1,m2,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m1);
		for(i=0;i<m1;i++) scanf("%s",str1[i]);
		scanf("%d",&m2);
		for(i=0;i<m2;i++) scanf("%s",str2[i]);
		if(m1!=m2) printf("DIFFERENT\n");
		else
		{
			for(i=0;i<m1;i++)
				if(str1[i][0]!=str2[i][0])
					break;
			if(i<m1) printf("DIFFERENT\n");
			else printf("SAME\n");
		}
	}
	return 0;
}
