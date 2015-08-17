#include <iostream>
using namespace std;
int main()
{
	char str[1000],c;
	int i,j,k,cnt,temp;
	
	while(cin.get(c))
	{
		i=0;
		while(c!='\n')
		{
			str[i]=c;
			i++;
			c=cin.get();
		}

		cnt=1;
		for(j=1;j<i;j++)
		{
			if(str[j]==str[j-1])
				cnt++;
			else
			{
				temp=64;
				cout<<char(str[j-1]);
				for(k=1;k<8;k++)
				{
					cout<<cnt/temp;
					cnt=cnt%temp;
					temp/=2;	
				}
				cnt=1;
			}
		}

		temp=64;
		cout<<char(str[i-1]);
		for(k=1;k<8;k++)
		{
			cout<<cnt/temp;
			cnt=cnt%temp;
			temp/=2;
		}
		cout<<endl;
	}
	return 0;
}

				


