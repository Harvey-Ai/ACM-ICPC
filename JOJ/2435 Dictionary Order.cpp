#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str[1003],temp;
	int i,j,k,l,p1,p2,p3,p4,s,t,n;
	char c1,c2;
	bool flag,f=0;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			cin>>str[i];
		if(f)
			cout<<endl;
		else
			f=1;
		flag=1;
		while(flag)
		{
			flag=0;
			for(i=1;i<n;i++)
			{
				if(str[i].length()<str[i-1].length())
				{
					flag=1;
					str[i].swap(str[i-1]);
				}
			}
		}
		i=0;
		while(i<n)
		{
			j=i;
			while(str[i].length()==str[j].length()&&j<n)
				j++;
			sort(&str[i],&str[j]);
			flag=1;
			while(flag)
			{
				flag=0;
				for(k=i+1;k<j;k++)
				{
					for(l=0;l<26;l++)
					{
						c1=l+'a';c2=l+'A';
						p1=str[k-1].find(c1);
						p2=str[k-1].find(c2);
						if(p1==string::npos)
							p1=100;
						if(p2==string::npos)
							p2=100;
						if(p1<p2)
							s=p1;
						else
							s=p2;
						p3=str[k].find(c1);
						p4=str[k].find(c2);
						if(p3==string::npos)
							p3=100;
						if(p4==string::npos)
							p4=100;
						if(p3<p4)
							t=p3;
						else
							t=p4;
						
						if(s>t)
						{
							flag=1;
							temp=str[k-1];
							str[k-1]=str[k];
							str[k]=temp;
							break;
						}
						else
						{
							if(s<t)
								break;
						}
					}
				}
			}
			i=j;
		}
		for(i=0;i<n;i++)
			cout<<str[i]<<endl;
	}
	return 0;
}
