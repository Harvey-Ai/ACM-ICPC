#include <iostream>
using namespace std;
int main()
{
	char num[1000];
	int i,j,k,carry,temp,n;
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		num[0]='1';k=0;
		for(i=1;i<=n;i++)
		{
			carry=0;
			for(j=0;j<=k;j++)
			{
				temp=carry+(num[j]-'0')*2;
				num[j]=temp%10+'0';
				carry=temp/10;
			}
			while(carry)
			{
				num[++k]=carry%10+'0';
				carry=carry/10;
			}
		}
		for(i=0;i<=k;i++)
		{
			if(num[i]!='0')
			{
				num[i]-=1;
				break;
			}
			else
				num[i]='9';
		}
		if(num[k]!='0')
			cout<<num[k];
		for(i=k-1;i>=0;i--)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}