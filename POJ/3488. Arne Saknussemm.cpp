/*
Description

Following the account of Jules Verne, a scrambled message written by the middle age alchemist Arne Saknussemm, and deciphered by professor Lidenbrock, started the incredible travel to the center of the Earth. The scrambling procedure used by Arne is alike the procedure given below.

1. Take a non empty message M that contains letters from the English alphabet, digits, commas, dots, quotes (i.e. '), spaces and line breaks, and whose last character is different than space. For example, consider the following message whose translation reads "In Sneffels's crater descend brave traveler, and touch the center of the Earth".

In Sneffels craterem descende audas
viator, et terrestre centrum attinges.
2. Choose an integral number 0<K≤length(M) and add trailing spaces to M such that the length of the resulting message, say M', is the least multiple of K. For K=19 and the message above, where length(M)=74 (including the 8 spaces and the line break that M contains), two trailing spaces are added yielding the message M' with length(M')=76.
3. Replace all the spaces from M' by the character _ (underscore) ; replace all the line breaks from M' by \ (backslash), and then reverse the message. In our case:

__.segnitta_murtnec_ertserret_te_,rotaiv\sadua_ednecsed_meretarc_sleffenS_nI
4. Write the message that results from step 3 in a table with length(M')/K rows and K columns. The writing is column wise. For the given example, the message is written in a table with 76/19=4 rows and 19 columns as follows:

_	e	t	m	n	e	e	t	_	t	\	u	d	s	m	t	_	f	S
_	g	t	u	e	r	r	_	,	a	s	a	n	e	e	a	s	f	_
.	n	a	r	c	t	r	t	r	i	a	_	e	d	r	r	l	e	n
s	i	_	t	_	s	e	e	o	v	d	e	c	_	e	c	e	n	I
5. The strings of characters that correspond to the rows of the table are the fragments of the scrambled message. The 4 fragments of Arne's message given in step 1 are:

_etmneet_t\udsmt_fS
.narctrtria_edrrlen
_gtuerr_,asaneeasf_
si_t_seeovdec_ecenI
Write a program that deciphers non empty messages scrambled as described. The length of a message, before scrambling, is at most 1000 characters, including spaces and line breaks.

Input

The program input is from a text file where each data set corresponds to a scrambled message. A data set starts with an integer n, that shows the number of fragments of the scrambled message, and continues with n strings of characters that designate the fragments, in the order they appear in the table from step 4 of the scrambling procedure. Input data are separated by white-spaces and terminate with an end of file.

Output

The deciphered message must be printed on the standard output, from the beginning of a line and must be followed by an empty line as shown in the input/output sample below.

Sample Input

4  _etmneet_t\udsmt_fS
   _gtuerr_,asaneeasf_
   .narctrtria_edrrlen
   si_t_seeovdec_ecenI
11 e n r e V _ s e l u J
Sample Output

In Sneffels craterem descende audas
viator, et terrestre centrum attinges.

Jules Verne
*/



#include <stdio.h>
#include <string.h>
char rel[1005],str[1005][1005];
int main()
{
	int i,j,k,n,len;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		len=strlen(str[0]);
		for(i=len-1,k=0;i>=0;i--)
		{
			for(j=n-1;j>=0;j--,k++)
			{
				if(str[j][i]=='_')
					rel[k]=' ';
				else
				{
					if(str[j][i]=='\\')
						rel[k]='\n';
					else
						rel[k]=str[j][i];
				}
			}
		}
		k--;
		while(rel[k]==' ')
			k--;
		rel[++k]='\0';
		printf("%s\n\n",rel);
	}
	return 0;
}
