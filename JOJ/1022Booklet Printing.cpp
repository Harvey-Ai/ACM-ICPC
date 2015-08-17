#include <iostream>
using namespace std;
int main()
{
	int i,n,sheet;
	int f1,f2,b1,b2;
	while(cin>>n,n)
	{
		sheet=n/4;
		if(n%4)
			sheet++;
		cout<<"Printing order for "<<n<<" pages:"<<endl;
		switch(n%4)
		{
		case 0:{cout<<"Sheet 1, front: "<<n<<", 1"<<endl;cout<<"Sheet 1, back : 2, "<<n-1<<endl;f1=n-2;f2=3;b1=4;b2=n-3;break;}
		case 1:
		{
			cout<<"Sheet 1, front: Blank, 1"<<endl;
			if(n>4)
				cout<<"Sheet 1, back : 2, Blank"<<endl;
			f1=n+1;f2=3;b1=4;b2=n;
			break;
		}
		case 2:{cout<<"Sheet 1, front: Blank, 1"<<endl;cout<<"Sheet 1, back : 2, Blank"<<endl;f1=n;f2=3;b1=4;b2=n-1;break;}
		case 3:{cout<<"Sheet 1, front: Blank, 1"<<endl;cout<<"Sheet 1, back : 2, "<<n<<endl;f1=n-1;f2=3;b1=4;b2=n-2;break;}
		}
		if(f1>n&&n>4)
		{
			cout<<"Sheet 2, front: Blank, 3"<<endl; 
			cout<<"Sheet 2, back : 4, "<<n<<endl;
			f1=n-1;f2=5;b1=6;b2=n-2;
			i=3;
		}
		else
			i=2;
		while(i<=sheet)
		{
			cout<<"Sheet "<<i<<", front: "<<f1<<", "<<f2<<endl; 
			cout<<"Sheet "<<i<<", back : "<<b1<<", "<<b2<<endl;
			i++;
			f1-=2;b1+=2;
			f2+=2;b2-=2;
		}
	}
	return 0;
}


