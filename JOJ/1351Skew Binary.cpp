#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char a[500],c;
	long int n;
	int i,j,sub;
	while(cin>>c,c!='0')
	{
		a[1]=c;i=1;sub=0;n=0;
		while(a[++i]=cin.get(),a[i]!='\n'){};

		for(j=1;j<=i-1;j++)
		{
			sub+=a[j]-'0';
			n+=a[j]-'0';
			n*=2;
		}
		cout<<setiosflags(ios::fixed);
		cout<<n-sub<<endl;
	}
	return 0;
}



		



