#include <iostream>
using namespace std;
int main()
{
	int z,i,j,m,l,k,n,cnt;
	int arr[10000];
	bool flag;
	n=1;
	while(cin>>z>>i>>m>>l,m)
	{
		k=0;flag=1;
		while(flag)
		{
			arr[k]=l;
			l=(z*l+i)%m;
			k++;
			for(j=0;j<k;j++)
			{
				if(l==arr[j])
				{
					cnt=k-j;
					flag=0;
					break;
				}
			}
		}
		cout<<"Case "<<n++<<": "<<cnt<<endl;
	}
	return 0;
}

