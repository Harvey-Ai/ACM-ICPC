#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b,c,i,n;
	long max,min,sum,id1,id2;
	string name[10];
	while(cin>>n,n!=-1)
	{
		max=0;
		min=100000000;
		for(i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			cin>>name[i];
			sum=a*b*c;
			if(sum>max)
			{
				max=sum;
				id1=i;
			}
			if(sum<min)
			{
				min=sum;
				id2=i;
			}
		}
		cout<<name[id1]<<" took clay from "<<name[id2]<<"."<<endl;
	}
	return 0;
}



