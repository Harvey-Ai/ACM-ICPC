#include <iostream>
using namespace std;
int main()
{
	int p1,p2,p,l=1;
	while(cin>>p1>>p2,p1&&p2)
	{
		p=p2-p1;
		cout<<"Hole #"<<l++<<endl;
		if(p2==1)
		{
			cout<<"Hole-in-one."<<endl<<endl;
			continue;
		}
		if(p<=-3)
		{
			cout<<"Double Eagle."<<endl<<endl;
			continue;
		}
		if(p>=2)
		{
			cout<<"Double Bogey."<<endl<<endl;
			continue;
		}
		switch(p)
		{
		case -2:{cout<<"Eagle."<<endl;break;}
		case -1:{cout<<"Birdie."<<endl;break;}
		case 0:{cout<<"Par."<<endl;break;}
		case 1:{cout<<"Bogey."<<endl;break;}
		}
		cout<<endl;
	}
	return 0;
}