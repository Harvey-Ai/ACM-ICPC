#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int arr[200001];
	int i,n;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(&arr[0],&arr[n]);
		for(i=n-1;i>=2;i--)
		{
			if(arr[i]<arr[i-1]+arr[i-2])
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("%d\n",arr[i]+arr[i-1]+arr[i-2]);
		else
			printf("0\n");
	}
	return 0;
}

