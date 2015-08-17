/*
Description

Professor Ben is an old stubborn man teaching mathematics in a university. He likes to puzzle his students with perplexing (sometimes boring) problems. Today his task is: for a given integer N, a1,a2, ... ,an are the factors of N, let bi be the number of factors of ai, your job is to find the sum of cubes of all bi. Looking at the confused faces of his students, Prof. Ben explains it with a satisfied smile:

Let's assume N = 4. Then it has three factors 1, 2, and 4. Their numbers of factors are 1, 2 and 3 respectively. So the sum is 1 plus 8 plus 27 which equals 36. So 36 is the answer for N = 4.

Given an integer N, your task is to find the answer.

Input

The first line contains the number the test cases, Q(1 ≤ Q ≤ 500000). Each test case contains an integer N(1 ≤ N ≤ 5000000)

Output

For each test case output the answer in a separate line.

Sample Input

1
4
Sample Output

36
*/

#include <stdio.h>
int prime[3000],ct[3000];
int tail;
double rel;
void dfs(int k,int a)
{
	if(k==tail)
	{
		rel+=a*a*a;
		return;
	}
	for(int i=0;i<=ct[k];i++)
		dfs(k+1,a*(i+1));
}
int main()
{
	int i,j,cnt,n,temp,ncase;
	cnt=1;prime[0]=2;
	for(i=3;i<3001;i++)
	{
		for(j=0;j<cnt;j++)
			if(i%prime[j]==0)
				break;
		if(j==cnt)
			prime[cnt++]=i;
	}
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		for(i=0,j=0;n>=prime[i]&&i<cnt;i++)
		{
			ct[j]=0;
			while(n%prime[i]==0)
			{
				n/=prime[i];
				ct[j]++;
			}
			if(ct[j])	j++;
		}
		if(n!=1)
		{
			ct[j]=1;
			j++;
		}
		tail=j;
		rel=0;
		dfs(0,1);
		printf("%.0lf\n",rel);
	}
	return 0;
}
