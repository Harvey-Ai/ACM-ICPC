#include <iostream>
using namespace std;
int main()
{
	int map[16][3];
	int i,x,y,z,t,dis,temp;
	for(i=0;i<16;i++)
		cin>>map[i][0]>>map[i][1]>>map[i][2];
	while(cin>>x>>y>>z,(x+1)&&(y+1)&&(z+1))
	{
		dis=1000000000;
		for(i=0;i<16;i++)
		{
			temp=(x-map[i][0])*(x-map[i][0])+(y-map[i][1])*(y-map[i][1])+(z-map[i][2])*(z-map[i][2]);
			if(temp<dis)
			{
				dis=temp;
				t=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,map[t][0],map[t][1],map[t][2]);
	}
	return 0;
}

			

