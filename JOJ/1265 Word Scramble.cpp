#include <iostream>
using namespace std;
int main()
{
	bool flag;
	int i;
	char str[500],temp;
	while(scanf("%c",&str[0])!=EOF)
	{
		flag=0;
		i=0;
		while(str[i]!='\n')
		{
			i=0;
			while(str[i-1]!=32&&str[i-1]!='\n')
			{
				if(flag)
					str[i]=cin.get();
				else
					flag=1;
				i++;
			}
			if(str[0]==32)
			{
				cout<<' ';
				i=0;
			}
			else
			{
				str[i]='\0';
				i-=2;
				for(int j=0;j<=i/2;j++)
				{
					temp=str[j];
					str[j]=str[i-j];
					str[i-j]=temp;
				}
				cout<<str;
				i++;
			}
		}
	}
	return 0;
}