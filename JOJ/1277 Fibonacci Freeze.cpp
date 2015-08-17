#include <iostream>
using namespace std;
int main()
{
	int f1[300],f2[300],f[300];
	int i,k,n;
	while(cin>>n)
	{
		cout<<"The Fibonacci number for "<<n<<" is ";
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		k=0;n--;
		for(i=1;i<=299;i++)	{f[i]=f1[i]=f2[i]=0;}
		f1[0]=1;f2[0]=0;f[0]=1;
		while(n--)
		{
			for(i=0;i<=k;i++)
			{
				f[i]=(f1[i]+f2[i])%10;
				f2[i+1]+=(f1[i]+f2[i])/10;
			}
			if(f2[k+1]!=0)
			{
				k++;
				f[k]=f2[k];
			}
			for(i=0;i<=k;i++)
			{
				f2[i]=f1[i];
				f1[i]=f[i];
			}
		}
		for(i=k;i>=0;i--)   {cout<<f[i];}
		cout<<endl;
	}
	return 0;
}
		



