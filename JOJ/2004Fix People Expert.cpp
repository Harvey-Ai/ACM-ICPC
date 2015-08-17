#include <iostream>
using namespace std;
int main()
{
	int block,ncase,i,j,k,s,count;
	int arr[5][10],cnt[5][10];
	cin>>ncase;
	while(ncase--)
	{
		count=0;
		for(i=0;i<5;i++)
			for(j=0;j<10;j++)
				cnt[i][j]=0;
		cin>>block;
		s=block;
		while(block--)
		{
			for(i=0;i<5;i++)
				for(j=0;j<10;j++)
					cin>>arr[i][j];
			cin>>k;
			for(i=0;i<5;i++)
				for(j=0;j<10;j++)
					if(arr[i][j]==k)
						cnt[i][j]++;
		}
		for(i=0;i<5;i++)
			for(j=0;j<10;j++)
				if(cnt[i][j]==s)
					count++;
		cout<<"count="<<count<<endl;
	}
	return 0;
}

