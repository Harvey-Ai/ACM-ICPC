#include <iostream>
using namespace std;
int main()
{
	char str[100];
	char c;
	int i,j,k,n;
	bool flag;
	while(cin.get(c))
	{
		i=0;
		while(c!='\n')
		{
			str[i]=c;
			i++;
			c=cin.get();
		}
		n=i;
		for(j=1;j<=n;j++)
		{
			i=j;
			if(n%j)
				continue;
			else
			{
				flag=1;
				while(i<=n-1)
				{
					for(k=0;k<j;k++)
						if(str[i+k]!=str[i-j+k])
						{
							flag=0;
							break;
						}
					if(flag==0)
						break;
					i+=j;
				}
			}
			if(flag)
			{
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
					



