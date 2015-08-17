/*
Problem Description
Bruce Force's keyboard is broken, only a few keys are still working. Bruce has figured out he can still type texts by switching the keyboard layout whenever he needs to type a letter which is currently not mapped to any of the m working keys of the keyboard. 

You are given a text that Bruce wishes to type, and he asks you if you can tell him the maximum number of consecutive characters in the text which can be typed without having to switch the keyboard layout. For simplicity, we assume that each key of the keyboard will be mapped to exactly one character, and it is not possible to type other characters by combination of different keys. This means that Bruce wants to know the length of the largest substring of the text which consists of at most m different characters. 

 

Input
The input contains several test cases, each test case consisting of two lines. The first line of each test case contains the number m (1 ≤ m ≤ 128), which specifies how many keys on the keyboard are still working. The second line of each test case contains the text which Bruce wants to type. You may assume that the length of this text does not exceed 1 million characters. Note that the input may contain space characters, which should be handled like any other character. 

The last test case is followed by a line containing one zero. 

 

Output
For each test case, print one line with the length of the largest substring of the text which consists of at most m different characters.
 

Sample Input
5
This can't be solved by brute force.
1
Mississippi
0
 

Sample Output
7
2
Hint
 The largest substring for the first test case is "_by_bru", where _ stands for a space character. 

*/


#include<stdio.h>
#include<string.h>
char str[1000005];
int cnt[400];
int main()
{
    char c;
    int i,n,res,head,tail,len,cn;
    while(scanf("%d",&n),n)
    {
    memset(cnt,0,sizeof(cnt));
        getchar();
        c=getchar();
        for(i=0;c!='\n';i++)
    {
        str[i]=c;
        c=getchar();
    }
        len=i;
        head=0;cn=0;
        for(tail=0;cn<n&&tail<len;tail++)
        {
            if(cnt[str[tail]]==0)
                cn++;
         cnt[str[tail]]++;
        }
        res=tail-head;
        for(;tail<len;tail++)
        {
            if(cnt[str[tail]]==0)
            {
         cnt[str[head]]--;
         head++;
         while(cnt[str[head-1]])
         {
            cnt[str[head]]--;
            head++;
        }
                     
            }
        cnt[str[tail]]++;
            if(tail-head+1>res)
                res=tail-head+1;
        }
        printf("%d\n",res);
    }
    return 0;
}
