#include <stdio.h>

void rmm(char *str)
{
	int i, j;
	char temp[605];
	for(i = 0, j = 0;str[i] != '\0';i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			temp[j++] = str[i] + 'a' - 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			temp[j++] = str[i];
	}
	temp[j] = '\0';
	for(i = 0;temp[i] != '\0';i++)
		str[i] = temp[i];
	str[i] = '\0';
}

int check(int *kk, char *str, char *fa)
{
	int j;
	int ok = 1;
	for(j = *kk;str[j - *kk] != '\0' && fa[j] != '\0';j++)
		if (str[j - *kk] != fa[j])
		{
			ok = 0;
			break;
		}
	if (ok == 1 && str[j - *kk] == '\0')
	{
		*kk = j;
		return 1;
	}
	return 0;
}

int main()
{
	int i, j, k, len;
	int pp;
	int n;
	int flag[3];
	char str[3][105], ans[605];

	scanf("%s %s %s", str[0], str[1], str[2]);
	rmm(str[0]);
	rmm(str[1]);
	rmm(str[2]);
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%s", ans);
		rmm(ans); 
		flag[0] = flag[1] = flag[2] = 0;
		pp = 0;
		for(j = 0;j < 3;j++)
		{
			for(k = 0;k < 3;k++)
				if (flag[k] == 0 && check(&pp, str[k], ans) == 1)
				{
					flag[k] = 1;
					break;
				}
			if (k >= 3)
				break;
		}
		if (j >= 3 && ans[pp] == '\0')
			printf("ACC\n");
		else
			printf("WA\n");
	}
}
