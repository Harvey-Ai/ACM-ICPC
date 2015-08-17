
/*»ØË·£¬´íÎó°¡
#include <iostream>
#include <string>
using namespace std;
int main()
{
	long creat(char n[100],int m,int k);
	char n[100];
	int k,m;
	while(cin>>n)
	{
		m=strlen(n);
		cin>>k;
		if(k==0)
		   break;
		cout<<creat(n,m,k)<<endl;
	}
	return 0;
}



long creat(char n[100],int m,int k)
{
	int i,j;
	long min=100000000,number;
	char c;
	for(i=0;i<m;i++)
	{
		c=n[i];
		if(c!='\0')
			n[i]='\0';
		else
			continue;
		k--;
		if(k)
			number=creat(n,m,k);
		else
		{
			int temp=1;
			number=0;
			for(j=m-1;j>=0;j--)
				if(n[j]!='\0')
				{
					number+=(n[j]-'0')*temp;
					temp*=10;
				}
		}
		if(min>number)
			min=number;	
		n[i]=c;
		k++;
	}
	return min;
}
1564584651231273257628371931753197539173515318537135135153817891791831537123713
12
1112257628371931753197539173515318537135135153817891791831537123713

*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	char n[3000],number[3000];
	char c;
	int k,i,j,t,l,m;
	bool flag=1;
	while(cin>>n)
	{
		m=0;
		l=strlen(n);
		cin>>k;
		if(k==0)
			continue;
		i=0;
		t=0;
		c=n[0];
		while(i<=l-k-1)
		{
			for(j=t;j<=i+k;j++)
				if(n[j]<c)
				{
					c=n[j];
					t=j;
				}
			number[m++]=c;
			i++;t++;
			c=n[t];
		}
		number[m]='\0';
		i=-1;
		while(number[++i]=='0'){};
		while(number[i]!='\0')
		{
			cout<<number[i];
			i++;
		}
		cout<<endl;
	}
	return 0;
}





