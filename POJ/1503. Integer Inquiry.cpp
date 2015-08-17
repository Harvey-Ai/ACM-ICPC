/*
Description

One of the first users of BIT's new supercomputer was Chip Diller. He extended his exploration of powers of 3 to go from 0 to 333 and he explored taking various sums of those numbers. 
``This supercomputer is great,'' remarked Chip. ``I only wish Timothy were here to see these results.'' (Chip moved to a new apartment, once one became available on the third floor of the Lemon Sky apartments on Third Street.) 
Input

The input will consist of at most 100 lines of text, each of which contains a single VeryLongInteger. Each VeryLongInteger will be 100 or fewer characters in length, and will only contain digits (no VeryLongInteger will be negative). 

The final input line will contain a single zero on a line by itself. 
Output

Your program should output the sum of the VeryLongIntegers given in the input.
Sample Input

123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0
Sample Output

370370367037037036703703703670
*/


#include <stdio.h>
int main()
{
	char rel[300],num[300];
	char c;
	int i,j,temp,sum,carry;
	rel[0]='0';rel[1]='\0';
	while(c=getchar())
	{
		if(c=='0')
		{
			c=getchar();
			if(c=='\n')
				break;
		}
		while(c=='0')
			c=getchar();
		num[0]=c;i=1;
		while(c=getchar(),c!='\n')
				num[i++]=c;
		num[i]='\0';
		for(j=0;j<i/2;j++)
		{
			temp=num[j];
			num[j]=num[i-j-1];
			num[i-j-1]=temp;
		}
		carry=0;
		for(i=0;num[i]!='\0'&&rel[i]!='\0';i++)
		{
			sum=num[i]+rel[i]-'0'-'0'+carry;
			rel[i]=sum%10+'0';
			carry=sum/10;
		}
		if(num[i]!='\0')
		{
			while(num[i]!='\0')
			{
				sum=num[i]-'0'+carry;
				rel[i]=sum%10+'0';
				carry=sum/10;
				i++;
			}
		}
		else
		{
			while(rel[i]!='\0')
			{
				sum=rel[i]-'0'+carry;
				rel[i]=sum%10+'0';
				carry=sum/10;
				i++;
			}
		}
		if(carry)
		{
			rel[i]=carry+'0';
			i++;
			rel[i]='\0';
		}
		else
			rel[i]='\0';
	}
	for(i=0;rel[i]!='\0';i++);
	while(i--)
		printf("%c",rel[i]);
	return 0;
}
