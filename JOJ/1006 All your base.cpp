#include<iostream>
using namespace std;
int main(){
	int base,num1,num2;
	void convert(int,int);
	while(cin>>base>>num1>>num2&&base!=0){
		convert(base,num1);
		cout<<" + ";
		convert(base,num2);
		cout<<" = ";
		convert(base,(num1+num2));
		cout<<endl;
	}
	return 0;     
}


void convert(int base,int n){
	int arr[20];
	int i;
	for(i=0;n!=0;i++)
		{
			arr[i]=n%base;
			n=n/base;
		}
	for(int j=i-1;j>=0;j--)
		cout<<arr[j];
}