#include <iostream>
using namespace std;
int main()
{
	int N,n,i;
	bool flag;
	cin>>N;
	while(N--)
	{
		i=0;flag=0;
		cin>>n;
		while(n)
		{
			if(n%2)
			{
				if(flag)
					cout<<" ";
				else
					flag=1;
				cout<<i;
			}
			n/=2;
			i++;
		}
		cout<<endl;
	}
	return 0;
}
	
		
