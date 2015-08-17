#include <iostream>
using namespace std;
int main()
{
	long long temp,n;
	int arr[10],dig,i,j,cnt;
	bool flag;
	while(cin>>n)
	{
		for(i=1;;i++)
		{  	
			flag=1;
			for(j=0;j<10;j++)
				arr[j]=0;
			temp=n*i;cnt=0;

			while(temp)
			{
				dig=temp%10;
				if(arr[dig])
					flag=0;
				else
					arr[dig]=1;
				temp/=10;
				cnt++;
			}
			if(cnt>10)
				break;

			temp=i;
			for(j=0;j<10;j++)
				arr[j]=0;

			while(temp)
			{
				dig=temp%10;
				if(arr[dig])
					flag=0;
				else
					arr[dig]=1;
				temp/=10;
			}
			if(flag)
				cout<<n*i<<" / "<<i<<" = "<<n<<endl;
		}
	}
	return 0;
}
			