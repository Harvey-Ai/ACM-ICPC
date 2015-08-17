//bug

#include <stdio.h>


long long lineNum[500];
long long personNum[500];
const char name[5][20] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
const long long MAX = 1000000000;

int main()
{
	int i, k;
	long long n;
	lineNum[0] = 0;
	personNum[1] = 1;
	lineNum[1] = 5;

	k = 1;
	while(lineNum[k] <= MAX)
	{
		k++;
		personNum[k] = personNum[k - 1] * 2;
		lineNum[k] = lineNum[k - 1] * 2;
	}
	
	scanf("%lld", &n);
	n--;

	for(i = 0; n - lineNum[i] >= 0;i++)
		n -= lineNum[i];

	printf("%s\n", name[n / personNum[i]]);
	return 0;
}
