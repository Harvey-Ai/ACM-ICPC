/*
Problem Description

Farmer John wants to evaluate the quality of the names of his N (1 <= N <= 1000) cows. Each name is a string with no more than 1000 characters, all of which are non-blank.
He has created a set of M (1 <= M <= 100) 'good' strings (no longer than 30 characters and fully non-blank). If the sequence letters of a cow's name contains the letters of a 'good' string in the correct order as a subsequence (i.e., not necessarily all next to each other), the cow's name gets 1 quality point.
All strings is case-insensitive, i.e., capital letters and lower case letters are considered equivalent. For example, the name "Bessie" contains the letters of "Be", "sI", "EE", and "Es" in the correct order, but not "is" or "eB". Help Farmer John determine the number of quality points in each of his cow's names.
 Input

There are multiple tests. For each test, there are three parts.
* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 contains a string that is the name of the ith cow
* Lines N+2..N+M+1: Line N+i+1 contains the ith good string
 Output

For each test, you should output following part.
* Lines 1..N+1: Line i+1 contains the number of quality points of the ith name
 Sample Input

5 3
Bessie
Jonathan
Montgomery
Alicia
Angola
se
nGo
Ont
 Sample Output

1
1
2
0
1
*/

#include <iostream>
using namespace std;
int n,m;
int sta[1010][26];
char s1[1010][1010],s2[1010][110];       
int main()
{
    int i,j,k,n,m,len,last[26],res,tag,now;
   while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",s1[i]);
			for(j=0;s1[i][j];j++)
				if(s1[i][j]<'a')
					s1[i][j]+=32;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",s2[i]);
			for(j=0;s2[i][j];j++)
				if(s2[i][j]<'a')
					s2[i][j]+=32;
        }    
        for(k=0;k<n;k++)
        {
            len=strlen(s1[k]);
            for(i=0;i<26;i++)last[i]=len;
            for(i=len-1;i>=0;i--)
            {
                for(j=0;j<26;j++)sta[i][j]=last[j];
                last[s1[k][i]-'a']=i;
            }
            res=0;
            for(i=0;i<m;i++)
            {
                tag=1;
                now=last[s2[i][0]-'a'];
                if(now==len)
					continue;
                for(j=1;s2[i][j];j++)
                {   
                    now=sta[now][s2[i][j]-'a'];
                    if(now==len)
                    {
                        tag=0;
                        break;
                    } 
                }    
                if(tag)res++;
            } 
            printf("%d\n",res);
        }
    }
    return 0;
}

