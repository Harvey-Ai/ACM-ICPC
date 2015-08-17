/*
Description

You are given a bunch of wooden sticks. Each endpoint of each stick is colored with some color. Is it possible to align the sticks in a straight line such that the colors of the endpoints that touch are of the same color?
Input

Input is a sequence of lines, each line contains two words, separated by spaces, giving the colors of the endpoints of one stick. A word is a sequence of lowercase letters no longer than 10 characters. There is no more than 250000 sticks.
Output

If the sticks can be aligned in the desired way, output a single line saying Possible, otherwise output Impossible.
Sample Input

blue red
red violet
cyan blue
blue magenta
magenta cyan
Sample Output

Possible
Hint

*/


#include<stdio.h>
struct Node
{
   int id;
   Node *p[26];
   Node()
   {
      int i;
      id=-1;
      for(i=0;i<26;i++)
        p[i]=NULL;
   }
}root;
int set[500010];
bool du[500010];
int cnt;
int getnum(char *str)
{
	int i;
	Node *r=&root;
	for(i=0;str[i];i++)
	{
		if(r->p[str[i]-'a']==NULL)
			r->p[str[i]-'a']=new Node();
		r=r->p[str[i]-'a'];
	}
	if(r->id==-1)
		r->id=cnt++;
	return r->id;
}
int find(int k)
{
	int temp,a=k;
	while(set[a]>=0)
		a=set[a];
	while(k!=a)
	{
		temp=set[k];
		set[k]=a;
		k=temp;
	}
	return a;
}
void uion(int a,int b)
{
	int t1,t2;
	t1=find(a);
	t2=find(b);
	if(t1!=t2)
	{
		if(set[t1]<set[t2])
		{
			set[t1]+=set[t2];
			set[t2]=t1;
		
		}
		else
		{
			set[t2]+=set[t1];
			set[t1]=t2;
		}
	}
}
int main()
{
	char str1[15],str2[15];
	int i,ccnt,a,b;
	cnt=0;
	for(i=0;i<500010;i++)
		set[i]=-1;
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		a=getnum(str1);
		b=getnum(str2);
		du[a]^=1;
		du[b]^=1;
		uion(a,b);
	}
	if(cnt==0)
	{
		printf("Possible\n");
		return 0;
	}
	if((-set[find(0)])!=cnt)
		printf("Impossible\n");
	else
	{
		ccnt=0;
		for(i=0;i<cnt;i++)
			if(du[i])
			{
				ccnt++;
				if(ccnt>2)
					break;
			}
		if(ccnt>2)
			printf("Impossible\n");
		else
			printf("Possible\n");
	}
	return 0;
}
