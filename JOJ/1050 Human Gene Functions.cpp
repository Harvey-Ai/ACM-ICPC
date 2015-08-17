#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	char str1[110],str2[110];
	int graph[110][110];
	int i,j,N,l1,l2,temp;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&l1);
		getchar();
		for(i=1;i<=l1;i++)
			str1[i]=getchar();

		scanf("%d",&l2);
		getchar();
		for(i=1;i<=l2;i++)
			str2[i]=getchar();
		graph[0][0]=0;
		for(i=1;i<=l1;i++)
		{
			switch(str1[i])
			{
				case 'A':{graph[i][0]=graph[i-1][0]-3;break;}
				case 'C':{graph[i][0]=graph[i-1][0]-4;break;}
				case 'G':{graph[i][0]=graph[i-1][0]-2;break;}
				case 'T':{graph[i][0]=graph[i-1][0]-1;break;}
				default:break;
			}
		}
		for(j=1;j<=l2;j++)
		{
			switch(str2[j])
			{
				case 'A':{graph[0][j]=graph[0][j-1]-3;break;}
				case 'C':{graph[0][j]=graph[0][j-1]-4;break;}
				case 'G':{graph[0][j]=graph[0][j-1]-2;break;}
				case 'T':{graph[0][j]=graph[0][j-1]-1;break;}
				default:break;
			}
		}
		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++)
			{
				temp=abs(str1[i]-str2[j]);
				switch(temp)
				{
				case 0:{graph[i][j]=graph[i-1][j-1]+5;break;}
				case 2:{graph[i][j]=graph[i-1][j-1]-1;break;}
				case 4:{graph[i][j]=graph[i-1][j-1]-3;break;}
				case 6:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 13:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 17:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 19:{graph[i][j]=graph[i-1][j-1]-1;break;}
				case 20:{graph[i][j]=graph[i-1][j-1]-3;break;}
				case 22:{graph[i][j]=graph[i-1][j-1]-4;break;}
				case 26:{graph[i][j]=graph[i-1][j-1]-2;break;}
				case 39:{graph[i][j]=graph[i-1][j-1]-1;break;}
				default:break;
				}
				switch(str1[i])
				{
				case 'A':{temp=graph[i-1][j]-3;break;}
				case 'C':{temp=graph[i-1][j]-4;break;}
				case 'G':{temp=graph[i-1][j]-2;break;}
				case 'T':{temp=graph[i-1][j]-1;break;}
				default:break;
				}
				if(temp>graph[i][j])
					graph[i][j]=temp;
				switch(str2[j])
				{
				case 'A':{temp=graph[i][j-1]-3;break;}
				case 'C':{temp=graph[i][j-1]-4;break;}
				case 'G':{temp=graph[i][j-1]-2;break;}
				case 'T':{temp=graph[i][j-1]-1;break;}
				default:break;
				}
				if(temp>graph[i][j])
					graph[i][j]=temp;
			}
		printf("%d\n",graph[l1][l2]);
	}
	return 0;
}
