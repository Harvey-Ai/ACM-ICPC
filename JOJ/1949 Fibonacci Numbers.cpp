#include <iostream>
using namespace std;
int main()
{
	char tp1[1000],tp2[1000],temp[1000];
	int n,i,k,carry;
	while(cin>>n)
	{
		for(i=0;i<=1000;i++)
		{
			tp1[i]='0';
			tp2[i]='0';
		}
		tp1[0]='1';
		tp2[0]='1';
		if(n==1||n==2)
			cout<<"1"<<endl;
		else
		{
			n=n-2;
			k=0;
			while(n--)
			{
				carry=0;
				for(i=0;i<=k;i++)
				{
					temp[i]=tp1[i];
					tp1[i]=tp1[i]+tp2[i]-'0'+carry;
					if(tp1[i]>'9')
					{
						tp1[i]=(tp1[i]-'0')%10+'0';
						carry=1;
					}
					else
						carry=0;
					tp2[i]=temp[i];
				}
				if(carry)
				{
					k++;
					tp1[k]='1';
				}
			}
			k++;
		while(k--)
			cout<<tp1[k];
		cout<<endl;
		}
	}
	return 0;
}