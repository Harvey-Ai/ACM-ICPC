#include <iostream>
using namespace std;
int main()
{
	int n,m,a,b,cnt,k,N;
	cin>>N;
	while(N--)
	{
		cnt=0;k=1;
		while(cin>>n>>m,n||m)
		{
			cnt=0;
			for(b=2;b<n;b++)
				for(a=1;a<b;a++)
					if((a*a+b*b+m)%(a*b)==0)
						cnt++;
			cout<<"Case "<<k++<<": "<<cnt<<endl;
		}
		if(N)
			cout<<endl;
	}
	return 0;
}

