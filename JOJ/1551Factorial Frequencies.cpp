#include <iostream>
using namespace std;
int main()
{
	char m[1000];
	int n,i,j,top,carry,temp;
	int dig[10];
	while(cin>>n,n)
	{
		m[1]='1';carry=0;top=1;j=1;
		for(i=0;i<=9;i++)
			dig[i]=0;

		for(j=2;j<=n;j++)
		{
			for(i=1;i<=top;i++)
			{	
				temp=(m[i]-'0')*j+carry;
				m[i]=temp%10+'0';
				carry=temp/10;
			}
			while(carry)
			{
				m[++top]=carry%10+'0';
				carry/=10;
			}
		}
		for(i=1;i<=top;i++)
		{
			switch(m[i])
			{
			case '0': {dig[0]++;break;}
			case '1': {dig[1]++;break;}
			case '2': {dig[2]++;break;}
			case '3': {dig[3]++;break;}
			case '4': {dig[4]++;break;}
			case '5': {dig[5]++;break;}
			case '6': {dig[6]++;break;}
			case '7': {dig[7]++;break;}
			case '8': {dig[8]++;break;}
			case '9': {dig[9]++;break;}
			}
		}

		cout<<n<<"! --";
		for(i=0;i<=9;i++)
		{
			if(i==0||i==5)
			{
				cout<<endl;
				cout<<"   ";
			}
			else
				cout<<"    ";
			cout<<"("<<i<<")";
			cout.width(5);
			cout<<dig[i];
		}
		cout<<endl;
	}
	return 0;
}



			
		

