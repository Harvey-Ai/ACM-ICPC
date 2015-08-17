#include  <iostream>
#include <string>
using namespace std;
int main()
{
	string str,re1,re2;
	int n,pos,len,len1;
	while(cin>>str)
	{
		cin>>n;
		while(n--)
		{
			cin>>re1>>re2;
			len=str.length();
			len1=re1.length();
			pos=0;
			while(pos<str.length()-len1+1)
			{
				if(str.compare(pos,len1,re1)==0)
				{
					str.replace(pos,len1,re2);
					pos+=re2.length();
				}
				else
					pos++;
			}
		}
		cout<<str<<endl;
	}
	return 0;
}









