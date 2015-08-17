#include <iostream>
using namespace std;
int main()
{
	long arr[31],max;
	int i,j,n;
	arr[1]=1;
	for(i=2;i<=30;i++)
	{
		max=i;
		for(j=1;j<i;j++)
			if(max<j*arr[i-j])
				max=j*arr[i-j];
		arr[i]=max;
	}
	while(cin>>n)
		cout<<arr[n]<<endl;
	return 0;
}

