#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
struct Election
{
	char candidates[100];
	char party[100];
	int sum;
};


int main()
{
	int i,j,n,m,max,id;
	char c;
	char p[100];
	bool flag;
	Election arr[50];
	while(cin>>n)
	{
		for(i=0;i<50;i++)
			arr[i].sum=0;
		j=n;cin.get();
		while(j--)
		{
			
			i=0;c=cin.get();
			while(c!='\n')
			{
				arr[j].candidates[i]=c;
				i++;
				c=cin.get();
			}
			arr[j].candidates[i]='\0';
			i=0;c=cin.get();
			while(c!='\n')
			{
				arr[j].party[i]=c;
				i++;
				c=cin.get();
			}
			arr[j].party[i]='\0';
		}
		cin>>m;
		cin.get();
		while(m--)
		{
			c=cin.get();i=0;
			while(c!='\n')
			{
				p[i]=c;
				i++;
				c=cin.get();
			}
			p[i]='\0';
			for(i=0;i<n;i++)
			{
				if(strcmp(p,arr[i].candidates)==0)
				{
					arr[i].sum++;
					break;
				}
			}
		}
		max=0;id=-1;flag=1;
		for(i=0;i<n;i++)
		{
			if(arr[i].sum>max)
			{
				max=arr[i].sum;
				id=i;
				flag=1;
			}
			else
			{
				if(arr[i].sum==max)
					flag=0;
			}
		}
		if(flag)
			cout<<arr[id].party<<endl;
		else
			cout<<"tie"<<endl;
	}
	return 0;
}




				


				


