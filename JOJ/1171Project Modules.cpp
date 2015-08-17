#include <iostream>
#include <string>
using namespace std;
int main()
{
	char dig1[2000],dig2[2000],dig[2000];
	int n,m,i,j,k,carry;
	while(cin>>dig1>>dig2)
	{
		n=strlen(dig1)-1;
		m=strlen(dig2)-1;
		carry=0;
		for(i=n,j=m,k=0;i>=0&&j>=0;i--,j--,k++)
		{
			dig[k]=(dig1[i]+dig2[j]+carry-'0'-'0')%10+'0';
			carry=(dig1[i]+dig2[j]+carry-'0'-'0')/10;
		}
		while(i>=0)
		{
			dig[k]=(dig1[i]+carry-'0')%10+'0';
			carry=(dig1[i]+carry-'0')/10;
			k++;
			i--;
		}
		while(j>=0)
		{
			dig[k]=(dig2[j]+carry-'0')%10+'0';
			carry=(dig2[j]+carry-'0')/10;
			k++;
			j--;
		}
		if(carry)
		{
			dig[k]=carry+'0';
			k++;
		}
		for(i=k-1;i>=0;i--)
			cout<<dig[i];
		cout<<endl;
	}
	return 0;
}

		
