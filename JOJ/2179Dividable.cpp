//n^k=(n-1+1)^k,Ȼ�����չ��
#include <iostream>
using namespace std;
int main()
{
	int k,n;
	while(cin>>n>>k)
	{
		if(k%(n-1))
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}