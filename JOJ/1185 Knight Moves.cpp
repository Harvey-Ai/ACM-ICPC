#include <stdio.h>
int main()
{
	int graph[9][9],line[100][3];
	char c1,c2,c3,c4;
	int i,j,k,l,cnt,cl,ro,temp;
	bool flag;
	while(scanf("%c%c",&c1,&c2)!=EOF)
	{
		getchar();
		scanf("%c%c",&c3,&c4);
		getchar();
		if(c1==c3&&c2==c4)
		{
			printf("To get from %c%c to %c%c takes 0 knight moves.\n",c1,c2,c3,c4);
			continue;
		}
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				graph[i][j]=0;
		graph[c1-'a'+1][c2-'0']=1;
		graph[c3-'a'+1][c4-'0']=2;
		line[0][0]=c1-'a'+1;line[0][1]=c2-'0';line[0][2]=0;
		j=0;l=0;flag=1;
		while(flag)
		{
			cl=line[j][0];ro=line[j][1];cnt=line[j][2]+1;
			for(i=-2;i<=2;i++)
			{
				if(i==0)
					continue;
				if(i<0)
					temp=-i;
				else
					temp=i;
				if(temp%2)
					k=-2;
				else
					k=-1;
				if((cl+i)>0&&(cl+i)<=8&&(ro+k)>0&&(ro+k)<=8)
				{
					if(graph[cl+i][ro+k]==2)
					{
						flag=0;
						break;
					}
					else
						if(graph[cl+i][ro+k]==0)
						{
							graph[cl+i][ro+k]=1;
							l++;
							line[l][0]=cl+i;line[l][1]=ro+k;line[l][2]=line[j][2]+1;
						}
				}
				k=-k;
				if((cl+i)>0&&(cl+i)<=8&&(ro+k)>0&&(ro+k)<=8)
				{
					if(graph[cl+i][ro+k]==2)
					{
						flag=0;
						break;
					}
					else
						if(graph[cl+i][ro+k]==0)
						{
							graph[cl+i][ro+k]=1;
							l++;
						    line[l][0]=cl+i;line[l][1]=ro+k;line[l][2]=line[j][2]+1;
						}
				}
			}
			j++;
		
		}
		printf("To get from %c%c to %c%C takes %d knight moves.\n",c1,c2,c3,c4,cnt);
	}
	return 0;
}



		