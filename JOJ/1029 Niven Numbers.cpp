#include <iostream>
using namespace std;
int main()
{
	int n,dit,base,i,temp,k;
	long vl;
	char c[100];
	cin>>n;
	while(n--)
	{
		while(cin>>base,base)
		{
			i=0;
			vl=0;
			dit=0;
			temp=1;
			c[i]=cin.get();
			while((c[i]=cin.get(),c[i]!='\n'))
				i++;
			while(--i)
				temp*=base;
			while(temp)
			{
				dit+=c[i]-'0';
				vl+=temp*(c[i]-'0');
				i++;
				temp/=base;
			}
		if(vl%dit)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
		}
		if(n>0)
			cout<<endl;
	}
	return 0;
}