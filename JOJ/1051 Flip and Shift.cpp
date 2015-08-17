#include <iostream>
using namespace std;
int main()
{
	int i,n,m,sum1,sum2,k;
	int arr[1000];
	cin>>n;
	while(n--)
	{
		sum1=sum2=0;
		cin>>m;
		for(i=0;i<m;i++)
			cin>>arr[i];
		for(i=0;i<m;i++)
		{
			if(arr[i])
			{
				if(i%2)
					sum1++;
				else
					sum2++;
			}
		}
		k=sum1-sum2;
		if(m%2||k<=1&&k>=-1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}


