/*
#include <iostream>
#include <string>
using namespace std;
int main()
{	
	char s1[100000],s2[100000];
	char c;
	int i,j;
	bool flag;
	while(cin.get(c))
	{
		i=0;
		while(c!=' ')
		{
			s1[i]=c;
			c=cin.get();
			i++;
		}
		s1[i]='\0';
		i=0;c=cin.get();
		while(c!='\n')
		{
			s2[i]=c;
			c=cin.get();
			i++;
		}
		s2[i]='\0';
		flag=1;i=0;j=0;
		while(s2[j]!='\0')
		{
			if(s1[i]==s2[j])
				i++;
			j++;
		}
		if(s1[i]!='\0')
			flag=0;
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{	
	char s1[200000],s2[200000];
	char c;
	long i,j;
	bool flag;
	while(cin.get(c))
	{
		i=0;
		while(c!=' ')
		{
			s1[i]=c;
			c=cin.get();
			i++;
		}
		s1[i]='\0';
		i=0;c=cin.get();
		while(c!='\n')
		{
			s2[i]=c;
			c=cin.get();
			i++;
		}
		s2[i]='\0';
		flag=1;i=0;j=0;
		while(s1[i]!='\0')
		{
			while(s1[i]!=s2[j]&&s2[j]!='\0')
				j++;
			if(s2[j]=='\0')
				break;
			j++;i++;
		}
		if(s1[i]!='\0')
			flag=0;
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}