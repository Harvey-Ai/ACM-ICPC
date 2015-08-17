#include <stdio.h>
int main()
{
	bool flag;
	int n,i1,j1,i2,j2,k,l,i;
	int arr1[10],arr2[10],arr[15];
	char d;
	scanf("%d",&n);
	while(n--)
	{    
		flag=0;
		i1=0;
		j1=0;

		while(scanf("%d%c",&arr1[i1++],&d),d!='\n');
		while(scanf("%d%c",&arr2[j1++],&d),d!='\n');

		arr[0]=arr1[0]+arr2[0];

		for(i=1;i<=14;i++)
			arr[i]=0;

		for(i2=1;i2<=i1-1;i2++)
			for(j2=1;j2<=j1-1;j2++)
				arr[i2+j2-1]+=arr1[i2]*arr2[j2];

		for(k=1;k<=arr[0]-1;k++){
			if(arr[k]!=0)
			{
				if(arr[k]!=1)
					printf("%d",arr[k]);
				printf("x^%d",arr[0]+1-k);
				flag=1;
				break;
			}
		}

		for(l=k+1;l<=arr[0]-1;l++)
		{
			if(arr[l]!=0)
				if(flag)
				{
					printf(" + ");
					if(arr[l]!=1)
						printf("%d",arr[l]);
					printf("x^%d",arr[0]+1-l);
				}
				
		}
		
		if(arr[arr[0]]!=0)
			if(flag)
				printf(" + %dx",arr[arr[0]]);
			else
			{
				printf("%dx",arr[arr[0]]);
				flag=1;
			}

		if(arr[arr[0]+1]!=0)
			if(flag)
				printf(" + %d",arr[arr[0]+1]);
			else
			{
				printf("%d",arr[arr[0]+1]);
				flag=1;
			}
		if(flag==0)
			printf("0");
		printf("\n");
	}
	return 0;
	
}