//好题，分析问题
#include <iostream>
using namespace std;
int main()
{
	double s[41];
	int i;
	s[0]=1;s[1]=2;s[2]=4;
	for(i=3;i<41;i++)
		s[i]=s[i-1]+s[i-2]+s[i-3];
	cout.setf(ios::fixed);
	cout.precision(0);
	while(cin>>i)
		cout<<s[i]<<endl;
	return 0;
}







