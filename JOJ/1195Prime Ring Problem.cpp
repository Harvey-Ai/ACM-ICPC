#include <iostream>
using namespace std;
int prime[20]={2,3,5,7,11,13,17,19,23,29,31};
int main()
{
	void search(int cir[16],int arr[17],int j,int n);
	int n,i,l=1;
	int circle[16],arr[17];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<16;i++)
			circle[i]=0;
		for(i=0;i<17;i++)
			arr[i]=i;
		circle[0]=1;
		printf("Case %d:\n",l);
		if(n%2==0)
			search(circle,arr,1,n-1);
		l++;
		cout<<endl;
	}
	return 0;
}

void search(int cir[16],int arr[17],int j,int n)
{
	int i,k,sum;
	bool flag;
	for(i=2;i<=n+1;i++)
	{
		if(arr[i])
		{
			cir[j]=arr[i];
			arr[i]=0;
			flag=0;sum=cir[j]+cir[j-1];
			for(k=0;k<11;k++)
				if(sum==prime[k])
				{
					flag=1;
					break;
				}
			if(flag)
				search(cir,arr,j+1,n);
			arr[i]=cir[j];
		}
	}
	if(j==n+1)
	{
		flag=0;
		sum=cir[n]+1;
		for(k=0;k<11;k++)
			if(sum==prime[k])
			{
				flag=1;
				break;
			}
		if(flag)
		{
			printf("%d",cir[0]);
			for(k=1;k<=n;k++)
				printf(" %d",cir[k]);
			printf("\n");
		}
	}
}

