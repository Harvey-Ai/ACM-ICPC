#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str[501],s,t;
	int i=0,j;
	while(cin>>str[i])
		i++;
	sort(&str[0],&str[i]);
	cout<<str[0]<<endl;
	for(j=1;j<i;j++)
		if(str[j]!=str[j-1])
			cout<<str[j]<<endl;
	return 0;
}


	