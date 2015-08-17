#include <iostream>
using namespace std;
int main()
{
	bool flag;
	int i;
	double sum,len;
	while((cin>>len,len!=0.00))
	{
		i=2;
		sum=0;
		flag=1;
		while(flag)
		{
			sum+=double(1)/i;
			if(sum>=len)
				flag=0;
			i++;
		}
		cout<<i-2<<" card(s)"<<endl;
	}
	return 0;
}