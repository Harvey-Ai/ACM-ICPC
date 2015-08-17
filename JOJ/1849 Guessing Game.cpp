#include <iostream>
using namespace std;
int main()
{
	bool flag;
	int max=11,min=0,fal,temp;
	char c;
	while((cin>>temp,temp))
	{
		flag=0;
		cin.get();
		c=cin.get();
		if(c!='r')
			while(c=cin.get())
			{
				if(c=='h')
				{
					if(temp<max)
						max=temp;
					break;
				}
				if(c=='l')
				{
					if(temp>min)
						min=temp;
					break;
				}
			}
		else
		{
			fal=temp;
			flag=1;
		}
		while((c=cin.get(),c!='\n'));
		if(flag)
		{
			if(fal>min&&fal<max)
				cout<<"Stan may be honest"<<endl;
			else
				cout<<"Stan is dishonest"<<endl;
			max=11;min=0;
		}
	}
	return 0;
}