#include <iostream>
using namespace std;
int arr[1001][1001];
int main()
{
	int i,j,n;
	bool flag;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
		flag=1;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(arr[i][j]+arr[i+1][j+1]!=arr[i+1][j]+arr[i][j+1])
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
				break;
		}
		if(flag)
			cout<<"homogeneous"<<endl;
		else
			cout<<"not homogeneous"<<endl;
	}
	return 0;
}


