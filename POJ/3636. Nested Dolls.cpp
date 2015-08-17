/*
Description

Dilworth is the world's most prominent collector of Russian nested dolls: he literally has thousands of them! You know, the wooden hollow dolls of different sizes of which the smallest doll is contained in the second smallest, and this doll is in turn contained in the next one and so forth. One day he wonders if there is another way of nesting them so he will end up with fewer nested dolls? After all, that would make his collection even more magnificent! He unpacks each nested doll and measures the width and height of each contained doll. A doll with width w1 and height h1 will fit in another doll of width w2 and height h= if and only if w1 < w2 and h1 < h2. Can you help him calculate the smallest number of nested dolls possible to assemble from his massive list of measurements?

Input

On the first line of input is a single positive integer 1 ≤ t ≤ 20 specifying the number of test cases to follow. Each test case begins with a positive integer 1 ≤ m ≤ 20000 on a line of itself telling the number of dolls in the test case. Next follow 2m positive integers w1, h1,w2, h2, ... ,wm, hm, where wi is the width and hi is the height of doll number i. 1 ≤ wi, hi ≤ 10000 for all i.

Output

For each test case there should be one line of output containing the minimum number of nested dolls possible.

Sample Input

4
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
Sample Output

1
2
3
2
*/


#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int x,y;
}a[20005];
bool com(const Node a,const Node b)  //比较函数 
{
	return a.x>b.x||((a.x==b.x)&&a.y<=b.y);
}
int n;
int d[20005];
/*int find(int x,int len)
{
    for(int i=len;i>=1;i--)
    if(d[i]>=x&&d[i-1]<x) return i;
}*/   
int find(int p,int q,int x)
{
	int m;
	while(p<q)
	{
		m=(p+q)/2;
		if(d[m]<=x)
			p=m+1;
		else
			q=m;
	}
	return p;
} 
int search()
{
	int i,j;
	d[0]=0;
	int len=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].y>=d[len])
		{
			len++;
			d[len]=a[i].y;
			continue;
		}
		else
		{
			j=find(1,len,a[i].y);  //在d[]中找大于等于a[i]的第一个数 
			d[j]=a[i].y;
		}
	}
	return len;
}		
int main()
{
	int i,t;
	scanf("%d",&t); 
	while(t--)
	{
		int count=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1,com);
	//	for(i=1;i<=n;i++)
	//	cout<<a[i].y<<" "; 
        printf("%d\n",search());
	}
	return 0;
}

