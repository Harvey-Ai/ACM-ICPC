#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	char num1[200],num2[200];
	int rel[200];
	int i,n,carry;
	cin>>n;
	while(n--)
	{
		memset(num1,'\0',sizeof(num1));
		memset(num2,'\0',sizeof(num2));
		cin>>num1>>num2;
		i=0;carry=0;
		while(num1[i]!='\0'&&num2[i]!='\0')
		{
			rel[i]=(carry+num1[i]+num2[i]-'0'-'0')%10;
			carry=(carry+num1[i]+num2[i]-'0'-'0')/10;
			i++;
		}
		while(num1[i]!='\0')
		{
			rel[i]=(carry+num1[i]-'0')%10;
			carry=(carry+num1[i]-'0')/10;
			i++;
		}
		while(num2[i]!='\0')
		{
			rel[i]=(carry+num1[i]-'0')%10;
			carry=(carry+num1[i]-'0')/10;
			i++;
		}
		if(carry)
		{
			rel[i]=carry;
			i++;
		}
		rel[i]=-1;
		i=0;
		while(rel[i]==0)
			i++;
		while(rel[i]!=-1)
		{
			cout<<rel[i];
			i++;
		}
		cout<<endl;
	}
	return 0;
}
