我用朴素的查找，时间复杂度很高。当然字符串匹配应该用KMP
#include <iostream>
using namespace std;
char str[1000000];
int main()
{
	int i,j,tail;
	char c;
	bool flag;
	while(scanf("%c",&c),c!='.')
	{
		i=0;
		while(c!='\n')
		{
			str[i++]=c;
			c=cin.get();
		}
		tail=0;flag=1;
		while(tail<i)
		{
			flag=1;
			if(i%(1+tail))
			{
				tail++;
				continue;
			}
			for(j=0;j<i;j++)
			{
				if(str[j]!=str[j%(tail+1)])
				{
					flag=0;
					break;
				}
			}
			if(flag)
				break;
			else
				tail++;
		}
		cout<<i/(tail+1)<<endl;
	}
	return 0;
}
KMP算法：
#include <stdio.h>
#include <string.h>
 
char s[1000001];
short next[1000000];
 
int main()
{
    int i, j, len;
 
    while (1)
    {
        scanf("%s", s);
        if ('.' == s[0] && '\0' == s[1])
            break;
 
        len = strlen(s);
        i = 0;
        j = -1;
        next[0] = -1;
        while (i < len)
        {
            if (-1 == j || s[i] == s[j])
            {
                ++i;
                ++j;
                if (s[i] != s[j])
                    next[i] = j;
                else
                    next[i] = next[j];
            }
            else
                j = next[j];
        }
        i -= j;
        if (0 == len % i)
            i = len / i;
        else
            i = 1;
        printf("%d\n", i);
    }
}			
