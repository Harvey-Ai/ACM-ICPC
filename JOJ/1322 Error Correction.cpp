#include <iostream>
using namespace std;
int main()
{
	int i,j,n,error1,error2;
	int arr[101][101];
	int flag;
	while(cin>>n,n)
	{
		for(i=1;i<=n;i++)
			arr[0][i]=arr[i][0]=0;

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cin>>arr[i][j];
				arr[0][j]+=arr[i][j];
				arr[i][0]+=arr[i][j];
			}
		error1=-1;error2=-1;flag=0;
		for(i=1;i<=n;i++)
		{
			if(arr[i][0]%2!=0)
			{
				if(error1==-1)
				{
					error1=i;
					flag=1;
				}
				else
				{
					flag=2;
					break;
				}
			}
			if(arr[0][i]%2!=0)
			{
				if(error2==-1)
				{
					error2=i;
					flag=1;
				}
				else
				{
					flag=2;
					break;
				}
			}
		}
		if(flag==0)
			cout<<"OK"<<endl;
		else
		{
			if(flag==1&&error1!=-1&&error2!=-1)
				cout<<"Change bit ("<<error1<<","<<error2<<")"<<endl;
			else
				cout<<"Corrupt"<<endl;
		}
	}
	return 0;
}






