/*
Description

An image A is said to be a subimage of another image B if it is possible to remove some rows and/or columns of pixels from B so that the resulting image is identical to A. Figure 6 illustrates an example. Image A, shown in Figure 6(a), is a subimage of image B, shown in Figure 6(b), because the image resulting from the removal of the middle row and column of pixels from B is identical to A.

 	 
 	 
 	 	 
 	 	 
 	 	 
(a) Image A		(b) Image B
Figure 6: An example of a subimage

Given two black-and-white images A and B, determine whether A is a subimage of B.

Input

The input contains a single test case. The first line contains two integers r and c (1 ≤ r, c ≤ 20), the dimensions of A. The following r lines, each containing a string of length c, give an r × c 0-1 matrix representing the pixels of A. The next line contains two integers R and C (r ≤ R ≤ 20; c ≤ C ≤ 20), the dimensions of B. The following R lines, each containing a string of length C, give an R × C 0-1 matrix representing the pixels of B. A 0 indicates a white pixel; a 1 indicates a black pixel.

Output

If A is a subimage of B, print “Yes”; otherwise, print “No”.

Sample Input

2 2
11
10
3 3
101
000
100
Sample Output

Yes
*/


#include <stdio.h>
int ok,rr,r,c,R,C;
char arr[20][20],arr2[20][20];
int used[20];
void dfs(int a,int num)
{
	int i;
	if(num==r)
	{
		ok=1;
		return;
	}
	if(a==R)
		return;
	if(ok)
		return;
	for(i=0;i<c;i++)
		if(arr2[a][used[i]]!=arr[num][i])
			break;
	if(i>=c)
	{
		for(i=a+1;i<=R-r+num+1;i++)
			dfs(i,num+1);
	}
}
void pipei(int k1,int k2)
{
	if(ok)
		return;
	if(k2==C||k1==c)
	{
		if(k1==c)
			dfs(rr,0);
		return;
	}
	if(arr[0][k1]==arr2[rr][k2])
	{
		used[k1]=k2;
		pipei(k1+1,k2+1);
		pipei(k1,k2+1);
	}
	else
		pipei(k1,k2+1);
}
int main()
{
	int i,j;
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		getchar();
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				arr[i][j]=getchar();
			getchar();
		}
		scanf("%d%d",&R,&C);
		getchar();
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
				arr2[i][j]=getchar();
			getchar();
		}
		ok=0;
		for(i=0;i<=R-r;i++)
		{
			rr=i;
			pipei(0,0);
			if(ok)
				break;
		}
		if(ok)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
