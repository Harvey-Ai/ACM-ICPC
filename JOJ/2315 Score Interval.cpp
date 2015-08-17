#include <iostream>
using namespace std;
int main()
{
	int n,s,i;
	int m[5];
	while(cin>>n,n!=-1)
	{
		for(i=0;i<=4;i++)
			m[i]=0;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			if(s<60) m[0]++;
			else	if(s<70) m[1]++;
			else	if(s<80) m[2]++;
			else    if(s<90) m[3]++;
			else	m[4]++;
		}
		cout<<"0-59:"<<m[0]<<endl;
		cout<<"60-69:"<<m[1]<<endl;
		cout<<"70-79:"<<m[2]<<endl;
		cout<<"80-89:"<<m[3]<<endl;
		cout<<"90-100:"<<m[4]<<endl;
	}
	return 0;
}


