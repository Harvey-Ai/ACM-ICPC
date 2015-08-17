/*
Decode the Strings

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 813    Accepted Submission(s): 251


Problem Description
Bruce Force has had an interesting idea how to encode strings. The following is the description of how the encoding is done: 

Let x1,x2,...,xn be the sequence of characters of the string to be encoded. 

1. Choose an integer m and n pairwise distinct numbers p1,p2,...,pn from the set {1, 2, ..., n} (a permutation of the numbers 1 to n). 
2. Repeat the following step m times. 
3. For 1 ≤ i ≤ n set yi to xpi, and then for 1 ≤ i ≤ n replace xi by yi. 

For example, when we want to encode the string "hello", and we choose the value m = 3 and the permutation 2, 3, 1, 5, 4, the data would be encoded in 3 steps: "hello" -> "elhol" -> "lhelo" -> "helol". 

Bruce gives you the encoded strings, and the numbers m and p1, ..., pn used to encode these strings. He claims that because he used huge numbers m for encoding, you will need a lot of time to decode the strings. Can you disprove this claim by quickly decoding the strings? 

 

Input
The input contains several test cases. Each test case starts with a line containing two numbers n and m (1 ≤ n ≤ 80, 1 ≤ m ≤ 109). The following line consists of n pairwise different numbers p1,...,pn (1 ≤ pi ≤ n). The third line of each test case consists of exactly n characters, and represent the encoded string. The last test case is followed by a line containing two zeros. 
 

Output
For each test case, print one line with the decoded string. 
 

Sample Input
5 3
2 3 1 5 4
helol
16 804289384
13 10 2 7 8 1 16 12 15 6 5 14 3 4 11 9
scssoet tcaede n
8 12
5 3 4 2 1 8 6 7
encoded?
0 0
 

Sample Output
hello
second test case
encoded?

*/


#include <stdio.h>
#include <string.h>

int main(void)
{
    int  n, m;
    int  b[100],bb[101],ccc[101];
    char a[2][100], t[100];
    int  c[100];
    while( scanf("%d%d", &n, &m) )
    { 
        if( n == 0 && m == 0 ) break;
        int  i, j;
        for( i=0; i < n; ++i ) 
        {
            scanf("%d", &c[i]);
            --c[i];
        } 
        for( i=0; i < n; ++i )
        {
            b[ c[i] ] = i;
         } 
             
        getchar();
        char ch;
        int len=0;
        while( (ch=getchar()) != '\n' ) a[0][len++] = ch;
        a[0][len] = a[1][len] = '\0';
   

        for(i=0;i<len;i++)
    {
           int t=i;
           int num=0;
           ccc[0]=i;
           while(b[t]!=i){
               num++;
               ccc[num]=b[t];
               t=b[t];
           }
           num++;
      
           bb[i]=ccc[m%num];
    }    
        for(i=0;i<len;i++)
            a[1][i]=a[0][bb[i]]; 
        printf("%s\n", a[1]);
    }
    return 0;
}
