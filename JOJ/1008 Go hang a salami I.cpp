#include <iostream>
#include <string.h>
using namespace std;
int main(){
	bool check(char arr[]);
	int n;
	char arr[500];
	cin>>n;
	cin.get();
	for(int i=0;i<=n-1;i++){
		cin.getline(arr,500);
		if(check(arr))
			cout<<arr<<" is a palindrome."<<endl;
		else
			cout<<arr<<" is not a palindrome."<<endl;
		
	}
	return 0;
}



bool check(char arr[]){
	int up=strlen(arr)-1,low=0;
	while(up>low)
	{
		while(arr[up]<'A'||arr[up]>'z'||arr[up]>'Z'&&arr[up]<'a')
			up--;
		while(arr[low]<'A'||arr[low]>'z'||arr[low]>'Z'&&arr[low]<'a')
			low++;
		if(arr[up]!=arr[low]&&arr[up]!=arr[low]+32&&arr[up]+32!=arr[low])
			return 0;
		up--;low++;
	}
	return 1;
	
}