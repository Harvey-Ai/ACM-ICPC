#include <iostream>
using namespace std;
int main()
{
	void sort(int p[],int n);
	int i,l,sum,c;
	int p[1000];
	cin>>i;
	c=i;
	while(i--)
	{
		cin>>sum>>l;
		for(int k=0;k<=l-1;k++)
			cin>>p[k];
		sort(p,l);
		cout<<"Scenario #"<<c-i<<":"<<endl;
		for(int m=0;m<=l-1;m++)
		{
			sum-=p[m];
			if(sum<=0)
			{
				cout<<m+1<<endl;
				break;
			}
		}
		if(sum>0)
			cout<<"impossible"<<endl;
		cout<<endl;
	}
	return 0;
}

void sort(int p[],int n)
{
	int i,k;
	int temp;
	for(i=0;i<=n-1;i++)
		for(k=i+1;k<=n-1;k++)
			if(p[k]>p[i])
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
			}
}





		