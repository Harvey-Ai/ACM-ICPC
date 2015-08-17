#include <iostream>
using namespace std;
int main()
{
	int s,i,max,t_max,clas;

	i=0;t_max=0;
	while((cin>>s,s!=-1))
	{
		max=s;i++;
		while((cin>>s,s!=0))
			if(s>max)
				max=s;
		cout<<max<<endl;
		if(t_max<max)
		{
			t_max=max;
			clas=i;
		}
	}
	cout<<t_max<<" At Class "<<clas<<endl;
	return 0;
}


			

