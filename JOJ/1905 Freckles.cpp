#include <iostream>
using namespace std;
int main()
{
	int i,n,k1,k2,k3,k4;
	double pos1[100][2],pos2[100][2],pos3[100][2],pos4[100][2],x,y,rel;
	while(cin>>n)
	{
		k1=k2=k3=k4=0;
		for(i=0;i<n;i++)
		{
			cin>>x>>y;
			if(x>=0)
			{
				if(y>=0)
				{
					pos1[k1][0]=y;
					pos1[k1][1]=x;
					k1++;
				}
				else
				{
					pos4[k4][0]=x;
					pos4[k4][1]=y;
					k4++;
				}
			}
			else
			{
				if(y>=0)
				{
					pos2[k2][0]=x;
					pos2[k2][1]=y;
					k2++;
				}
				else
				{
					pos3[k3][0]=y;
					pos3[k3][1]=x;
					k3++;
				}
			}
		}
		sort(&pos1[0],&pos1[k1]);
		sort(&pos2[0],&pos2[k2]);
		sort(&pos3[0],&pos3[k3]);
		sort(&pos4[0],&pos4[k4]);
		rel=0;
		for(i=1;i<k1;i++)
			rel+=sqrt((pos1[i][0]-pos1[i-1][0])*(pos1[i][0]-pos1[i-1][0])+(pos1[i][1]-pos1[i-1][1])*(pos1[i][1]-pos1[i-1][1]));
		if(k4&&k1)
			rel+=(pos1[0][0]-pos4[k4-1][1])*(pos1[0][0]-pos4[k4-1][1])+(pos1[0][1]-pos4[k4-1][0])*(pos1[0][1]-pos4[k4-1][0])
		for(i=1;i<k1;i++)
			rel+=sqrt((pos1[i][0]-pos1[i-1][0])*(pos1[i][0]-pos1[i-1][0])+(pos1[i][1]-pos1[i-1][1])*(pos1[i][1]-pos1[i-1][1]));

		if(k4&&k1)
			rel+=(pos1[0][0]-pos4[k4-1][1])*(pos1[0][0]-pos4[k4-1][1])+(pos1[0][1]-pos4[k4-1][0])*(pos1[0][1]-pos4[k4-1][0])
		for(i=1;i<k1;i++)
			rel+=sqrt((pos1[i][0]-pos1[i-1][0])*(pos1[i][0]-pos1[i-1][0])+(pos1[i][1]-pos1[i-1][1])*(pos1[i][1]-pos1[i-1][1]));

		if(k4&&k1)
			rel+=(pos1[0][0]-pos4[k4-1][1])*(pos1[0][0]-pos4[k4-1][1])+(pos1[0][1]-pos4[k4-1][0])*(pos1[0][1]-pos4[k4-1][0])
		for(i=1;i<k1;i++)
			rel+=sqrt((pos1[i][0]-pos1[i-1][0])*(pos1[i][0]-pos1[i-1][0])+(pos1[i][1]-pos1[i-1][1])*(pos1[i][1]-pos1[i-1][1]));
