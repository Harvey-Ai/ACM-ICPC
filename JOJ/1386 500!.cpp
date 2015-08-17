#include <iostream>
using namespace std;
int main()
{
	int k[1200];int n,i,j,temp,carry;
	while(cin>>n)
	{
		k[0]=1;j=0;for(i=1;i<=1199;i++)k[i]=0;
		cout<<n<<"!"<<endl;

		while(n>=1)
		{
			carry=0;
			for(i=0;i<=j;i++)
			{
				temp=k[i]*n;
				k[i]=(carry+temp)%10;
				carry=(carry+temp)/10;
			}
			while(carry)
			{
				k[++j]=carry%10;
				carry/=10;
			}
			n--;
		}
		for(i=j;i>=1;i--)
		{
			cout<<k[i];
			if((j-i+1)%80==0)
			cout<<endl;
		}
		cout<<k[0];
		cout<<endl;
	}
	return 0;
}

//	
