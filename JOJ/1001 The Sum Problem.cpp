#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double i,sum=0;
	while(cin>>i){
		sum=sum+i;
	}
	cout.precision(15);
	cout<<sum<<endl;
	return 0;     
}
