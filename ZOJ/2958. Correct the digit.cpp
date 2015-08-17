/*
To our acknowledgement, numbers can be displayed on computer screen as below, from 0 to 9:

._. ... ._. ._. ... ._. ._. ._. ._. ._.
|.| ..| ._| ._| |_| |_. |_. ..| |_| |_|
|_| ..| |_. ._| ..| ._| |_| ..| |_| ._|
As you can see, vertical bars and horizontal bars descript digits.

This technology has been used in Cheer bank today. The bank use optical scanner to read the accounts of checks, and display them on computer screen. But there is something wrong with the optical scanner, sometimes it recognizes bars (either vertical or horizontal) as dots. This makes some digit incorrect. To cope with such situation, the bank uses checksum.

The account in a check will always has 9 digit, namely, d1, d2, d3, ..., d9. We consider the account read by the scanner correct if
(9d1 + 8d2 + 7d3 + ... + d9) mod 11 = 0

You are to write a program to detect errors and try to correct them.

Note: Error seldom occurs. So if this does happen, at most 1 digit would be incorrect.

Input

There are multiple test cases for this problem.

There are three lines for each test. Each line contains 27 characters, with no leading and tailing spaces. And you can assume that there is no malformed input, errors will just replace bars with dots.

Output

Output the actual account for each test case if there is no error or the error can be corrected. If you can't find any solution, output "failure". If you can find more than one solution, output "ambiguous".

Sample Input

...._.._....._.._.._.._.._.
..|._|._||_||_.|_...||_||_|
..|._.._|..|._||_|..||_|._|
._.._.._.._.._.._.._.._.._.
|_||_||_||_||_||_||_||_||_|
|_||_||_||_||_||_||_||_||_|
...._.._.._.._.._.._....._.
|_||_||.||.||_...|..|..||_.
..|._||_||_||_|..|..|..|._|
._....._.._.._.._.._.._.._.
|_|..||_||_||_||_||_||_||_|
|_|..||_||_||_||_||_||_||_|
Sample Output

123456789
failure
ambiguous
878888888
Hint

The solution for the first sample should be 123456789 because the second digit can be 2 or 3, but if it is 3, checksum will not be satisfied. And the fifth digit can be 5 or 6, but if the fifth digit is 6, there will be 2 two incorrect digits, this violates the rule: "at most 1 digit would be incorrect".
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char cdig[10][10]={"._.|.||_|",".....|..|","._.._||_.","._.._|._|","...|_|..|","._.|_.._|",
	"._.|_.|_|","._...|..|","._.|_||_|","._.|_|._|"};
	char dig[3][31],temp[10];
	int rel[11],corr[11],d[11][11];
	int i,j,k,flag,flaure,l,s,ero,sum,cnt,tt;
	while(scanf("%s",dig[0])!=EOF)
	{
		scanf("%s",dig[1]);
		scanf("%s",dig[2]);
		cnt=0;flaure=0;
		for(i=0;i<9;i++)
		{
			for(j=i*3;j<i*3+3;j++)
				temp[j-3*i]=dig[0][j];
			
			for(j=i*3;j<i*3+3;j++)
				temp[j-3*i+3]=dig[1][j];
			
			for(j=i*3;j<i*3+3;j++)
				temp[j-3*i+6]=dig[2][j];
			temp[9]='\0';

			l=0;
			corr[i]=-1;
			for(j=0;j<10;j++)
			{
				ero=0;flag=1;
				for(k=0;k<10;k++)
					if(temp[k]!=cdig[j][k])
					{
						flag=0;
						if(cdig[j][k]=='.')
						{
							ero=1;
							break;
						}
					}
				if(flag)
				{
					corr[i]=j;
					cnt++;
				}
				else
					if(ero==0)
						d[i][++l]=j;
			}
			if(l==0&&corr[i]==-1)
				flaure=1;
			d[i][0]=-l;
		}
		if(flaure||cnt<8)
			printf("failure\n");
		else
		{
			s=0;
			if(cnt==9)
			{
				sum=0;
				for(i=0;i<9;i++)
					sum+=corr[i]*(9-i);
				for(i=0;i<9;i++)
					rel[i]=corr[i];
				if(sum%11==0) 
					s++;

				for(i=0;i<9;i++)
				{
					tt=rel[i];
					sum-=tt*(9-i);
					for(j=1;j<=-d[i][0];j++)
					{
						sum+=d[i][j]*(9-i);
						if(sum%11==0)
						{
							rel[i]=d[i][j];
							s++;
						}
						sum-=d[i][j]*(9-i);
					}
					sum+=tt*(9-i);
					if(s>1)
						break;
				}
			}
			else
			{
				sum=0;
				for(i=0;i<9;i++)
				{
					if(corr[i]==-1)
						j=i;
					else
					{
						rel[i]=corr[i];
						sum+=corr[i]*(9-i);
					}
				}
				i=j;
				for(j=1;j<=-d[i][0];j++)
				{
					sum+=d[i][j]*(9-i);
					if(sum%11==0)
					{
						s++;
						rel[i]=d[i][j];
					}
					sum-=d[i][j]*(9-i);
					if(s>1) break;
				}
			}
			if(s>1)
				printf("ambiguous\n");
			if(s==0)
				printf("failure\n");
			if(s==1)
			{
				for(i=0;i<9;i++)
					printf("%d",rel[i]);
				putchar('\n');
			}
		}
	}
	return 0;
}
