/*
Recently, Dearboy buys a dart for his dormitory, but neither Dearboy nor his roommate knows how to play it. So they decide to make a new rule in the dormitory, which goes as follows:

Given a number N, the person whose scores accumulate exactly to N by the fewest times wins the game.

Notice once the scores accumulate to more than N, one loses the game.

Now they want to know the fewest times to get the score N.



So the task is : 
Given all possible dart scores that a player can get one time and N, you are required to calculate the fewest times to get the exact score N.

Input

Standard input will contain multiple test cases. The first line of the input is a single integer T (1 <= T <= 50) which is the number of test cases. And it will be followed by T consecutive test cases.

Each test case begins with two positive integers M(the number of all possible dart scores that a player can get one time) and N.  Then the following M integers are the exact possible scores in the next line.

Notice: M (0 < M < 100), N (1 < N <= 1000000000), every possible score is (0, 100).

Output

For each test case, print out an integer representing the fewest times to get the exact score N.
If the score can't be reached, just print -1 in a line.

Sample Input

3
3 6
1 2 3
3 12
5 1 4
1 3
2
Sample Output

2
3
-1
*/

#include<cstdio>

#define inf 1000000000

int num[101],dp[10001];

int n,m;

inline int mmin(int a,int b)

{return a<b?a:b;}

 

int main()

{

       int i,j,run,nn,mmax;

       scanf("%d",&run);

       while(run--)

       {

              scanf("%d%d",&n,&m);

              mmax=0;

              for(i=0;i<n;i++)

              {

                     scanf("%d",&num[i]);

                     if(mmax<num[i])

                            mmax=num[i];

              }

              nn=mmax*mmax;

              if(m%mmax==0) { printf("%d\n",m/mmax); continue; }

              for(i=0;i<=nn;i++) dp[i]=inf;

              dp[0]=0;

              for(i=0;i<nn;i++)

              {

                     for(j=0;j<n;j++)

                     {

                            dp[i+num[j]]=mmin(dp[i+num[j]],dp[i]+1);

                     }

              }

              if(m<=nn) 

              {

                     if(dp[m]>=inf) printf("-1\n");

            else printf("%d\n",dp[m]);

              }

              else

              {

                     int tmp=m-nn,ans=inf,time,mod;

                     time=tmp/mmax;

                     mod=tmp%mmax;

                     for(i=1;i<=mmax;i++)

                     {

                            ans=mmin(ans,time+i+dp[nn+mod-i*mmax]);

                     }

                     if(ans>=inf) printf("-1\n");

            else printf("%d\n",ans);

 

              }

       }

       return 0;

}
