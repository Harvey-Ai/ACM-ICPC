/*
Description

Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems. 

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
Input

The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
Output

The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
Sample Input

95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12
Sample Output

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/

#include <stdio.h>
#include <string>
void mult(char rel[500],char str[500])
{
	char temp[500],tem[500];
	int i,j,k,a,carry;
	for(i=0;i<499;i++)
		tem[i]='0';
	tem[499]='\0';
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='0') continue;
		carry=0;
		for(j=0;rel[j]!='\0';j++)
		{
			a=(str[i]-'0')*(rel[j]-'0')+carry;
			temp[j]=a%10+'0';
			carry=a/10;
		}
		if(carry)
		{
			temp[j]=carry+'0';
			j++;
		}
		carry=0;
		for(k=0;k<j;k++)
		{
			a=temp[k]+tem[k+i]-'0'-'0'+carry;
			tem[k+i]=a%10+'0';
			carry=a/10;
		}
		if(carry)
		{
			tem[k+i]=carry+'0';
			k++;
		}
	}
	tem[k+i-1]='\0';
	strcpy(rel,tem);
}

int main()
{
	char str[500],rel[500];
	int i,j,temp,plen,len,n;
	while(scanf("%s%d",str,&n)!=EOF)
	{
		//略去前导'0'
		for(i=0;str[i]=='0';i++);
		for(j=i;str[j-1]!='\0';j++)
			str[j-i]=str[j];

		//去除'.'
		for(i=0;str[i]!='.'&&str[i]!='\0';i++);
		for(plen=0;str[i]!='\0';i++,plen++)
			str[i]=str[i+1];
		if(str[i-1]=='\0')
		{
			plen--;
			i--;
		}
		for(j=0;j<i/2;j++)
		{
			temp=str[j];
			str[j]=str[i-j-1];
			str[i-j-1]=temp;
		}
		strcpy(rel,str);
		for(i=1;i<n;i++) mult(rel,str);
		len=strlen(rel);
		len--;
		plen*=n;
		while(len>=plen)
		{
			putchar(rel[len]);
			len--;
		}
		for(i=0;rel[i]=='0';i++);
		if(len>=i)
			putchar('.');
		else
		{
			putchar('\n');
			continue;
		}
		if(rel[len+1]=='\0')
		{
			plen--;
			while(len<plen)
			{
				putchar('0');
				plen--;
			}
		}
		while(len>=i)
		{
			putchar(rel[len]);
			len--;
		}
		putchar('\n');
	}
	return 0;
}

