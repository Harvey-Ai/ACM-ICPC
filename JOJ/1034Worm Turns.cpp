#include <stdio.h>
int main()
{
	int worm[21][2];
	int n,i,head,move;
	char c;
	bool flag;
	while(scanf("%d",&n),n)
	{
		getchar();
		for(i=1;i<=20;i++)
		{
			worm[i][0]=25;
			worm[i][1]=i+10;
		}
		head=20;move=0;flag=0;
		while(n--)
		{
			c=getchar();
			move++;
			switch(c)
			{
			case 'N':
			{
				worm[head%20+1][0]=worm[head][0]-1;
				worm[head%20+1][1]=worm[head][1];
				break;
			}
			case 'S':
			{
				worm[head%20+1][0]=worm[head][0]+1;
				worm[head%20+1][1]=worm[head][1];
				break;
			}
			case 'W':
			{
				worm[head%20+1][0]=worm[head][0];
				worm[head%20+1][1]=worm[head][1]-1;
				break;
			}
			case 'E':
			{
				worm[head%20+1][0]=worm[head][0];
				worm[head%20+1][1]=worm[head][1]+1;
				break;
			}
			}
			head=head%20+1;
			for(i=1;i<=20;i++)
			{
				if(i==head)
					i++;
				if(worm[i][0]==worm[head][0]&&worm[i][1]==worm[head][1])
				{
					while(n--)
						getchar();
					printf("The worm ran into itself on move %d.\n",move);
					flag=1;
					break;
				}
			}
			if(worm[head][0]>50||worm[head][0]<1||worm[head][1]>50||worm[head][1]<1)
			{
				while(n--)
					getchar();
				printf("The worm ran off the board on move %d.\n",move);
				flag=1;
			}
			if(flag)
				break;
		}
		if(flag==0)
			printf("The worm successfully made all %d moves.\n",move);
	}
	return 0;
}







