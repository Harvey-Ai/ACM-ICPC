#include <iostream>
using namespace std;
int main()
{
	char c;
	char str1[100],str2[100];
	int i,n;
	bool flag;

	c=cin.get();i=0;
	while(c!='\n')
	{
		str1[i]=c;
		c=cin.get();
		i++;
	}
	str1[i]='\0';
	c=cin.get();i=0;
	while(c!='\n')
	{
		str2[i]=c;
		c=cin.get();
		i++;
	}
	str2[i]='\0';
	n=i;
	cout<<str2<<endl<<str1<<endl;
	while(cin.get(c))
	{
		flag=0;
		for(i=0;i<n;i++)
			if(c==str1[i])
			{
				cout<<str2[i];
				flag=1;
			}
		if(flag==0)
			cout<<c;
	}
	return 0;
}

