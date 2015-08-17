/*
#include <iostream>
using namespace std;
int main()
{
	int f(int a,int b);
	int n,i,k,temp,first,cnt,l;
	int m[30008];
	bool flag;

	while(cin>>n)
	{
		cnt=1;flag=1;
		if(n==0)
		{
		   cout<<1<<endl;
		   continue;
		 }

		for(i=1;i<=n;i++)
			cin>>m[i];
	
		i=1;first=1;
		
		while(flag)
		{
			flag=0;k=1;
			while(m[i]!=first)
			{
				k++;
				temp=m[i];
				m[i]=0;
				i=temp;
			}
			m[i]=0;
			l=f(cnt,k);
			cnt=(cnt*k)/l;

			for(i=1;i<=n;i++)
				if(m[i]!=0)
				{
					first=i;
					flag=1;
					break;
				}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

int f(int a,int b)
{
	if(a%b)
		f(b,a%b);
	else
		return b;
}

#include <iostream>
#include <algorithm>
using namespace std;
int ar[30008];
bool f[30008];
int gcd(int x, int y){
	int t;
	while(y>0){
		t= x%y;
		x=y;
		y=t;
	}
	return x;
}
int main(){
	int i,j,n,s,k;
	while(cin>>n){
		for(i=0;i<n;++i){
			cin >> ar[i];
			ar[i]--;
			f[i]=true;
		}
		s=1;
		while(true){
			k=find(f,f+n,true)-f;
			if(k==n) break;
			j=0; i=k;
			while(true){
				f[i]=false;
				++j;
				i=ar[i];
				if(i==k) break;
			}
			k=gcd(s,j);
			s=s*j/k;
		}
		cout << s << endl;
	}
	return 0;
}	
*/	


#include <iostream>
using namespace std;
int main()
{
	int f(int a,int b);
	int a,b;
	while(cin>>a>>b)
		cout<<f(a,b)<<endl;
	return 0;
}
int f(int a,int b)
{
	if(a%b)
		f(b,a%b);
	else
		return b;
}
