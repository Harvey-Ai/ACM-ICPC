#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i,n,arr[1000];
	while(cin>>n,n)
	{
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(&arr[0],&arr[n]);
		if(n%2)
			cout<<arr[n/2]<<endl;
		else
			cout<<(arr[n/2]+arr[n/2-1])/2.0<<endl;
	}
	return 0;
}
