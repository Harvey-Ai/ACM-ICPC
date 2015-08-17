#include <stdio.h>
#include <math.h>
//using namespace std;
int cion1s[10001][11],cion2s[10001][11];
int main()
{
	int i,j,k,m,n,max,up,UP,sign,ep,temp;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		max=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&cion1s[i][j]);
		ep=pow(2,n);
		for(i=0;i<ep;i++)
		{
		    for(k=0;k<m;k++)
			   for(j=0;j<n;j++)
			       cion2s[k][j]=cion1s[k][j];
			temp=i;
			for(j=0;j<n;j++)
			{
				sign=temp%2;
				temp/=2;
				if(sign)
					for(k=0;k<m;k++)
						cion2s[k][j]=1-cion2s[k][j];
			}
			UP=0;
			for(j=0;j<m;j++)
			{
				up=0;
				for(k=0;k<n;k++)
					up+=cion2s[j][k];
				if((up*2)<n)
					UP+=n-up;
				else
					UP+=up;
			}
			if(UP>max)
				max=UP;
		}
		printf("%d\n",max);
	}
	return 0;
}
/*

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int i,j,l,m,n,max,up,flag;
	int cion1s[10000][10],cion2s[10000][10];
	long long k,flip,ep;
	while(cin>>m>>n)
	{
		flip=0;max=0;ep=pow(2,(m+n));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				cin>>cion1s[i][j];

		for(k=0;k<ep;k++)
		{
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cion2s[i][j]=cion1s[i][j];

			up=0;l=0;flip=k;
			while(flip)
			{
				flag=flip%2;
				flip/=2;
				if(flag)
				{
					if(l<m)
						for(j=0;j<n;j++)
							if(cion2s[l][j])
								cion2s[l][j]=0;
							else
								cion2s[l][j]=1;
					else
						for(j=0;j<m;j++)
							if(cion2s[j][l-m])
								cion2s[j][l-m]=0;
							else
								cion2s[j][l-m]=1;
				}
				l++;
			}
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					if(cion2s[i][j])
						up++;
			if(up>max)
				max=up;
		}
		cout<<max<<endl;
	}
	return 0;
}



#include <stdio.h>
#include <math.h>
#include <memory.h>

int     arr[10001][11];
int     sign[1025];

int main(void)
{
 int     row, col;
       int     i, j, k, n, t, count, ans;
 while( scanf("%d%d", &row, &col) != EOF )
 {
    for( i=count=0; i < row; ++i )
     for( j=0; j < col; ++j )
     {
      scanf("%d", &arr[i][j]);
      count += arr[i][j];
     }
    if(count == row*col){ printf("%d\n", count); continue;}
    n = (int)pow(2, col);     memset(sign, 0, 4*n);

    for( i=1; i < n && count < row*col; ++i )
    {
     for(j=0, t=1; t ; ++j)
     {
      sign[j] += t;
      if(sign[j] == 2)
      { 
       t = 1; sign[j] = 0; 
      }
      else 
      {
       t = 0;     for(k=0; k < row; ++k) arr[k][j] = 1-arr[k][j];
      }
     }
     for(j=0; j < row; ++j)
     {
      for(k=ans=0; k < col; ++k) ans += arr[j][k]; 
      if(ans <= col/2)
      {
       for(k=0; k < col; ++k) arr[j][k] = 1-arr[j][k]; 
      }
     }

     for(j=ans=0; j < row; ++j)
      for(k=0; k < col; ++k)
       ans += arr[j][k];
     if(ans > count) count = ans;
    }

    printf("%d\n", count);
 }
 return 0;
}
*/



		