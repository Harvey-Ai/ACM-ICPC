#include <stdio.h>
#define N 1005

int arr[N][N];
int main()
{
        int i, j, n, temp;
        scanf("%d", &n);

        for(i = 0;i < n;i++)
            for(j = 0;j < n;j++)
                    arr[i][j] = (i + j) % (n - 1) ? (i + j) % (n - 1) : (n - 1);

        for(i = 0;i < n;i++)
		{
            temp = arr[i][i];
            arr[i][i] = 0;
			arr[i][n - 1] = temp;
		}

		arr[n - 1][n - 1] = 0;
		for(i = 0;i < n;i++)
			arr[n - 1][i] = arr[i][n - 1];

        for(i = 0;i < n;i++)
        {
                for(j = 0;j < n - 1;j++)
                        printf("%d ", arr[i][j]);
                printf("%d\n", arr[i][j]);
        }
        return 0;
}
