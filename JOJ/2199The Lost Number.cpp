//cin�Ķ���û��scanf����Ŀ죬���ݴ��ʱ�򣬶ԱȺ����ԡ�
#include <iostream>
#include <algorithm>
using namespace std;
int s[1000001];
int main()
{
	int n,i;
	while(cin>>n)
	{
		i=0;
		while(i++<n)
			scanf("%d",&s[i-1]);
		sort(&s[0],&s[n]);
		for(i=0;i<n-1;i++)
			if(s[i+1]!=s[i]+1)
			{
				cout<<s[i]+1<<endl;
				break;
			}
		//cout.setf(ios::fixed);
		//cout.precision(0);
	}
	return 0;
}
