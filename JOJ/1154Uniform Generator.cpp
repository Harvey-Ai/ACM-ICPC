#include <iostream>
using namespace std;
int main()
{
	int n,m,temp;
	while(cin>>n>>m)
	{
		cout.width(10);
		cout<<n;
		cout.width(10);
		cout<<m;
		if(m==0)
		{
			cout<<"    Good Choice"<<endl;
			continue;
		}
		while(n%m)
		{
			temp=n;
			n=m;
			m=temp%m;
		}
		if(m==1)
			cout<<"    Good Choice"<<endl;
		else
			cout<<"    Bad Choice"<<endl;
		cout<<endl;
	}
	return 0;
}




