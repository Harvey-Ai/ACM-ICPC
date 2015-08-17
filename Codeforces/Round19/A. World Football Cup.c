#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct teamS
{
	char name[50];
	int sc;
	int goal, lost;
}team[55];


int cmpStr(const void *a, const void *b)
{
	struct teamS *aa = (struct teamS *)a;
	struct teamS *bb = (struct teamS *)b;
	
	return strcmp(aa->name, bb->name);
}

int cmpSC(const void *a, const void *b)
{
	struct teamS *aa = (struct teamS *)a;
	struct teamS *bb = (struct teamS *)b;
	
	if (bb->sc - aa->sc > 0)
		return 1;
	else if (bb->sc - aa->sc < 0)	
		return -1;
	else if (bb->goal - bb->lost > aa->goal - aa->lost)
		return 1;
	else if (bb->goal - bb->lost < aa->goal - aa->lost)
		return -1;
	else if (bb->goal > aa->goal)
		return 1;
	else if (bb->goal < aa->goal)
		return -1;
	return 1;
}	

int main()
{
	char team1[100], team2[100];
	int i, j, k;
	int n;
	int iteam1, iteam2;
	int sc1, sc2;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
	{
		scanf("%s", team[i].name);
		team[i].sc = team[i].goal = team[i].lost = 0;
	}
	
	for(i = 0;i < n * (n - 1) / 2;i++)
	{
		scanf("%s %d:%d", team1, &sc1, &sc2);
		for(j = 0;team1[j] != '\0';j++)
			if (team1[j] == '-')
			{
				team1[j] = '\0';
				j++;
				break;
			}
		for(k = 0;team1[j] !='\0';j++, k++)
			team2[k] = team1[j];
		team2[k] = '\0';
		for(j = 0;j < n;j++)
			if (strcmp(team[j].name, team1) == 0)
				iteam1 = j;
			else if (strcmp(team[j].name, team2) == 0)
				iteam2 = j;
		team[iteam1].goal += sc1;
		team[iteam1].lost += sc2;
		team[iteam2].goal += sc2;
		team[iteam2].lost += sc1;
		if (sc1 > sc2)
			team[iteam1].sc += 3;
		else if (sc1 < sc2)
			team[iteam2].sc += 3;
		else
		{
			team[iteam1].sc++;
			team[iteam2].sc++;
		}
	}
	qsort(team, n, sizeof(team[0]), cmpSC);
	qsort(team, n / 2, sizeof(team[0]), cmpStr);

	for(i = 0;i < n / 2;i++)
		printf("%s\n", team[i].name);
	return 0;
}
