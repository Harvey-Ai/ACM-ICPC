#include <iostream>
using namespace std;
int main()
{
	int m,n,access_n,cut;
	while(cin>>n,n)
	{
		m=2;cut=1;
		access_n=n;
		while(access_n>=1)
		{
			if(cut!=0)//如CUT等于0，则表示删除的是最后一个；否则CUT--；
				cut--;
			access_n--;//余下的总数；
			if(access_n==0)
				break;
			cut=(cut+m)%access_n;
			if(cut==1)
			{
				access_n=n;
				m++;
				cut=1;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}





