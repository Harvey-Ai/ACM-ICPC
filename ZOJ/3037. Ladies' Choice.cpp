/*
Teenagers from the local high school have asked you to help them with the organization of next year's Prom. The idea is to find a suitable date for everyone in the class in a fair and civilized way. So, they have organized a web site where all students, boys and girls, state their preferences among the class members, by ordering all the possible candidates. Your mission is to keep everyone as happy as possible. Assume that there are equal numbers of boys and girls.

Given a set of preferences, set up the blind dates such that there are no other two people of opposite sex who would both rather have each other than their current partners. Since it was decided that the Prom was Ladies' Choice, we want to produce the best possible choice for the girls.

Input

A positive integer P in a single line followed by a sequence of P test cases. Each test case consists of a positive integer N, not greater than 1,000, indicating the number of couples in the class. Next, there are N lines, each one containing the all the integers from 1 to N, ordered according to the girl's preferences. Next, there are N lines, each one containing all the integers from 1 to N, ordered according to the boy's preferences.

Output

The output consists of a sequence of N lines, where the i-th line contains the number of the boy assigned to the i-th girl (from 1 to N).

Sample Input

1
5
1 2 3 5 4
5 2 4 3 1
3 5 1 2 4
3 4 2 1 5
4 5 1 2 3
2 5 4 1 3
3 2 4 1 5
1 2 4 3 5
4 1 2 5 3
5 3 2 4 1
Sample Output

1
2
5
3
4
*/

#include <stdio.h>
int arr2[1005],match1[1005],match2[1005],prio1[1005][1005],p1[1005][1005],p2[1005][1005];
int main()
{
	int i,j,n,Case,flag;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&p2[i][j]);
				p2[i][j]--;
			}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&p1[i][j]);
				p1[i][j]--;
				prio1[i][p1[i][j]]=j;
			}
		for(i=0;i<n;i++)
		{
			match1[i]=match2[i]=-1;
			arr2[i]=0;
		}
		flag=1;
		while(flag)
		{
			flag=0;
			for(i=0;i<n;i++)
			{
				if(match2[i]==-1)
				{
					flag=1;
					for(j=arr2[i];j<n;j++)
					{
						if(match1[p2[i][j]]==-1)
						{
							match2[i]=p2[i][j];
							match1[p2[i][j]]=i;
							break;
						}
						else
						{
							if(prio1[p2[i][j]][i]<prio1[p2[i][j]][match1[p2[i][j]]])
							{
								match2[match1[p2[i][j]]]=-1;
								match1[p2[i][j]]=i;
								match2[i]=p2[i][j];
								break;
							}
						}
					}
					arr2[i]=j;
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%d\n",match2[i]+1);
	}
	return 0;
}
