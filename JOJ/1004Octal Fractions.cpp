#include <iostream>
using namespace std;
int main()
{
	char n[1000],result[1000],l[1000],m1[1000],m2[1000],c;
	double temp;
	int i,j,t,ct,k,w;
	while(cin>>c)
	{
		i=1;ct=3;
		cin>>c;cin>>c;
		while(c!='\n')
		{
			n[i++]=c;
			c=cin.get();
		}
		cout<<"0.";
		for(j=1;j<=i-1;j++)
			cout<<n[j];
		cout<<" [8] = ";
		
		for(j=0;j<=999;j++){result[j]='0';l[j]='0';m1[j]='0';m2[j]='0';}
		l[1]='1';l[2]='2';l[3]='5';
		
		for(j=1;j<=i-1;j++)
		{
			for(k=0;k<=999;k++)
				m1[k]=m2[k]='0';

			for(k=1;k<=ct;k++)
			{
				m1[k]+=((l[k]-'0')*(n[j]-'0'))%10;
				m1[k-1]+=(l[k]-'0')*(n[j]-'0')/10;
				for(w=k-1;w>=1;w--)
				{
					if(m1[w]>'9')
					{
						m1[w]-=10;
						m1[w-1]++;
					}
					else
						break;
				}
			}

			for(k=ct;k>=1;k--)
			{
				result[k]+=m1[k]-'0';
				if(result[k]>'9')
				{
					result[k-1]++;
					result[k]-=10;
				}
			}

			for(k=1;k<=ct;k++)
			{
				temp=(l[k]-'0')/8.0;
				t=1+k;
				while(temp!=0)
				{
					temp*=10;
					m2[t++]+=int(temp);
					temp-=int(temp);
					for(w=t-1;w>=1;w--)
					{
						if(m2[w]>'9')
						{
							m2[w]-=10;
							m2[w-1]++;
						}
						else
							break;
					}
				}
			}
			ct=t-1;
			for(k=0;k<=ct;k++)
				l[k]=m2[k];
		}
		while(result[ct]=='0')
			ct--;
		cout<<"0.";
		for(j=1;j<=ct;j++)
			cout<<result[j];
		cout<<" [10]"<<endl;
	}
	return 0;
}



