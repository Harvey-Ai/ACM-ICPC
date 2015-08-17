#include <iostream>
using namespace std;
int main()
{
	int n,m,temp,cnt;
	while(cin>>n>>m,m||n)
	{
		if(n<m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		cnt=m*m*n-((m+n)*m*(m-1))/2+((m-1)*m*(2*m-1))/6;
		cout<<cnt<<endl;
	}
	return 0;
}
