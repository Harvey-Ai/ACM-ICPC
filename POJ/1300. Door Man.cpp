/*
Description

You are a butler in a large mansion. This mansion has so many rooms that they are merely referred to by number (room 0, 1, 2, 3, etc...). Your master is a particularly absent-minded lout and continually leaves doors open throughout a particular floor of the house. Over the years, you have mastered the art of traveling in a single path through the sloppy rooms and closing the doors behind you. Your biggest problem is determining whether it is possible to find a path through the sloppy rooms where you: 

Always shut open doors behind you immediately after passing through 
Never open a closed door 
End up in your chambers (room 0) with all doors closed 

In this problem, you are given a list of rooms and open doors between them (along with a starting room). It is not needed to determine a route, only if one is possible. 
Input

Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets. 
A single data set has 3 components: 

Start line - A single line, "START M N", where M indicates the butler's starting room, and N indicates the number of rooms in the house (1 <= N <= 20). 
Room list - A series of N lines. Each line lists, for a single room, every open door that leads to a room of higher number. For example, if room 3 had open doors to rooms 1, 5, and 7, the line for room 3 would read "5 7". The first line in the list represents room 0. The second line represents room 1, and so on until the last line, which represents room (N - 1). It is possible for lines to be empty (in particular, the last line will always be empty since it is the highest numbered room). On each line, the adjacent rooms are always listed in ascending order. It is possible for rooms to be connected by multiple doors! 
End line - A single line, "END" 

Following the final data set will be a single line, "ENDOFINPUT". 

Note that there will be no more than 100 doors in any single data set.
Output

For each data set, there will be exactly one line of output. If it is possible for the butler (by following the rules in the introduction) to walk into his chambers and close the final open door behind him, print a line "YES X", where X is the number of doors he closed. Otherwise, print "NO".
Sample Input

START 1 2
1

END
START 0 5
1 2 2 3 3 4 4




END
START 0 10
1 9
2
3
4
5
6
7
8
9

END
ENDOFINPUT
Sample Output

YES 1
NO
YES 10
*/


#include <stdio.h>
#include <string.h>
int main()
{
	int deg[22],i,a,start,sum,n;
	char str[15],c;
	bool flag;
	while(scanf("%s",str),strcmp(str,"ENDOFINPUT")!=0)
	{
		scanf("%d%d",&start,&n);
		getchar();
		for(i=0;i<n;i++) deg[i]=0;
		sum=0;
		for(i=0;i<n-1;i++) 
		{
			c=getchar();
			while(c!='\n')
			{
				a=0;
				while(c>='0'&&c<='9')
				{
					a*=10;
					a+=c-'0';
					c=getchar();
				}
				deg[i]++;
				deg[a]++;
				sum++;
				while(c==' ')	c=getchar();
			}
		}
		scanf("%s",str);
		flag=1;
		if(start==0)
		{
			for(i=0;i<n;i++)
				if(deg[i]%2==1)
				{
					flag=0;
					break;
				}
		}
		else
		{
			if(deg[start]%2&&deg[0]%2)
			{
				deg[start]=0;
				for(i=1;i<n;i++)
					if(deg[i]%2==1)
					{
						flag=0;
						break;
					}
			}
			else
				flag=0;
		}
		if(flag)
			printf("YES %d\n",sum);
		else
			printf("NO\n");
	}
	return 0;
}
