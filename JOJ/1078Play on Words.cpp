//回朔，肯定不行
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	bool check(char word[10000][2],char c,int n);
	int i,N,n,m;
	char s[100],word[10000][2],c;
	cin>>N;
	while(N--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s;
			m=strlen(s);
			word[i][0]=s[0];
			word[i][1]=s[m-1];
		}
		c=1;
		if(check(word,c,n))
			cout<<"Ordering is possible."<<endl;
		else
			cout<<"The door cannot be opened."<<endl;
	}
	return 0;
}

bool check(char word[1000][2],char c,int n)
{
	int i;
	char temp;
	bool flag=0;
	for(i=0;i<n;i++)
	{
		if((word[i][0]==c||c==1))
		{
			temp=word[i][0];
			word[i][0]='\0';
			flag=check(word,word[i][1],n);
			word[i][0]=temp;
		}
		if(flag)
			break;
	}
	if(flag)
		return flag;
	else
	{
		flag=1;
		for(i=0;i<n;i++)
			if(word[i][0]!='\0')
			{
				flag=0;
				break;
			}
		return flag;
	}
}
*/
