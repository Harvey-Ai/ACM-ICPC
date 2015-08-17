/*
Description

Before the invention of book-printing, it was very hard to make a copy of a book. All the contents had to be re-written by hand by so called scribers. The scriber had been given a book and after several months he finished its copy. One of the most famous scribers lived in the 15th century and his name was Xaverius Endricus Remius Ontius Xendrianus (Xerox). Anyway, the work was very annoying and boring. And the only way to speed it up was to hire more scribers. 

Once upon a time, there was a theater ensemble that wanted to play famous Antique Tragedies. The scripts of these plays were divided into many books and actors needed more copies of them, of course. So they hired many scribers to make copies of these books. Imagine you have m books (numbered 1, 2 ... m) that may have different number of pages (p1, p2 ... pm) and you want to make one copy of each of them. Your task is to divide these books among k scribes, k <= m. Each book can be assigned to a single scriber only, and every scriber must get a continuous sequence of books. That means, there exists an increasing succession of numbers 0 = b0 < b1 < b2, ... < bk-1 <= bk = m such that i-th scriber gets a sequence of books with numbers between bi-1+1 and bi. The time needed to make a copy of all the books is determined by the scriber who was assigned the most work. Therefore, our goal is to minimize the maximum number of pages assigned to a single scriber. Your task is to find the optimal assignment. 
Input

The input consists of N cases. The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly two lines. At the first line, there are two integers m and k, 1 <= k <= m <= 500. At the second line, there are integers p1, p2, ... pm separated by spaces. All these values are positive and less than 10000000.
Output

For each case, print exactly one line. The line must contain the input succession p1, p2, ... pm divided into exactly k parts such that the maximum sum of a single part should be as small as possible. Use the slash character ('/') to separate the parts. There must be exactly one space character between any two successive numbers and between the number and the slash. 

If there is more than one solution, print the one that minimizes the work assigned to the first scriber, then to the second scriber etc. But each scriber must be assigned at least one book.
Sample Input

2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100
Sample Output

100 200 300 400 500 / 600 700 / 800 900
100 / 100 / 100 / 100 100

*/


#include <stdio.h>
int dp[501][501];
int main()
{
	bool tag[505];
	int arr[501];
	int i,j,k,n,part,min,max,sum,cnt,ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d%d",&n,&part);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			tag[i]=0;
		}
		dp[0][0]=arr[0];
		for(i=1;i<n;i++)
			dp[0][i]=dp[0][i-1]+arr[i];
		for(i=1;i<part;i++)
		{
			for(j=i;j<n;j++)
			{
				min=1000000000;
				sum=arr[j];
				for(k=j-1;k>=i-1;k--)
				{
					if(sum>dp[i-1][k])
						max=sum;
					else
						max=dp[i-1][k];
					if(min>=max)
						min=max;
					sum+=arr[k];
				}
				dp[i][j]=min;
			}
		}
		max=dp[part-1][n-1];
		cnt=part-1;
		sum=0;
		for(j=n-1;j>=cnt;j--)
		{
			sum+=arr[j];
			if(sum>max)
			{
				tag[j]=1;
				j++;
				sum=0;
				cnt--;
			}
		}
		for(j=0;j<cnt;j++)
			tag[j]=1;
		for(i=0;i<n;i++)
		{
			if(tag[i])
				printf("%d / ",arr[i]);
			else
				printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}
