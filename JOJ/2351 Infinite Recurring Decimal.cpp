#include <iostream>
using namespace std;
int main()
{
	long yu[1000],shang[1000];
	long long a,b;
	int i,j,k;
	bool flag;

	while(cin>>a)
	{
		cin.get();
		cin>>b;
		i=0;flag=1;
		while(1)
		{
			yu[i]=a;
			a*=10;
			shang[i]=a/b;
			a=a-shang[i]*b;
			if(a==0)
			{
				flag=0;
				break;
			}
			for(j=0;j<=i;j++)
				if(a==yu[j])
					break;
			if(j!=i+1)
				break;
			else
				i++;
		}

		if(flag)
		{
			cout<<"0.";
			for(k=0;k<j;k++)
				cout<<shang[k];
			cout<<"(";
			for(k=j;k<=i;k++)
				cout<<shang[k];
			cout<<")";
		}
		else
		{
			cout<<"0.";
			for(k=0;k<=i;k++)
				cout<<shang[k];
		}
		cout<<endl;
	}
	return 0;
}

			






