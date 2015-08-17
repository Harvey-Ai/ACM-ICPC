#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int carrots,rabbits,i;
	int need[1000];
	long sum;
	while(cin>>carrots>>rabbits)
	{
		sum=0;
		for(i=0;i<rabbits;i++)
		{
			cin>>need[i];
			sum+=need[i];
		}
		sort(&need[0],&need[i]);
		for(i=rabbits-1;i>=0;i--)
		{
			if(sum>carrots)
				sum-=need[i];
			else
				break;
		}
		cout<<rabbits-i-1<<endl;
	}
	return 0;
}

