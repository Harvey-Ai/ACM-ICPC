#include <iostream>
#include <algorithm>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 


int main()
{
	int treal[10000],info[10000][2];
	int i,j,n,max;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&info[i][0],&info[i][1]);
		
		qsort(info,n,sizeof(info[0]),cmp); 

		for(i=0;i<n;i++)
			treal[i]=1;

		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				if(treal[i]<=treal[j]&&info[i][0]>info[j][1])
					treal[i]=treal[j]+1;

		max=0;
		for(i=0;i<n;i++)
			if(max<treal[i])
				max=treal[i];
		cout<<max<<endl;
	}
	return 0;
}









