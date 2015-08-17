#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,i,j,l,k,cnt,min,t1,t2,t[10];
	string s[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
	bool flag;
	cin>>n;
	l=1;
	while(n--)
	{
		flag=0;min=100;cnt=0;
		for(i=0;i<10;i++)
		{
			cin>>t[i];
			if(t[i]>=1&&t[i]<= 5)
				t[i]+=12;
		}
		for(j=0;j<=1;j++)
			for(i=0;i<10;i+=2)
			{
				cin>>t1>>t2;
				if(t1>=1&&t1<=5)
					t1+=12;
				if(t2>=1&&t2<=5)
					t2+=12;
				if(t1>t[i])
					t[i]=t1;
				if(t2<t[i+1])
					t[i+1]=t2;
			}
		for(i=0;i<10;i+=2)
			t[i]=t[i+1]-t[i];
		for(i=0;i<10;i+=2)
			if(t[i]>=3)
			{
				flag=1;
				break;
			}
		if(flag)
		{
			for(i=0;i<10;i+=2)
			if(t[i]>=1)
				for(j=0;j<10;j+=2)	
				if(t[j]>=2)
					for(k=0;k<10;k+=2)
					if(t[k]>=3)
					{
						cnt=0;
						if(i>=j)
							cnt+=5;
						if(j>=k)
							cnt+=5;
						cnt+=k;
						if(min>cnt)
						{
							min=cnt;
							t[1]=i;
							t[3]=j;
							t[5]=k;
							
						}
					}
			cout<<"Case "<<l++<<": "<<s[t[1]/2]<<" for 1 hour, then "<<s[t[3]/2]<<" for 2 hours, then "<<s[t[5]/2]<<" for 3 hours."<<endl;
		}
		else
			cout<<"Case "<<l++<<": The meetings cannot be scheduled."<<endl;
	}
	return 0;
}


								


		

