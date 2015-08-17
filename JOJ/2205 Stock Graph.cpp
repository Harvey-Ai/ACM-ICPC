#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int height[60][2],cnt[60];
	int i,j,k,l,n,max;
	scanf("%d",&n);
	l=1;
	while(l<=n)
	{
		printf("Case #%d:\n",l);
		for(i=0;i<60;i++)
		{
			height[i][0]=0;
			cnt[i]=0;
		}
		max=0;i=1;
		cin>>s;
		while(s[i-1]!='\0')
		{
			switch(s[i-1])
			{
			case'R':{height[i][0]=height[i-1][0]+1;height[i][1]=2;break;}
			case'F':{height[i][0]=height[i-1][0]-1;height[i][1]=0;break;}
			case'C':{height[i][0]=height[i-1][0];height[i][1]=1;break;}
			}
			i++;
		}
		for(j=1;j<i;j++)
		{
			if(height[j][1]==2)
				height[j][0]--;
			if(height[j][0]>max)
				max=height[j][0];
			cnt[height[j][0]]++;
		}
		for(j=max;j>=0;j--)
		{
			printf("| ");
			k=1;
			while(cnt[j])
			{
				if(height[k][0]!=j)
					printf(" ");
				else
				{
					cnt[j]--;
					switch(height[k][1])
					{
					   case 0:{printf("\\");break;}
					   case 1:{printf("_");break;}
					   case 2:{printf("/");break;}
					}
				}
				k++;
			}
			printf("\n");
		}
		printf("+");
		for(j=0;j<=i;j++)
			printf("-");
		printf("\n\n");
		l++;
	}
	return 0;
}
