//过了，但是明显是不对的，
//测试数据：4 jlu uba ubc ckw(反过来)
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int dfs(char str[14][2],int cnt[14],int n,char c);
	string s;
	char str1[14][2],str2[14][2];
	int cnt[14];
	int i,j,n,sum,max;
	while(scanf("%d",&n)!=EOF)
	{
		i=n;
		while(i--)
		{
			cin>>s;
			str1[i][0]=str2[i][0]=*s.begin();
			str1[i][1]=str2[i][1]=*(s.end()-1);
			cnt[i]=s.length();
		}
		max=0;
		for(i=0;i<n;i++)
		{
			str1[i][0]='\0';
			sum=dfs(str1,cnt,n,str1[i][1])+cnt[i];
			if(max<sum)
				max=sum;
			for(j=0;j<n;j++)		
			{				
				str1[j][0]=str2[j][0];			
				str1[j][1]=str2[j][1];			
			}
		}
		printf("%d\n",max);
	}
	return 0;
}

int dfs(char str[14][2],int cnt[14],int n,char c)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(str[i][0]==c)
		{
			str[i][0]='\0';
			return dfs(str,cnt,n,str[i][1])+cnt[i];
		}
	}
	return 0;
}
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int dfs(int graph[26][26],int m);
	string s;
	char a,b;
	int c,graph[26][26];
	int i,j,n,temp,sum,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				graph[i][j]=0;
		i=n;
		while(i--)
		{
			cin>>s;
			a=*s.begin();
			b=*(s.end()-1);
			c=s.length();
			if(a==b)
				graph[a-'a'][b-'a']+=c;
			else
				graph[a-'a'][b-'a']=c;
		}
		max=0;
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
			{
				if(graph[i][j])
				{
					temp=graph[i][j];
					graph[i][j]=0;
					sum=dfs(graph,j)+temp;
					if(max<sum)
						max=sum;
					graph[i][j]=temp;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}

int dfs(int graph[26][26],int m)
{
	int j,temp,sum,max=0;
	for(j=0;j<26;j++)
	{
		if(graph[m][j])
		{
			temp=graph[m][j];
			graph[m][j]=0;
			sum=dfs(graph,j)+temp;
			if(max<sum)
				max=sum;
			graph[m][j]=temp;
		}
	}
	return max;
}