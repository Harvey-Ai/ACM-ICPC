//回朔，不对。1 0 7 0 4 0测试应该是Can be divided.
#include <iostream>
using namespace std;
int main()
{
	bool search(int m[6],int s,int sum);
	int l,sum,i,m[6];
	bool flag;
	l=1;
	while(1)
	{
		if(l!=1)
			cout<<endl;
		sum=0;flag=0;
		for(i=0;i<6;i++)
		{
			cin>>m[i];
			if(m[i]%6)
			{
				flag=1;
				m[i]=m[i]%6;
				sum+=(i+1)*m[i];
				
			}
			else
			{
				if(m[i])
					m[i]=6;
				else
					m[i]=0;
			}
		}
		if(flag==0)
			break;
		cout<<"Collection #"<<l++<<":"<<endl;
		if(sum%2)
		{
			cout<<"Can't be divided."<<endl;
			continue;
		}
		flag=search(m,0,sum/2);
		if(flag)
			cout<<"Can be divided."<<endl;
		else
			cout<<"Can't be divided."<<endl;
	}
	return 0;
}



bool search(int m[6],int s,int sum)
{
	int i;
	bool t=0,flag=0;
	for(i=0;i<6;i++)
	{
		if(m[i]!=0)
		{
			s+=i+1;
			m[i]--;
			if(s==sum)
			{
				flag=true;
				break;
			}
			else
				t=search(m,s,sum);
			if(t==true)
				break;
			m[i]++;
			s-=i+1;
		}
	}
	if(t==true)
		return true;
	if(flag==true)
		return true;
	return false;
}