#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,i;
	double length;
	cout<<"# Cards  Overhang"<<endl;
	while(cin>>n)
	{
		length=0.0;
		for(i=1;i<=n;i++)
			length+=(double(1.0)/(i*2));
		cout<<setw(5)<<setiosflags(ios::right)<<n<<"     ";
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<length<<endl;
	}
	return 0;
}