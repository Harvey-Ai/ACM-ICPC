#include <iostream>
//#include <algorithm>
#include <string>
using namespace std;
int main()
{
	string str[10000],s;
	char c;
	int i,j,k,n1,n2;
	bool flag,f;
	while(scanf("%d",&n1),n1)
	{
		i=0;j=0;
		while(i<n1)
		{
			cin>>str[j];
			j++;
			c=cin.peek();
			while(c==' ')
			{
				cin.get();
				c=cin.peek();
			}
			if(c=='\n')
				i++;
		}
		n1=j;
		scanf("%d",&n2);
		i=0;j=0;f=1;
		while(i<n2)
		{
			cin>>s;
			j++;
			c=cin.peek();
			while(c==' ')
			{
				cin.get();
				c=cin.peek();
			}
			if(c=='\n')
				i++;
			flag=0;
			for(k=0;k<n1;k++)
				if(s==str[k])
				{
					flag=1;
					str[k][0]='\0';
					str[k][1]='\0';
					str[k][2]='\0';
					break;
				}
			if(flag==0)
				f=0;
		}
		if(f&&j==n1)
			printf("OK\n");
		else
			printf("WRONG\n");
	}
	return 0;
}
