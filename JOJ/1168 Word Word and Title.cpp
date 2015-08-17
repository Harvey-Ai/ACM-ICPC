包含的字符可能很多，所以,map
/*
#include <iostream>
#include <string>
using namespace std;
char arr[45][20]={"am","is","are","was","were","be","being","i","my","mine",
	"you","your","yours","he","him","his","she","her","it","its","they","them",
	"their","myself","himself","herself","itself","themself","in","on","out","into",
	"off","to","the","a","an","of","for","onto","upon","this","that","these","those"};

int main()
{
	bool check(char s[10000]);
	int cnt[600];
	int i,j,k,n,max,max_id;
	char str[510][10000];
	char c;
	bool flag;
	scanf("%d",&n);
	n--;
	c=getchar();
	while(c!='\n')c=getchar();
	while(n--)
	{
		memset(cnt,0,sizeof(cnt));
		c=getchar();
		i=-1;
		while(1)
		{
			j=0;flag=1;
			if(c>='A'&&c<='Z'||c>='a'&&c<='z')
				i++;
			else
				flag=0;
			while(c>='A'&&c<='Z'||c>='a'&&c<='z')
			{
				if(c<'a')
					c+=32;
				str[i][j]=c;
				j++;
				c=getchar();
			}
			if(flag)
			{
				str[i][j]='\0';
				if(check(str[i]))
				{
					for(k=0;k<=i;k++)
					   if(strcmp(str[i],str[k])==0)
					   {
					    	cnt[k]++;
					    	break;
					   }
				}
			}
			if(c=='\n')
			{
				c=getchar();
				if(c=='\n')
					break;
			}
			else
				c=getchar();
		}
		max=0;max_id=-1;
		for(j=0;j<=i;j++)
		{
			cout<<str[j]<<" ";
			if(cnt[j]>max)
			{
				max=cnt[j];
				max_id=j;
			}
			else
				if(cnt[j]==max)
				{
					if(strlen(str[j])>strlen(str[max_id]))
						max_id=j;
				}
		}
		if(max_id>=0)
			printf("%s\n",str[max_id]);
		else
			printf("\n");
	}
	i=-1;memset(cnt,0,sizeof(cnt));
	while(cin.get(c))
	{
		j=0;flag=1;
		if(c>='A'&&c<='Z'||c>='a'&&c<='z')
			i++;
		else
			flag=0;
		while(c>='A'&&c<='Z'||c>='a'&&c<='z')
		{
			if(c<'a')
				c+=32;
			str[i][j]=c;
			j++;
			c=getchar();
		}
		if(flag)
		{
			str[i][j]='\0';
			if(check(str[i]))
			{
				for(k=0;k<=i;k++)
					if(strcmp(str[i],str[k])==0)
					 {
					    cnt[k]++;
					    break;
					 }
			}
		}
	}
	max=0;
	for(j=0;j<=i;j++)
	{
		if(cnt[j]>max)
		{
			max=cnt[j];
			max_id=j;
		}
		else
			if(cnt[j]==max)
			{
				if(strlen(str[j])>strlen(str[max_id]))
					max_id=j;
			}
	}
	if(max_id>=0)
		printf("%s\n",str[max_id]);
	else
		printf("\n");
	return 0;
}

bool check(char s[10000])
{
	int i;
	for(i=0;i<45;i++)
		if(strcmp(s,arr[i])==0)
			return 0;
	return 1;
}

*/
//chihao
#include<iostream>
#include<map>
#include<algorithm>
#include<list>
#include<set>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;

string array[45]={"am","is","are","was","were","be","being","i","my","mine",
	"you","your","yours","he","him","his","she","her","it","its","they","them",
	"their","myself","himself","herself","itself","themself","in","on","out","into",
	"off","to","the","a","an","of","for","onto","upon","this","that","these","those"};

int main()
{
	int n;cin>>n;
	int i;
	char c=getchar();while(c!='\n')c=getchar();
	set<string> basic;
	for(i=0;i<45;++i)
		basic.insert(array[i]);

	while(n--)
	{
		map<string,int>record;
		string temp="";
		list<string>alist;
		c=getchar();
		bool flag=true;
		while(flag)
		{
			if(c==EOF)break;
			if(isalpha(c))
			{
				if(isupper(c))
					c+=32;
				temp+=c;
				c=getchar();
				continue;
			}
			if(c=='\n')
			{
				if(temp!="")
				{
					alist.push_back(temp);
			    record[temp]++;
				}
				temp="";
				c=getchar();
				while(c==' ')c=getchar();
				if(c=='\n')
				{
					flag=false;
					continue;
				}
				continue;
			}
			if(temp!="")
			{alist.push_back(temp);
			record[temp]++;
			}
			c=getchar();
			temp="";
		}
		map<string,int>::iterator it;int dmax=0;
		for(it=record.begin();it!=record.end();it++)
		{
			if((*it).second>dmax&&basic.find((*it).first)==basic.end())
			{
				temp=(*it).first;
				dmax=(*it).second;
				continue;
			}
			if((*it).second==dmax&&basic.find((*it).first)==basic.end())
			{
				if((int)(*it).first.size()==(int)temp.size())
				{
					list<string>::iterator it1=find(alist.begin(),alist.end(),(*it).first);
					list<string>::iterator it2=find(alist.begin(),it1,temp);
					if(it2==it1)temp=(*it).first;
					continue;
				}
				if((int)(*it).first.size()>(int)temp.size())
				{
					temp=(*it).first;
					continue;
				}
			}
		}
		cout<<temp<<endl;
	}
}
