#include <iostream>
using namespace std;
int main()
{
	int i,j,k,n;
	int arr[1000][2];
	bool flag;
	char c;
	while(cin>>n,n)
	{
		for(i=0;i<n;i++)
		{
			cin>>arr[i][0];
			c=cin.get();
			cin>>arr[i][1];
			if(c=='-')
				arr[i][1]=-arr[i][1];
			cin.get();
		}

		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(arr[i][0]+arr[j][0]+arr[k][0]==0&&arr[i][1]+arr[j][1]+arr[k][1]==0)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

