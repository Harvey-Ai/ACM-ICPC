#include <iostream>
#include <string>
using namespace std;
int main()
{
	char s[1000];
	int i,j,n,max_i,max_j;
	char temp;
	while(cin>>s,strcmp(s,"#"))
	{
		n=strlen(s);
		max_i=0;
		for(i=1;i<n;i++)
			if(s[i]>s[i-1])
			{
				if(max_i<i)
					max_i=i;
			}
		if(max_i==0)
		{
			cout<<"No Successor"<<endl;
			continue;
		}
		max_j=0;
		for(i=0;i<n;i++)
			if(s[i]>s[max_i-1])
			{
				if(i>max_j)
					max_j=i;
			}
		temp=s[max_i-1];
		s[max_i-1]=s[max_j];
		s[max_j]=temp;
		i=max_i;j=n-1;
		while(j>i)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
			i++;j--;
		}
		cout<<s<<endl;
	}
	return 0;
}

