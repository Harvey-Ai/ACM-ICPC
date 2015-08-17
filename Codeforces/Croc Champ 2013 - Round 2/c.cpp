#include <iostream>
#include <cstdio>

char str1[2000005], str2[2000005];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str1);
    scanf("%s", str2);

    int oneToZero = 0, zeroToOne = 0;
    int oneToOne = 0;
    for(int i = 0;i < 2 * n;i++)
        if (str1[i] == '0' && str2[i] == '1')
            zeroToOne++;
        else if (str1[i] == '1' && str2[i] == '0')
            oneToZero++;
        else if (str1[i] == '1' && str2[i] == '1')
            oneToOne++;

    int thea1, thea2;
    if (oneToOne % 2)
    {
        thea1 = -1;
        thea2 = -2;
    }
    else
    {
        thea1 = 0;
        thea2 = -1;
    }

    if (oneToZero - zeroToOne < thea2)
        printf("Second\n");
    else if (oneToZero - zeroToOne > thea1)
        printf("First\n");
    else
        printf("Draw\n");
    return 0;
}
