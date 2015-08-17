#include <iostream>
using namespace std;
int main()
{
	double vl;
	int n,ct;
	while(cin>>n)
	{
		ct=0;
		vl=1;
		cout<<"2^-"<<n<<" = ";
		while(n--)
		{
			vl/=2;
			if(vl<1e20)
			{
				vl*=1e20;
				ct+=20;
			}
		}
		while(vl>10)
		{
			vl/=10;
			ct--;
		}
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<vl<<"e-"<<ct<<endl;
	}
	return 0;
}