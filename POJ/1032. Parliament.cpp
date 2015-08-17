/*
Description

New convocation of The Fool Land's Parliament consists of N delegates. According to the present regulation delegates should be divided into disjoint groups of different sizes and every day each group has to send one delegate to the conciliatory committee. The composition of the conciliatory committee should be different each day. The Parliament works only while this can be accomplished. 
You are to write a program that will determine how many delegates should contain each group in order for Parliament to work as long as possible. 
Input

The input file contains a single integer N (5<=N<=1000 ).
Output

Write to the output file the sizes of groups that allow the Parliament to work for the maximal possible time. These sizes should be printed on a single line in ascending order and should be separated by spaces.
Sample Input

7
Sample Output

3 4
*/

#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,k,left;
	while(scanf("%d",&n)!=EOF)
	{
		k=sqrt(2*n+2);
		if(k*k+k>2*n+2) k--;
		left=n-(2+k)*(k-1)/2;
		if(left<k)
		{
			if(left<k-1)	
			{
				printf("2");
				for(i=3;i<=k-left;i++) printf(" %d",i);
				for(;i<=k;i++) printf(" %d",i+1);
			}
			else	
			{
				printf("3");
				for(i=3;i<=k;i++) printf(" %d",i+1);
			}
		}
		else 
		{
			printf("3");
			for(i=3;i<k;i++) printf(" %d",i+1);
			printf(" %d",k+2);
		}
		printf("\n\n");
	}
	return 0;
}
