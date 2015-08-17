#include <iostream>
using namespace std;
int main()
{
	double vl;
	int n,ct;
	while(cin>>n)
	{
		ct=-1;
		vl=10;
		cout<<"2^-"<<n<<" = ";
		while(n--)
		{
			vl/=2;
			if(vl<10)
			{
				vl*=10;
				ct++;
			}
		}
		if(vl>10)
		{
			vl/=10;
			ct++;
		}
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<vl<<"E-"<<ct<<endl;
	}
	return 0;
}