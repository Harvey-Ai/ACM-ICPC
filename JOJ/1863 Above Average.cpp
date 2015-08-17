#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int N,n,i,k,sum;
	int m[1000];
	float average;
	cin>>N;
	while(N--)
	{
		cin>>n;sum=0;k=0;
		for(i=0;i<=n-1;i++)
		{
			cin>>m[i];
			sum+=m[i];
		}
		average=float(sum)/n;
		for(i=0;i<=n-1;i++)
			if(m[i]>average)
				k++;
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(3)<<float(k*100)/n<<"%"<<endl;
	}
	return 0;
}
