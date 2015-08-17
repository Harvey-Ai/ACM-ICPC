#include <iostream>
using namespace std;
int main()
{
	int i,j,n,xi,yi,cnt,max,sum;
	int arr[20][20];
	bool flag;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>arr[i][j];

		cnt=0;sum=0;
		while(cnt<n)
		{
			flag=1;max=0;xi=-1;yi=-1;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					if(max<arr[i][j])
					{
						max=arr[i][j];
						xi=i;
						yi=j;
					}
			}
			arr[xi][yi]=0;
			sum+=max;
			flag=1;
			for(i=0;i<n;i++)
			{
				if(arr[xi][i]==max)
				{
					arr[xi][i]=0;
					flag=0;
				}
				if(arr[i][yi]==max)
				{
					arr[i][yi]=0;
					flag=0;
				}
			}

			if(flag)
				for(i=0;i<n;i++)
					arr[xi][i]=arr[i][yi]=0;

			cnt++;
		}
		cout<<sum<<endl;
	}
	return 0;
}



	