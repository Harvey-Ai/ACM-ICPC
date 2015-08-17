#include <iostream>
using namespace std;
int main()
{
	int i,j,k,l;
	long arr[201];
	for(i=1;i<201;i++)
		arr[i]=i*i*i;
	for(i=2;i<201;i++)
		for(j=2;j<i;j++)
			for(k=j;k<i;k++)
				for(l=k;l<i;l++)
					if(arr[i]==(arr[j]+arr[k]+arr[l]))
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
	return 0;
}