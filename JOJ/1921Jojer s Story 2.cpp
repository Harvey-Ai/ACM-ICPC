#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int n,id1,id2,temp,scores;
	while(cin>>s)
	{
		scores=5;
		cin>>n;
		scores+=n*10;
		cin>>id2;
		n--;
		temp=0;
		while(n--)
		{
			cin>>id1;
			if(id1-id2==1)
			{
				if(temp<10)
					temp++;
			}
			else
				temp=0;
			scores+=temp;
			id2=id1;
		}
		cout<<scores<<endl;
	}
	return 0;
}

