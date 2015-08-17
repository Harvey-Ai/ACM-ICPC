/*
Problem Description
Generally speaking, there are a lot of problems about strings processing. Now you encounter another such problem. If you get two strings, such as “asdf” and “sdfg”, the result of the addition between them is “asdfg”, for “sdf” is the tail substring of “asdf” and the head substring of the “sdfg” . However, the result comes as “asdfghjk”, when you have to add “asdf” and “ghjk” and guarantee the shortest string first, then the minimum lexicographic second, the same rules for other additions.
 

Input
For each case, there are two strings (the chars selected just form ‘a’ to ‘z’) for you, and each length of theirs won’t exceed 10^5 and won’t be empty.
 

Output
Print the ultimate string by the book.
 

Sample Input
asdf sdfg
asdf ghjk
 

Sample Output
asdfg
asdfghjk
*/


#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int next[100005];
void getNext(const char *str, int len)
{
    int k = -1;
    next[0] = -1;
    
    for(int i = 1;i < len;i++)
    {
        while(k >= 0 && str[i] != str[k + 1])
            k = next[k];

        if (str[i] == str[k + 1])
            k++;
        next[i] = k;
    }
}

int kmp(char *str1, char *str2, int len1, int len2)
{
    getNext(str2, len2);
    int k = -1;
    for(int i = 0;i < len1;i++)
    {
        while(k >= 0 && str1[i] != str2[k + 1])
            k = next[k];
        if (str1[i] == str2[k + 1])
            k++;
        
        if (k == len2)
            k = next[len2 - 1];
    }
    return k + 1;
}

int main()
{
    char s1[100005], s2[100005];
    char res[200005];
    while(scanf("%s %s", s1, s2) != EOF)
    {
        int len1 = strlen(s1), len2 = strlen(s2);
        int oSize = kmp(s1, s2, len1, len2);
        int resSize = len1 + len2 - oSize;
        strcpy(res, s1);
        strcpy(res + len1, s2 + oSize);
        
        oSize = kmp(s2, s1, len2, len1);
        if (len1 + len2 - oSize <= resSize)
        {
            char temp[200005];
            strcpy(temp, s2);
            strcpy(temp + len2, s1 + oSize);
            if (len1 + len2 - oSize < resSize || strcmp(temp, res) < 0)
                printf("%s\n", temp);
            else
                printf("%s\n", res);
        }
        else
            printf("%s\n", res);
    }
    return 0;
}
