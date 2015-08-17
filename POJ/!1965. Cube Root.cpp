/*
Description

Your task is to calculate the cube root of a given positive integer. We can not remember why exactly we need this, but it has something in common with a princess, a young peasant, kissing and half of a kingdom (a huge one, we can assure you). 
Write a program to solve this crucial task.
Input

The input consists of large positive integers of up to 150 decimal digits.Each number is on its own separate line of the input file. The input file may contain empty lines. Numbers can be preceded or followed by whitespaces but no line exceeds 255 characters.
Output

For each number in the input file your program should output a line consisting of two values separated by single space. The second value is the cube root of the given number, truncated (not rounded!) after the 10th decimal place. First value is a checksum of all printed digits of the cube root, calculated as the sum of the printed digits modulo 10.
Sample Input

1
   	8

1000

     2
33076161
Sample Output

1 1.0000000000
2 2.0000000000
1 10.0000000000
0 1.2599210498
6 321.0000000000
*/


#include <stdio.h>
int main()
{
	double bottom,up,temp,rel,n;
	int i,sum;
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')
			continue;
		n=0;
		while(c!='\n')
		{
			n*=10;
			n+=c-'0';
			c=getchar();
		}
		bottom=0;up=n;
		while(up-bottom>1e-11)
		{
			temp=(up+bottom)/2;
			temp=temp*temp*temp;
			if(temp-n>1e-11)
				up=(up+bottom)/2;
			else
			{
				if(temp-n<1e-11)
					bottom=(up+bottom)/2;
				else
					up=bottom=(up+bottom)/2;
			}
		}
		rel=(up+bottom)/2;
		sum=0;
		temp=rel;
		while(temp-1>1e-11)
		{
			sum+=long(temp)%10;
			temp/=10;
		}
		temp=rel;
		for(i=0;i<10;i++)
		{
			temp*=10;
			sum+=long(temp)%10;
		}
		sum%=10;
		printf("%d %.10Lf\n",sum,rel);
	}
	return 0;
}
