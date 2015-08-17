/*
#include <iostream>
using namespace std;
int main()
{
	int d,p,i;
	int l[350],c[350];
	int search(int l[350],int c[350],int m,int n,int sum);
	while(cin>>d)
	{
		cin>>p;
		i=0;
		while(i<p)
		{
			cin>>l[i]>>c[i];
			i++;
		}
		cout<<search(l,c,d,p,0)<<endl;
	}
	return 0;
}


int search(int l[350],int c[350],int m,int n,int sum)
{
	int temp,i,t=0,min=1000000000,max=0;
	for(i=0;i<n;i++)
	{
		if(l[i]!=0)
		{
			sum+=l[i];
			temp=l[i];
			l[i]=0;
		}
		else
			continue;
		if(sum>m)
		{
			sum-=temp;
			l[i]=temp;
			continue;
		}
		else
		{
			if(sum==m)
			{
				int j;
				for(j=0;j<n;j++)
					if(l[j]==0&&min>c[j])
						min=c[j];
			}
			else
				t=search(l,c,m,n,sum);
			if(t>max&&t!=1000000000)
				max=t;
			if(min>max&&min!=1000000000)
				max=min;
		}
		sum-=temp;
		min=1000000000;
	}
	return max;
}
*/
#include <iostream>
using namespace std;
long f[2][200001];
int main()
{
	long i,j,d,p,a,b;
	long dit[400][2];
	while(cin>>d>>p)
	{
		for(j=0;j<200001;j++)
		{
			f[0][j]=f[1][j]=0;
		}
		i=0;
		while(p--)
		{
			cin>>dit[i][0]>>dit[i][1];
			i++;
		}
		if(dit[0][0]<=d)
			f[0][dit[0][0]]=dit[0][1];
		p=i;
		for(i=1;i<p;i++)
		{
			if(dit[i][0]<=d)
				f[1][dit[i][0]]=dit[i][1];
			for(j=0;j<=d;j++)
			{
				if(j>=dit[i][0])
				{
					if(f[1][dit[i][0]]>f[0][j-dit[i][0]])
						b=f[0][j-dit[i][0]];
					else
						b=f[1][dit[i][0]];
					if(f[0][j]>b)
						a=f[0][j];
					else
						a=b;
					if(f[1][j]<a)
						f[1][j]=a;
				}
				else
				{
					if(f[1][j]<f[0][j])
						f[1][j]=f[0][j];
				}
			}
			for(j=0;j<=d;j++)
			{
				f[0][j]=f[1][j];
				f[1][j]=0;
			}
		}
		cout<<f[0][d]<<endl;
	}
	return 0;
}
			



