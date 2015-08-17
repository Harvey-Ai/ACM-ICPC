#include <iostream>
using namespace std;
int main()
{
	bool flag=1,way;
	int i;
	char c;
	while(1)
	{
		for(i=1;i<=3;i++)
		{
			c=cin.get();
			if(i==1&&c=='D')
			{
				way=0;
				break;
			}
			if(c=='D'&&i==3)
			{
				flag=0;
				break;
			}
			if(c=='C'&&i==3)
			{
				way=1;
				break;
			}
		}
		if(flag)
		{
			while(i<=6)
			{
				c=cin.get();
				i++;
			}
			if(way){
				while((c=cin.get(),c!='\n'))
				{
					c+=3;
					if(c>'z'||(c>'Z'&&c<'a'))
						c-=26;
					cout<<c;
				}
				cout<<endl;
			}
			else{
				while((c=cin.get(),c!='\n'))
				{
					c-=3;
					if((c<'a'&&c>'Z')||c<'A')
						c+=26;
					cout<<c;
				}
				cout<<endl;
			}
		}
		else
			break;
	}
	return 0;
}