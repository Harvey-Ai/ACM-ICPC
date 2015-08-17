#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	string arr;
	int i,j,n;
	char c;
	while(scanf("%d",&n),n!=-1)
	{
		getchar();
		arr.copy('0',1,0);
		for(i=1;i<=n;i++)
		{
			c=getchar();
			arr.copy(c,1,i);
			getchar();
			c=getchar();
			c=arr[i]+c-'0';
			j=i;
			while(c>'9'&&j)
			{
				arr[j]-=10;
				arr[j-1]+=1;
				j--;
			}
		}
		if(arr[0]!='0')
			printf("%c",arr[0]);
		for(i=1;i<=n;i++)
			printf("%c",arr[i]);
		printf("\n");
	}
	return 0;
}




