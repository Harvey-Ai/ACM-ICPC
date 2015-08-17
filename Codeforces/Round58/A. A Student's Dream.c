#include <stdio.h>

int main()
{
	int gl, gr, bl, br;
	scanf("%d %d %d %d", &gl, &gr, &bl, &br);

	if ((br >= gl - 1 && br <= (gl + 1) * 2) ||
			(bl >= gr - 1 && bl <= (gr + 1) * 2))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
