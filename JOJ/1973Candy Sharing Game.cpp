#include <iostream>
using namespace std;
int main()
{
	int i,n,temp,cnt;
	int arr[200];
	bool flag;
	while(cin>>n,n)
	{
		for(i=0;i<n;i++)
			cin>>arr[i];

		flag=1;cnt=0;
		while(flag)
		{
			cnt++;
			temp=arr[n-1];
			for(i=n-1;i>0;i--)
			{
				arr[i]-=arr[i]/2;
				arr[i]+=arr[i-1]/2;
			}
			arr[0]-=arr[0]/2;
			arr[0]+=temp/2;

			flag=0;
			for(i=0;i<=n-1;i++)
				if(arr[i]%2)
					arr[i]++;
			for(i=0;i<n-1;i++)
				if(arr[i+1]!=arr[i])
				{
					flag=1;
					break;
				}
		}
		cout<<cnt<<" "<<arr[0]<<endl;
	}
	return 0;
}

			
				

		
