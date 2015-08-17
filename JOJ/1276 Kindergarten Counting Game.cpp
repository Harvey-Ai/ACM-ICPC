#include <iostream>
using namespace std;
int main()
{
	int ct;
	char c1,c2;
	while((c1=cin.get())!=EOF)
	{
		ct=0;
		c2=c1;
		while((c1=cin.get(),c1!='\n'))
		{
			if(c1<'A'||c1>'z'||c1>'Z'&&c1<'a')
				if(c2>='A'&&c2<='Z'||c2<='z'&&c2>='a')
					ct++;
			c2=c1;
		}
		if(c2>='A'&&c2<='Z'||c2<='z'&&c2>='a')
			ct++;
		cout<<ct<<endl;
	}
	return 0;
}