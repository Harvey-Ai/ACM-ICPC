#include <iostream>
using namespace std;
int main()
{
	long arr[100],max;
	int i,n;
	while(cin>>n,n)
	{
		max=-100000;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			if(max<arr[i])
				max=arr[i];
		}
		cout<<max<<endl;
	}
	return 0;
}
		
