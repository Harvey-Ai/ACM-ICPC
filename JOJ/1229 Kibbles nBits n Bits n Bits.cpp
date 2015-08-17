#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int arr[1000];
	long i,j,n,sum1,sum2,temp,rel;
	char c,fuhao;
	cin>>n;
	cin.get();
	while(n--)
	{
		c=cin.get();i=0;sum1=0;
		while(c!=' ')
		{
			switch(c)
			{
			case 'A':{arr[i]=10;break;}
			case 'B':{arr[i]=11;break;}
			case 'C':{arr[i]=12;break;}
			case 'D':{arr[i]=13;break;}
			case 'E':{arr[i]=14;break;}
			case 'F':{arr[i]=15;break;}
			default:{arr[i]=c-'0';break;}
			}
			c=cin.get();
			i++;
		}
		temp=1;
		for(j=i-1;j>=0;j--)
		{
			sum1+=temp*arr[j];
			temp*=16;
		}
		fuhao=cin.get();
		cin.get();
		c=cin.get();i=0;sum2=0;
		while(c!='\n')
		{
			switch(c)
			{
			case 'A':{arr[i]=10;break;}
			case 'B':{arr[i]=11;break;}
			case 'C':{arr[i]=12;break;}
			case 'D':{arr[i]=13;break;}
			case 'E':{arr[i]=14;break;}
			case 'F':{arr[i]=15;break;}
			default:{arr[i]=c-'0';break;}
			}
			c=cin.get();
			i++;
		}
		temp=1;
		for(j=i-1;j>=0;j--)
		{
			sum2+=temp*arr[j];
			temp*=16;
		}
		if(fuhao=='+')
			rel=sum1+sum2;
		else
			rel=sum1-sum2;
		i=0;memset(arr,0,sizeof(arr));
		while(sum1)
		{
			arr[i]=sum1%2;
			sum1/=2;
			i++;
		}
		for(j=12;j>=0;j--)
			cout<<arr[j];
		cout<<" "<<fuhao<<" ";
		i=0;memset(arr,0,sizeof(arr));
		while(sum2)
		{
			arr[i]=sum2%2;
			sum2/=2;
			i++;
		}
		for(j=12;j>=0;j--)
			cout<<arr[j];
		cout<<" = "<<rel<<endl;
	}
	return 0;
}
