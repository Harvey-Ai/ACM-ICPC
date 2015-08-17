#include <iostream>
#include <cstdio>
using namespace std;

int arr[1005];
int main()
{
    int n;
    scanf("%d", &n);

    int arr1 = 0;
    int arr2[105], arr3[105];
    int arr2Num = 0, arr3Num = 0;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0)
        {
            if (arr1 == 0)
                arr1 = arr[i];
            else
                arr2[arr2Num++] = arr[i];
        }
        else if (arr[i] > 0)
            arr2[arr2Num++] = arr[i];
        else
            arr3[arr3Num++] = arr[i];
    }

    int ng = 0;
    for(int i = 0;i < arr2Num;i++)
        if (arr2[i] < 0)
            ng++;

    if (ng % 2)
    {
        for(int i = 0;i < arr2Num;i++)
            if (arr2[i] < 0)
            {
                swap(arr2[arr2Num - 1], arr2[i]);
                arr3[arr3Num++] = arr2[arr2Num - 1];
                arr2Num--;
                break;
            }
    }

    printf("1 %d\n", arr1);
    printf("%d", arr2Num);
    for(int i = 0;i < arr2Num;i++)
        printf(" %d", arr2[i]);
    putchar('\n');
    printf("%d", arr3Num);
    for(int i = 0;i < arr3Num;i++)
        printf(" %d", arr3[i]);
    putchar('\n');
    return 0;
}
