#include <iostream>
using namespace std;
int main()
{
	int i,j;
	char c1,c2;
	char str1[10],str2[10];
	bool flag=1;
	while(cin.get(c1))
	{
		if(c1=='<')
		{
			i=0;
			c2=cin.get();
			while(c2!='>'&&i<=9&&cin.peek()!='<')
			{
				str1[i]=str2[i]=c2;
				c2=cin.get();
				if(str1[i]>='A'&&str1[i]<='Z')
					str1[i]+=32;
				i++;
			}
			str1[i]='\0';
			if(c2=='>')
			{
				if(strcmp("/html",str1)==0)
					continue;
				if(strcmp("b",str1)==0||strcmp("i",str1)==0||strcmp("body",str1)==0||strcmp("head",str1)==0)
					continue;
				if(strcmp("tr",str1)==0||strcmp("td",str1)==0||strcmp("br",str1)==0||strcmp("marquee",str1)==0)
					continue;
				if(strcmp("html",str1)==0||strcmp("table",str1)==0||strcmp("title",str1)==0||strcmp("blink",str1)==0)
					continue;
				if(strcmp("/tr",str1)==0||strcmp("/td",str1)==0||strcmp("/i",str1)==0||strcmp("/b",str1)==0)			
					continue;
				if(strcmp("/blink",str1)==0||strcmp("/table",str1)==0||strcmp("/title",str1)==0)
					continue;
				if(strcmp("/marquee",str1)==0||strcmp("/head",str1)==0||strcmp("/body",str1)==0)
					continue;		
			}
			cout<<c1;
			for(j=0;j<i;j++)
				cout<<str2[j];
			cout<<c2;
		}
		else
			cout<<c1;
	}
	return 0;
}
