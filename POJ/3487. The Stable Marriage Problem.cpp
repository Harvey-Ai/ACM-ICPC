/*
Description

The stable marriage problem consists of matching members of two different sets according to the member’s preferences for the other set’s members. The input for our problem consists of:

a set M of n males;
a set F of n females;
for each male and female we have a list of all the members of the opposite gender in order of preference (from the most preferable to the least).
A marriage is a one-to-one mapping between males and females. A marriage is called stable, if there is no pair (m, f) such that f ∈ F prefers m ∈ M to her current partner and m prefers f over his current partner. The stable marriage A is called male-optimal if there is no other stable marriage B, where any male matches a female he prefers more than the one assigned in A.

Given preferable lists of males and females, you must find the male-optimal stable marriage.

Input

The first line gives you the number of tests. The first line of each test case contains integer n (0 < n < 27). Next line describes n male and n female names. Male name is a lowercase letter, female name is an upper-case letter. Then go n lines, that describe preferable lists for males. Next n lines describe preferable lists for females.

Output

For each test case find and print the pairs of the stable marriage, which is male-optimal. The pairs in each test case must be printed in lexicographical order of their male names as shown in sample output. Output an empty line between test cases.

Sample Input

2
3
a b c A B C
a:BAC
b:BAC
c:ACB
A:acb
B:bac
C:cab
3
a b c A B C
a:ABC
b:ABC
c:BCA
A:bac
B:acb
C:abc
Sample Output

a A
b B
c C

a B
b A
c C
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int arr1[30],arr2[30],match1[30],match2[30],p1[30][30],p2[30][30];
	int i,j,k,l,n,Case,flag,man,woman;
	char a,c;
	scanf("%d",&Case);
	l=0;
	while(Case--)
	{
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			c=getchar();
			arr1[i]=c-'a';
			getchar();
		}
		sort(&arr1[0],&arr1[n]);
		for(i=0;i<n;i++)
		{
			c=getchar();
			arr2[i]=c-'A';
			getchar();
		}
		sort(&arr2[0],&arr2[n]);
		for(i=0;i<n;i++)
		{
			a=getchar();
			for(j=0;j<n;j++)
				if(arr1[j]==a-'a')
					break;
			man=j;
			getchar();
			c=getchar();
			j=0;
			while(c!='\n')
			{
				for(k=0;k<n;k++)
					if(c-'A'==arr2[k])
						break;
				p1[man][j++]=k;
				c=getchar();
			}
			p1[man][j]=-1;
		}
		for(i=0;i<n;i++)
		{
			a=getchar();
			for(j=0;j<n;j++)
				if(arr2[j]==a-'A')
					break;
			woman=j;
			getchar();
			c=getchar();
			j=0;
			while(c!='\n')
			{
				for(k=0;k<n;k++)
					if(c-'a'==arr1[k])
						break;
				p2[woman][j++]=k;
				c=getchar();
			}
			p2[woman][j]=-1;
		}
		flag=1;
		for(i=0;i<n;i++)
			match1[i]=match2[i]=-1;
		while(flag)
		{
			flag=0;
			for(i=0;i<n;i++)
			{
				if(match1[i]==-1)
				{
					flag=1;
					for(j=0;p1[i][j]!=-1;j++)
					{
						if(match2[p1[i][j]]!=-1)
						{
							for(k=0;p2[p1[i][j]][k]!=-1;k++)
								if(p2[p1[i][j]][k]==i||p2[p1[i][j]][k]==match2[p1[i][j]])
									break;
							if(p2[p1[i][j]][k]==i)
							{
								match1[match2[p1[i][j]]]=-1;
								match1[i]=p1[i][j];
								match2[p1[i][j]]=i;
								break;
							}
						}
						else
						{
							match1[i]=p1[i][j];
							match2[p1[i][j]]=i;
							break;
						}
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			putchar(arr1[i]+'a');
			putchar(' ');
			putchar(arr2[match1[i]]+'A');
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
