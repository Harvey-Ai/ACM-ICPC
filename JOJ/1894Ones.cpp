#include <iostream>
using namespace std;
int main()
{
	int n,dig,m;
	while(cin>>n)
	{
		m=dig=1;
		while(m)
		{
			m=(m*10+1)%n;
			dig++;
		}
		cout<<dig<<endl;
	}
	return 0;
}
