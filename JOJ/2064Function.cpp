#include <iostream>
using namespace std;
int main()
{
	int tm[11],n[2000];
	int N,k,i,j;
	while(cin>>N)
	{
		for(i=1;i<=N;i++)
			cin>>tm[i];
		for(i=0;i<=N-1;i++)
			cin>>n[i];
		cin>>k;
		i=N-1;
		while(i++<k)
		{
			n[i]=0;
			for(j=1;j<=N;j++)
				n[i]+=n[i-j]*tm[j];
		}
		cout<<n[k]<<endl;
	}
	return 0;
}






