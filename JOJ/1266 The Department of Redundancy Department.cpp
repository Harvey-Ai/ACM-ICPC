#include <iostream>
using namespace std;
int main()
{
	long n,i,pos=-1;
	long seqance[5000000][2];
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		for(i=0;i<=pos;i++)
			if(seqance[i][0]==n)
			{
				seqance[i][1]++;
				flag=1;
				break;
			}
		if(flag==0)
		{
			pos++;
			seqance[pos][0]=n;
			seqance[pos][1]=1;
		}
	}
	for(i=0;i<=pos;i++)
		cout<<seqance[i][0]<<" "<<seqance[i][1]<<endl;
	return 0;
}


