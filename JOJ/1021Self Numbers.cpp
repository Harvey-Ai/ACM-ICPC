#include <iostream>
using namespace std; 
int main()
{	
	int x,sum,k,temp;	
	bool f[1000100]; 
	for(k=1;k<=1000099;k++)
		f[k]=1;
	for(k=1;k<=1000000;k++)	
	{				
		sum=k;		
		temp=k;		
		while(temp)			
		{				
			x=temp%10;				
			temp/=10;				
			sum+=x;
		}		
		f[sum]=0;
	}
	for(k=1;k<=1000000;k++)		
		if(f[k])			
			cout<<k<<endl;	
	return 0;
}