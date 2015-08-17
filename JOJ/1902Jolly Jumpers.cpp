#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	bool arr[3001];
	int t1,t2,i,n,temp;
	bool flag;
	while(cin>>n)
	{
		memset(arr,0,3001*sizeof(bool));
		cin>>t1;
		flag=1;
		for(i=1;i<n;i++)
		{
			cin>>t2;
			temp=t2-t1;
			t1=t2;
			if(temp<0)
				temp=-temp;
			if(temp>=n||temp==0)
			{
				flag=0;
				continue;
			}
			arr[temp]=1;
		}
		for(i=1;i<n;i++)
			if(arr[i]==0)
			{
				flag=0;
				break;
			}
		if(flag)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
	return 0;
}




