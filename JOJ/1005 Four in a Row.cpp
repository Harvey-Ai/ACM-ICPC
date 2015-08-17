#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(!n)
			break;
		if(int((n/4.0)*10)%10==5)
			cout<<n<<" is the sum of four consecutive integers."<<endl;
		else
			cout<<n<<" is not the sum of four consecutive integers."<<endl;
	}
	return 0;
}