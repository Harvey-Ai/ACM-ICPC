/*
Description

A catenym is a pair of words separated by a period such that the last letter of the first word is the same as the last letter of the second. For example, the following are catenyms: 
dog.gopher

gopher.rat

rat.tiger

aloha.aloha

arachnid.dog

A compound catenym is a sequence of three or more words separated by periods such that each adjacent pair of words forms a catenym. For example, 

aloha.aloha.arachnid.dog.gopher.rat.tiger 

Given a dictionary of lower case words, you are to find a compound catenym that contains each of the words exactly once.
Input

The first line of standard input contains t, the number of test cases. Each test case begins with 3 <= n <= 1000 - the number of words in the dictionary. n distinct dictionary words follow; each word is a string of between 1 and 20 lowercase letters on a line by itself.
Output

For each test case, output a line giving the lexicographically least compound catenym that contains each dictionary word exactly once. Output "***" if there is no solution.
Sample Input

2
6
aloha
arachnid
dog
gopher
rat
tiger
3
oak
maple
elm
Sample Output

aloha.arachnid.dog.gopher.rat.tiger
***
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct dd
{
	char str[30];
	char bg,ed;
}ss[1001];
int iindex[26][1005],res[1001],used[1001],rudu[26],chudu[26];
int ok,n;
void dfs(int p,int num)
{
	if(ok)
		return;
	int i,a;
	if(num==n)
	{
		printf("%s",ss[res[0]].str);
		for(i=1;i<n;i++)
			printf(".%s",ss[res[i]].str);
		putchar('\n');
		ok=1;
		return;
	}
	a=ss[p].ed-'a';
	for(i=1;i<=iindex[a][0];i++)
		if(used[iindex[a][i]]==0)
		{
			used[iindex[a][i]]=1;
			res[num]=iindex[a][i];
			dfs(iindex[a][i],num+1);
			used[iindex[a][i]]=0;
		}
}
bool cmp(const dd a,const dd b)
{
	if(strcmp(a.str,b.str)<=0)
		return 1;
	else
		return 0;
}
int main()
{
	char c;
	int i,j,a,ncase,chu,ru,id;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			c=getchar();
			for(j=0;c!='\n';j++)
			{
				ss[i].str[j]=c;
				c=getchar();
			}
			ss[i].str[j]='\0';
			ss[i].bg=ss[i].str[0];
			ss[i].ed=ss[i].str[j-1];
		}
		sort(&ss[0],&ss[n],cmp);
		for(i=0;i<26;i++)
		{
			iindex[i][0]=0;
			chudu[i]=rudu[i]=0;
		}
		for(i=0;i<n;i++)
		{
			a=ss[i].bg-'a';
			iindex[a][0]++;
			iindex[a][iindex[a][0]]=i;
		}
		for(i=0;i<n;i++)
		{
			a=ss[i].bg-'a';
			rudu[a]++;
			a=ss[i].ed-'a';
			chudu[a]++;
		}
		ru=chu=0;
		for(i=0;i<26;i++)
			if(iindex[i][0])
			{
				id=i;
				break;
			}
		for(i=0;i<26;i++)
		{
			if(rudu[i]-chudu[i]>0)
			{
				ru+=rudu[i]-chudu[i];
				id=i;
			}
			else
				chu+=chudu[i]-rudu[i];
		}
		if(ru>1||chu>1)
		{
			printf("***\n");
			continue;
		}
		ok=0;
		memset(used,0,sizeof(used));
		id=iindex[id][1];
		used[id]=1;
		res[0]=id;
		dfs(id,1);
		if(ok==0)
			printf("***\n");
	}
	return 0;
}
