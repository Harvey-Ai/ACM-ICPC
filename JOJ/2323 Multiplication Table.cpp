#include <stdio.h>
int main()
{
	int i,j,rel,dig,n;
	int arr[2];
	while(scanf("%d",&n),n!=-1)
	{
		for(i=1;i<n;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(j!=1)
					printf(" ");
				if(i>9)
					printf("%c*",i-10+'A');
				else
					printf("%d*",i);
				if(j>9)
					printf("%c=",j-10+'A');
				else
					printf("%d=",j);
				rel=i*j;
				dig=rel%n;
				rel/=n;
				arr[0]=dig;
				dig=rel%n;
				arr[1]=dig;
				if(arr[1]>9)
					printf("%c",arr[1]-10+'A');
				else
					printf("%d",arr[1]);
				if(arr[0]>9)
					printf("%c",arr[0]-10+'A');
				else
					printf("%d",arr[0]);	
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
						

