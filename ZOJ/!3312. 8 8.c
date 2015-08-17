///貌似需要高精
#include <stdio.h>
#include <stdlib.h>
#define ADD 1
#define SUB 2
#define MULT 3
#define DIV 4
#define MIN 1e-5

struct nodeEight
{
	int leftD, leftL, rightD, rightL;
	int op;
	int value1, value2;
	int lbrace, rbrace;
};

struct nodeEight Num[9][50000];
int count[50];
int nn, nnn;

int cmp(const void *a, const void *b)
{
	double aa = ((struct nodeEight *)a)->value;
	double bb = ((struct nodeEight *)b)->value;

	return aa > bb ? 1 : -1;
}

int search(int v1, int v2, int i, int n)
{
	int j;
	for(j = 0;j < n;j++)
		if (v1 == Num[i][j].value1 && v2 == Num[i][j].value2)
			return 0;
	return 1;
}

void wTable()
{
	int i, j, k, c1, c2, cnt, value1, value2;
	double valueEight = 8;
	for (i = 2;i < 9;i++)
	{
		cnt = 1;
		valueEight = valueEight * 10 + 8;
		Num[i][0].leftD = Num[i][0].rightD = 0;
		Num[i][0].leftL = Num[i][0].rightL = 0;
		Num[i][0].op = 0;
		Num[i][0].lbrace = Num[i][0].rbrace = 0;
		Num[i][0].value1 = valueEight;
		Num[i][0].value2 = 1;

		for (j = 1, k = i - 1;j <= k;j++, k--)
		{
			for (c1 = 0;c1 < count[j];c1++)
				for (c2 = 0;c2 < count[k];c2++)
				{
					Num[i][cnt].leftD = j;Num[i][cnt].leftL = c1;
					Num[i][cnt].rightD = k;Num[i][cnt].rightL = c2;
					Num[i][cnt].op = MULT;
					if (Num[j][c1].op == 0)
						Num[i][cnt].lbrace = 0;
					else
						Num[i][cnt].lbrace = 1;
					if (Num[k][c2].op == 0)
						Num[i][cnt].rbrace = 0;
					else
						Num[i][cnt].rbrace = 1;

					value1 = Num[j][c1].value1 * Num[k][c2].value1;
					value2 = Num[j][c1].value2 * Num[k][c2].value2;
					if (search(value1, value2, i, cnt))
					{
						Num[i][cnt].value1 = value1;
						Num[i][cnt++].value2 = value2;
					}
				}
			for (c1 = 0;c1 < count[j];c1++)
				for (c2 = 0;c2 < count[k];c2++)
				{
					if (Num[k][c2].value1 != 0)
					{
						Num[i][cnt].leftD = j;Num[i][cnt].leftL = c1;
						Num[i][cnt].rightD = k;Num[i][cnt].rightL = c2;
						Num[i][cnt].op = DIV;
						if (Num[j][c1].op == 0)
							Num[i][cnt].lbrace = 0;
						else
							Num[i][cnt].lbrace = 1;
						if (Num[k][c2].op == 0)
							Num[i][cnt].rbrace = 0;
						else
							Num[i][cnt].rbrace = 1;

						value1 = Num[j][c1].value1 * Num[k][c2].value2;
						value2 = Num[j][c1].value2 * Num[k][c2].value1;
						if (search(value1, value2, i, cnt))
						{
							Num[i][cnt].value1 = value1;
							Num[i][cnt++].value2 = value2;
						}

					}
					if (Num[j][c1].value != 0)
					{
						Num[i][cnt].leftD = k;Num[i][cnt].leftL = c2;
						Num[i][cnt].rightD = j;Num[i][cnt].rightL = c1;
						Num[i][cnt].op = DIV;
						if (Num[k][c2].op == 0)
							Num[i][cnt].lbrace = 0;
						else
							Num[i][cnt].lbrace = 1;
						if (Num[j][c1].op == 0)
							Num[i][cnt].rbrace = 0;
						else
							Num[i][cnt].rbrace = 1;
						value1 = Num[j][c1].value2 * Num[k][c2].value1;
						value2 = Num[j][c1].value1 * Num[k][c2].value2;
						if (search(value1, value2, i, cnt))
						{
							Num[i][cnt].value1 = value1;
							Num[i][cnt++].value2 = value2;
						}
					}
				}
			for (c1 = 0;c1 < count[j];c1++)
				for (c2 = 0;c2 < count[k];c2++)
				{
					Num[i][cnt].leftD = j;Num[i][cnt].leftL = c1;
					Num[i][cnt].rightD = k;Num[i][cnt].rightL = c2;
					Num[i][cnt].op = ADD;
					if (Num[j][c1].op == 0)
						Num[i][cnt].lbrace = 0;
					else
						Num[i][cnt].lbrace = 1;
					if (Num[k][c2].op == 0)
						Num[i][cnt].rbrace = 0;
					else
						Num[i][cnt].rbrace = 1;

					value1 = Num[j][c1].value1 * Num[k][c2].value2 + Num[j][c1].value2 * Num[k][c2].value1;
					value2 = Num[j][c1].value2 * Num[k][c2].value2;
					if (search(value1, value2, i, cnt))
					{
						Num[i][cnt].value1 = value1;
						Num[i][cnt++].value2 = value2;
					}
				}

			for (c1 = 0;c1 < count[j];c1++)
				for (c2 = 0;c2 < count[k];c2++)
				{
					Num[i][cnt].leftD = j;Num[i][cnt].leftL = c1;
					Num[i][cnt].rightD = k;Num[i][cnt].rightL = c2;
					Num[i][cnt].op = SUB;
					if (Num[j][c1].op == 0)
						Num[i][cnt].lbrace = 0;
					else
						Num[i][cnt].lbrace = 1;
					if (Num[k][c2].op == 0)
						Num[i][cnt].rbrace = 0;
					else
						Num[i][cnt].rbrace = 1;

					value1 = Num[j][c1].value1 * Num[k][c2].value2 - Num[j][c1].value2 * Num[k][c2].value1;
					value2 = Num[j][c1].value2 * Num[k][c2].value2;
					if (search(value1, value2, i, cnt))
					{
						Num[i][cnt].value1 = value1;
						Num[i][cnt++].value2 = value2;
					}

					Num[i][cnt].leftD = k;Num[i][cnt].leftL = c2;
					Num[i][cnt].rightD = j;Num[i][cnt].rightL = c1;
					Num[i][cnt].op = SUB;
					if (Num[k][c2].op == 0)
						Num[i][cnt].rbrace = 0;
					else
						Num[i][cnt].rbrace = 1;
					if (Num[j][c1].op == 0)
						Num[i][cnt].rbrace = 0;
					else
						Num[i][cnt].rbrace = 1;

					value1 = Num[j][c1].value2 * Num[k][c2].value1 - Num[j][c1].value1 * Num[k][c2].value2;
					value2 = Num[j][c1].value2 * Num[k][c2].value2;
					if (search(value1, value2, i, cnt))
					{
						Num[i][cnt].value1 = value1;
						Num[i][cnt++].value2 = value2;
					}
				}
		}
		count[i] = cnt;
	}
}


int bSearch(int v, int n)
{
	int low = 0, high = n - 1;
	int mid = (low + high) / 2;

	while(low <= high)
	{
		mid =  (low + high) / 2;
		if ((int)Num[8][mid].value1 == v)
			return mid;
		else
		{
			if ((int)Num[8][mid].value1 < v)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}

void dfs(int dep, int location)
{
	int leftD, leftL, rightD, rightL, op, lbrace, rbrace;
	if (Num[dep][location].op != 0)
	{
		op = Num[dep][location].op;
		lbrace = Num[dep][location].lbrace;
		rbrace = Num[dep][location].rbrace;
		leftD = Num[dep][location].leftD;
		leftL = Num[dep][location].leftL;

		if (lbrace)
			putchar('(');
		dfs(leftD, leftL);
		if (lbrace)
			putchar(')');

		switch(op)
		{
			case ADD: {putchar('+'); break;}
			case SUB: {putchar('-'); break;}
			case MULT: {putchar('*'); break;}
			case DIV: {putchar('/'); break;}
		}

		rightD = Num[dep][location].rightD;
		rightL = Num[dep][location].rightL;

		if (rbrace)
			putchar('(');
		dfs(rightD, rightL);
		if (rbrace)
			putchar(')');
	}
	else
		printf("%.lf", Num[dep][location].value);
}


int main()
{
	int location, n;
	Num[1][0].value1 = 8;
	Num[1][0].value2 = 1;
	Num[1][0].op = 0;
	Num[1][0].leftD = Num[1][0].rightD = 0;
	Num[1][0].leftL = Num[1][0].rightL = 0;
	Num[1][0].lbrace = Num[1][0].rbrace = 0;
	count[1] = 1;
	wTable();
	while(scanf("%d", &n) != EOF)
	{
		location = bSearch(n, count[8]);
		if (location != -1)
		{
			dfs(8, location);
			putchar('\n');
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
