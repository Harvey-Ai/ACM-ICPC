#include <iostream>
using namespace std;
int main()
{
	int n1,n2,temp1,temp2,carry,sum;
	while(cin>>n1>>n2,n1||n2)
	{
		sum=0;carry=0;
		while(n1&&n2)
		{
			temp1=n1%10;
			temp2=n2%10;
			if((temp1+temp2+carry)>9)
			{
				carry=1;
				sum++;
			}
			else
				carry=0;
			n1/=10;n2/=10;
		}
		while(n1)
		{
			temp1=n1%10;
			if((temp1+carry)>9)
			{
				carry=1;
				sum++;
			}
			else
			{
				carry=0;
				break;

			}
			n1/=10;
		}
		while(n2)
		{
			temp2=n2%10;
			if((temp2+carry)>9)
			{
				carry=1;
				sum++;
			}
			else
			{
				carry=0;
				break;

			}
			n2/=10;
		}
		if(sum)
			if(sum!=1)
				cout<<sum<<" carry operations."<<endl;
			else
				cout<<"1 carry operation."<<endl;
		else
			cout<<"No carry operation."<<endl;
	}
	return 0;
}

		

