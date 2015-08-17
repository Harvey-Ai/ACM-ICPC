//这一题我写了不少的时间，开始的时候没考虑到大数，后来知道后却迟迟未能AC。
//经过我的坚苦卓绝的调试，发现字符加法的函数写错了！基础这是很重要啊。
#include <iostream>
using namespace std;
char way[2][301][500];
int main()
{
	void add(char str1[],char str2[],char str[]);
	int node[1000][2];
	int i,j,k,m,n,t;
	bool flag;
	while(cin>>m>>n>>t)
	{
		if(m==0||n==0)
			continue;
		for(i=0;i<301;i++)
		{
			way[0][i][0]=way[1][i][0]='0';
			way[0][i][1]=way[1][i][1]='\0';
		}
		way[1][0][0]='1';
		k=0;
		while(k++<t)
			cin>>node[k-1][0]>>node[k-1][1];
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=m;i++)
			{
				flag=1;
				for(k=0;k<t;k++)
					if(node[k][0]==i&&node[k][1]==j)
					{
						way[1][i][0]='0';
						way[1][i][1]='\0';
						flag=0;
					}
				if(flag)
					add(way[0][i],way[1][i-1],way[1][i]);
				else
					strcpy(way[0][i],way[1][i]);
			}
			for(k=1;k<=m;k++)
				strcpy(way[0][k],way[1][k]);
			way[1][0][0]='0';
		}
		for(i=0;i<501;i++)
			if(way[1][m][i]=='\0')
				break;
		while(i--)
			cout<<way[1][m][i];
		cout<<endl;
	}
	return 0;
}

void add(char str1[],char str2[],char str[])
{
	int i=0,carry=0;
	while(str1[i]!='\0'&&str2[i]!='\0')
	{
		str[i]=(str1[i]+str2[i]+carry-'0'-'0')%10+'0';
		carry=(str1[i]+str2[i]+carry-'0'-'0')/10;
		i++;
	}
	if(str1[i]!='\0')
	{
		while(str1[i++]!='\0')
		{
			str[i-1]=(str1[i-1]+carry-'0')%10+'0';
			carry=(str1[i-1]+carry-'0')/10;
		}
		i--;
	}
	else
	{
		while(str2[i++]!='\0')
		{
			str[i-1]=(str2[i-1]+carry-'0')%10+'0';
			carry=(str2[i-1]+carry-'0')/10;
		}
		i--;
	}
	if(carry)
	{
		str[i]=carry+'0';
		str[i+1]='\0';
	}
	else
		str[i]='\0';

}
/*
12357
0
12357 0
12357
123575
0
123575 0
123575
15537516
0
15537516 0
15537516
0
15647
0 15647
156475
*/







