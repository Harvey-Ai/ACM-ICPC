#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int list[100],n=0,i;
	char arr1[100][50],arr2[100][50];
	char g;
	while((cin>>list[n],(g=cin.get())!='\n'))
		n++;
	for(i=0;i<=n;i++)
		cin>>arr1[i];
	for(i=0;i<=n;i++)
		strcpy(arr2[list[i]-1],arr1[i]);
	for(i=0;i<=n;i++)
		cout<<arr2[i]<<endl;
	return 0;
}
