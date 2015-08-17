
解一：
#include <iostream>
using namespace std;
int main()
{
	int m[2000],b[2000];
	int n,i,j,k;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
			cin>>m[i];
		b[1]=m[1];k=1;b[0]=1000000000;
		for(i=2;i<=n;i++)
		{
			if(m[i]<=b[k])
			{
				k++;
				b[k]=m[i];
			}
			else
			{
				for(j=k-1;j>=0;j--)
					if(m[i]<b[j])
					{
						b[j+1]=m[i];
					}
			}
		}
		cout<<k<<endl;
	}
	return 0;
}

解二：
#include <iostream>
using namespace std;
int main()
{
	int b[1001],a[1001];
	int n,i,j,k;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=1;
		}
		for(i=2;i<=n;i++)
			for(j=i-1;j>=1;j--)
				if((a[i]<=a[j])&&(b[j]>=b[i]))
					b[i]=b[j]+1;
		k=1;
		for(i=2;i<=n;i++)
			if(b[i]>b[k])
				k=i;
		cout<<b[k]<<endl;
	}
	return 0;
}

				


