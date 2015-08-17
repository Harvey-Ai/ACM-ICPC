#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i,j,rel,temp;
	long sq[50][50];
	while(cin>>n)
	{
		memset(sq,0,sizeof(sq));
		for(i=0;i<=n-1;i++)
			cin>>sq[i][0];

		for(j=1;j<n;j++)
			for(i=n-j;i>=0;i--)
				sq[i][j]=(sq[i+1][j-1]-sq[i][j-1])/j;

		if(n!=0)
			rel=sq[0][0];

		temp=1;
		for(j=1;j<n;j++)
		{
			temp*=(n-j+1);
			rel+=sq[0][j]*temp;
		}
		cout<<rel<<endl;
	}
	return 0;
}

//用迭代方法可以求出解，但是不知道为什么牛顿插值不ok???
