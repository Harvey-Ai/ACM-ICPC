#include <iostream>
using namespace std;
int main()
{
	int degree,p,first,second,third;
	while(cin>>p>>first>>second>>third,p||first||second||third)
	{
		degree=1080;
		if(p<first)
			degree+=(40-first+p)*9;
		else
			degree+=(p-first)*9;
		if(second>first)
			degree+=(second-first)*9;
		else
			degree+=(second+40-first)*9;
		if(second<third)
			degree+=(second+40-third)*9;
		else
			degree+=(second-third)*9;
		cout<<degree<<endl;
	}
	return 0;
}
