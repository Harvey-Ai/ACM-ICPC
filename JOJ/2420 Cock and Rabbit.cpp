#include <iostream>
#include <string>
using namespace std;
int main()
{
	long a,b,x,y,h,l,i,temp;
	int arr1[5],arr2[6];
	string str1="first",str2="second";
	while(cin>>x>>y>>h>>l)
	{
		if(y>x)
		{
			b=(l-x*h)/(y-x);
			a=h-b;
			temp=(l-x*h)%(y-x);
		}
		else
		{
			a=(l-y*h)/(x-y);
			b=h-a;
			temp=(l-y*h)%(x-y);
		}

		if(temp||a<0||b<0)
		{
			cout<<"HaHaHa,such a facetiosity story,that is impossible!!!"<<endl;
			continue;
		}
		temp=a;
		for(i=1;i<=5;i++)
		{
			arr1[5-i]=temp%2;
			temp/=2;
		}
		temp=b;
		for(i=1;i<=6;i++)
		{
			arr2[6-i]=temp%2;
			temp/=2;
		}
		for(i=0;i<=4;i++)
			if(arr1[i])
				cout<<char(str1[i]-32);
			else
				cout<<char(str1[i]);
		cout<<":"<<a<<endl;
		for(i=0;i<=5;i++)
			if(arr2[i])
				cout<<char(str2[i]-32);
			else
				cout<<char(str2[i]);
		cout<<":"<<b<<endl;
	}
	return 0;
}
