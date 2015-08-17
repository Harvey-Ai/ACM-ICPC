#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i=0;
	int chang,kuan,in,cut;
	bool flag;
	while(cin>>n)
	{
		if(i)
			cout<<endl;
		else
			i=1;
		chang=n*2-2;

		if((n-1)*n<(n-0.5)*(n-0.5))
			flag=1;
		else
			flag=0;

		kuan=sqrt(n-1/4);
		kuan*=2;
		in=chang*kuan*2-kuan*kuan;
		cut=(kuan+2)*4;
		cout<<kuan<<endl;

		//if(flag)
			cut+=4;
	//else
		//	cut-=4;

		cout<<"In the case n = "<<n<<", "<<cut<<" cells contain segments of the circle."<<endl;
		cout<<"There are "<<in<<" cells completely contained in the circle."<<endl;
	}
	return 0;
}


