#include <iostream>
using namespace std;
int main()
{
	int rank[26],i,k,max;
	bool flag=1,flag1=0;
	char a,b;
	for(i=0;i<=25;i++)
		rank[i]=0;
	while(cin>>a>>b)
	{
		rank[a-'A']+=2;
		rank[b-'A']++;
	}
	while(flag)
	{
		max=rank[0];
		k=0;
		for(i=0;i<=25;i++)
			if(rank[i]>max)
			{
				k=i;
				max=rank[i];
			}
		if(max>0)
		{
			if(flag1)
				cout<<" ";
			else
				flag1=1;
			cout<<char(k+'A');
			rank[k]=0;
		}
		else
		{
			cout<<endl; 
			break;
		}
	}
	return 0;
}
