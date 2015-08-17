/*
#include <iostream>
using namespace std;
int main()
{
	double n1,n2;
	while(cin>>n1>>n2)
	{
		cout.setf(ios::fixed);
		cout.precision(0);
		cout<<n1+n2<<endl;
		cout<<n1-n2<<endl;
		cout<<n1*n2<<endl;
		cout<<n1/n2<<endl;
	}
	return 0;
}
*/
#include <iostream>
using namespace std;
void add(char n1[],char n2[],char n[]);
int main()
{
	
	void minus(char n1[],char n2[]);
	void multiply(char n1[],char n2[]);
	void divide(char n1[],char n2[]);
	char n1[100],n2[100],n[100];
	char c;
	int i;
	while(cin.get(c))
	{
		n1[0]=c;i=0;
		while(c!=' ')
		{
			n1[i++]=c;
			c=cin.get();
		}
		n1[i]='\0';
		i=0,c=cin.get();
		while(c!='\n')
		{
			n2[i++]=c;
			c=cin.get();
		}
		n2[i]='\0';
		add(n1,n2,n);
		for(i=0;n[i]!='\0';i++);
		while(i--)
			cout<<n[i];
		cout<<endl;
		minus(n1,n2);
		multiply(n1,n2);
	//	divide(n1,n2);
	}
	return 0;
}

void add(char n1[],char n2[],char n[])
{
	int i,j,k,carry;
	i=0;j=0;k=0;carry=0;
	while(n1[i]!='\0')
		i++;
	while(n2[j]!='\0')
		j++;
	i--;j--;
	while(j>=0)
	{
		n[k]=(n1[i]+n2[j]-'0'-'0'+carry)%10+'0';
		carry=(n1[i]+n2[j]-'0'-'0'+carry)/10;
		k++;i--;j--;
	}
	while(i>=0)
	{
		n[k]=(n1[i]-'0'+carry)%10+'0';
		carry=(n1[i]-'0'+carry)/10;
		k++;i--;
	}
	n[k]='\0';
}


void minus(char n1[],char n2[])
{
	char n[100];
	int i,j,k,carry;
	i=0;j=0;k=0;carry=0;
	while(n1[i]!='\0')
		i++;
	while(n2[j]!='\0')
		j++;
	i--;j--;
	while(j>=0)
	{
		if(n1[i]-n2[j]-carry<0)
		{
			n[k]=n1[i]-n2[j]-carry+10+'0';
			carry=1;
		}
		else
		{
			n[k]=n1[i]-n2[j]-carry+'0';
			carry=0;
		}
		k++;i--;j--;
	}
	while(i>=0)
	{
		if(n1[i]-carry<0)
		{
			n[k]=n1[i]-carry+10;
			carry=1;
		}
		else
		{
			n[k]=n1[i]-carry;
			carry=0;
		}
		k++;i--;
	}
	k--;
	while(n[k]=='0')
		k--;
	k++;
	while(k--)
		cout<<n[k];
	cout<<endl;
}


void multiply(char n1[],char n2[])
{
	char n[100],temp[100];
	int i,j,k,t,l,carry;
	for(i=0;i<100;i++)
	{
		n1[i]='0';temp[i]='0';
	}
	n[0]='\0';
	i=0;j=0;carry=0;l=0;
	while(n1[i]!='\0')
		i++;
	while(n2[j]!='\0')
		j++;
	while(j--)
	{
		carry=0;t=i;
		for(k=0;k<l;k++)
			temp[k]='0';
		while(t--)
		{
			temp[k]=((n2[j]-'0')*(n1[t]-'0')+carry)%10+'0';
			carry=((n2[j]-'0')*(n1[t]-'0')+carry)/10;
			k++;
		}
		if(carry)
			temp[k++]=carry+'0';
		temp[k]='\0';
		add(temp,n,n);
	}
	if(n[k]!='\0')
		k++;
	k++;
	while(k--)
		cout<<n[k];
	cout<<endl;
}




