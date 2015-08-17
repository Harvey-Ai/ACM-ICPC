/*
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k,N;
	char tree[10001][100];
	bool flag;
	while(cin>>n,n)
	{
		for(i=1;i<=n;i++)
			cin>>tree[i];
		cout<<'A'<<endl;
		k=1;N=n-1;
		while(N)
		{
			flag=0;
			for(i=1;i<=n;i++)
			{
				if(tree[i][k]=='L'&&tree[i][k+1]==0)
				{
					cout<<tree[i]<<endl;
					k++;N--;
					flag=1;
					break;
				}
				if(tree[i][k]=='R'&&tree[i][k+1]==0)
				{
					cout<<tree[i]<<endl;
					k++;N--;
					flag=1;
					break;
				}
			}
			if(flag==0)
				k--;
		}
	cout<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	string tree[10001];
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>tree[i];
		}

		sort(&tree[1], &tree[n+1]);
		
		for(i=1;i<=n;i++)
			cout<<tree[i]<<endl;
		cout<<endl;
	}
	return 0;
}
		

		





