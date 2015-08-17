/*
Description

To help you move from Waterloo to the big city, you are considering renting a moving truck. Gas prices being so high these days, you want to know how much the gas for such a beast will set you back. 
The truck consumes a full litre of gas for each kilometre it travels. It has a 200 litre gas tank. When you rent the truck in Waterloo, the tank is half full. When you return it in the big city, the tank must be at least half full, or you'll get gouged even more for gas by the rental company. You would like to spend as little as possible on gas, but you don't want to run out along the way.
Input

Input is all integers. The first integer is the distance in kilometres from Waterloo to the big city, at most 10000. Next comes a set of up to 100 gas station specifications, describing all the gas stations along your route, in non-decreasing order by distance. Each specification consists of the distance in kilometres of the gas station from Waterloo, and the price of a litre of gas at the gas station, in tenths of a cent, at most 2000.
Output

Output is the minimum amount of money that you can spend on gas to get you from Waterloo to the big city. If it is not possible to get from Waterloo to the big city without running out of gas along the way, output "Impossible".
Sample Input

500
100 999
150 888
200 777
300 999
400 1009
450 1019
500 1399
Sample Output

450550
*/

#include <stdio.h>
int main()
{
	int GasStation[105][2],Dp[105][201];
	int i,j,n,min,Mx,Distance,dis;
	Mx=2000*10001;
	while(scanf("%d",&Distance)!=EOF)
	{
		GasStation[0][0]=0;GasStation[0][1]=2001;
		i=1;
		while(scanf("%d%d",&GasStation[i][0],&GasStation[i][1])!=EOF)
		{
			if(GasStation[i][0]==GasStation[i-1][0])
			{
				if(GasStation[i][1]<GasStation[i-1][1])
					GasStation[i-1][1]=GasStation[i][1];
				i--;
			}
			i++;
		}
		n=i;
		GasStation[n][0]=Distance+100;GasStation[n][1]=2001;
		for(i=0;i<=100;i++)
			Dp[0][i]=0;
		if(GasStation[0][1]!=2001)
		{
			for(i=101;i<=200;i++)
				Dp[0][i]=Dp[0][i-1]+GasStation[0][1];
		}
		else
		{
			for(i=101;i<=200;i++)
				Dp[0][i]=Mx;
		}
		if(GasStation[1][0]>100)
		{
			printf("Impossible\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			dis=GasStation[i][0]-GasStation[i-1][0];
			if(dis>200)
				break;
			Dp[i][0]=Dp[i-1][dis];
			for(j=1;j+dis<=200;j++)
			{
				if(Dp[i-1][j+dis]<Dp[i][j-1]+GasStation[i][1])
					Dp[i][j]=Dp[i-1][j+dis];
				else
					Dp[i][j]=Dp[i][j-1]+GasStation[i][1];
			}
			while(j<=200)
			{
				Dp[i][j]=Dp[i][j-1]+GasStation[i][1];
				j++;
			}
		}
		if(i!=n+1)
			printf("Impossible\n");
		else
		{
			min=Dp[n][0];
			for(j=1;j<=200;j++)
				if(Dp[n][j]<min)
					min=Dp[n][j];
			printf("%d\n",min);
		}
	}
	return 0;
}
