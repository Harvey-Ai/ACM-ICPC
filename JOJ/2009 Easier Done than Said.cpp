#include <iostream>
#include <string>
using namespace std;
char vowel[5]={'a','e','i','o','u'};
int main()
{
	bool check1(char str[100]);
	bool check2(char str[100]);
	char str[100];
	bool flag;
	while(cin>>str)
	{
		if(strcmp(str,"end"))
		{
			flag=check1(str)&&check2(str);
			if(flag)
				cout<<"<"<<str<<"> is acceptable."<<endl;
			else
				cout<<"<"<<str<<"> is not acceptable."<<endl;
		}
		else
			break;
	}
	return 0;
}

bool check1(char str[100])
{
	int i,j,cnt=0;
	bool flag,flag1,flag2;
	flag1=0;flag2=1;
	for(i=0;str[i]!='\0';i++)
	{
		flag=0;
		for(j=0;j<5;j++)
			if(str[i]==vowel[j])
			{
				if(cnt<0)
					cnt=1;
				else
					cnt++;
				flag=1;
				break;
			}
		if(flag==0)
		{
			if(cnt>0)
				cnt=-1;
			else
				cnt--;
		}
		if(cnt>2||cnt<-2)
			flag2=0;
		if(flag)
			flag1=1;
	}
	return (flag1&&flag2);
}

bool check2(char str[100])
{
	int i;
	bool flag=1;
	for(i=0;str[i+1]!='\0';i++)
	{
		if(str[i+1]==str[i]&&str[i]!='o'&&str[i]!='e')
		{
			flag=0;
			break;
		}
	}
	return flag;
}

		





