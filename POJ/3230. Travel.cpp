/*
Description

One traveler travels among cities. He has to pay for this while he can get some incomes.

Now there are n cities, and the traveler has m days for traveling. Everyday he may go to another city or stay there and pay some money. When he come to a city ,he can get some money. Even when he stays in the city, he can also get the next day's income. All the incomes may change everyday. The traveler always starts from city 1.

Now is your turn to find the best way for traveling to maximize the total income.

Input

There are multiple cases.

The first line of one case is two positive integers, n and m .n is the number of cities, and m is the number of traveling days. There follows n lines, one line n integers. The j integer in the i line is the expense of traveling from city i to city j. If i equals to j it means the expense of staying in the city.

After an empty line there are m lines, one line has n integers. The j integer in the i line means the income from city j in the i day.

The input is finished with two zeros.
n,m<100.

Output

You must print one line for each case. It is the max income.
Sample Input

3 3
3 1 2
2 3 1
1 3 2

2 4 3
4 3 2
3 4 2

0 0
Sample Output

8
*/

#include <stdio.h>
#include <string.h>
int tcost[105][105],income[105][105],get[105][105];
int main()
{
	int i,j,k,m,n,max;
	while(scanf("%d%d",&n,&m),m||n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&tcost[i][j]);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&income[i][j]);
		memset(get,0,sizeof(get));
		for(i=0;i<n;i++)
			get[0][i]=income[0][i]-tcost[0][i];
		for(i=1;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				max=-10000000;
				for(k=0;k<n;k++)
					if(get[i-1][k]-tcost[k][j]>max)
						max=get[i-1][k]-tcost[k][j];
				get[i][j]=max+income[i][j];
			}
		}
		max=-10000000;
		for(i=0;i<n;i++)
			if(get[m-1][i]>max)
				max=get[m-1][i];
		printf("%d\n",max);
	}
	return 0;
}
