#include <stdio.h>

int main()
{
	int ncase;
	int icase;

	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &p);
		num = pow(2, p);
		for(i = 0;i < num;i++)
		{
			scanf("%d", &a);
			must[i] = p - a;
		}
		
		t = num / 2;
		for(i = 0;i < p;i++)
		{
			for(j = 0;j < t;j++)
				scanf("%d", &price[j]);
			t /= 2;
		}

		flag = 1;
		memset(buyM, 0, sizeof(buyM));
		while(flag)
		{
			memset(need, 0, sizeof(need));
			memset(buyMN, 0, sizeof(buyMN));
			meset(buyN, 0, sizeof(buyN));
			flag = 1;
			t = num / 2;
			for(j = 0;j < t;j++)
			{
				buyN[0][j] = need[0][j] = 1;
				if (must[j * 2] <= 0 && must[j * 2 + 1] <= 0)
					buyN[0][j] = need[0][j] = 0;
			}

			for(j = 0;j < t;j++)
				if(need[0][j] && !buyM[0][j])
				{
					buyM[0][j] = 1;
					need[0][j] = 0;
					buyMN[0][j] = price[0][j];
				}
				else
					buyMN[0][j] = 0;

			t /= 2;
			for(i = 1;i < p;i++)
				for(j = 0;j < t;j++)
				{
					buyN[i][j] = buyN[i - 1][j * 2] + buyN[i - 1][j * 2 + 1];
					if ((need[i - 1][j * 2] || need[i - 1][j * 2 + 1]))
					{
						if (!buyM[i][j])
						{
							buyM[i][j] = 1;
							need[i][j] = 0;
							buyMN[i][j] = price[i][j];
						}
						else
						{
							need[i][j] = 1;
							buyMN[i][j] = buyMN[i - 1][j * 2] + buyMN[i - 1][j * 2 + 1];
						}
					}
					else
					{
						if (buy[i - 1][j * 2] + buy[i
					}
				}

		}
		memset(avgM, 0, sizeof(avgM));
		memset(buyM, 0, sizeof(buyM));
		memest(teamM, 0, sizeof(teamM));


		t = num / 2;
		for(j = 0;j < t;j++)
		{
			teamM[0][j] = 2;
			if (have[j * 2] <= 0)
				teamM[0][j]--;
			if (have[j * 2 + 1] <= 0)
				tempM[0][j]--;
		}
		t /= 2;
		for(i = 1;i < p;i++)
			for(j = 0;j < t;j++)
				teamM[i][j] = teaM[i - 1][j * 2] + teamM[i - 1][j * 2 + 1];


		
	}
}
