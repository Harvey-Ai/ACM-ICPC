/*
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,sum,temp,x,y;
	while(cin>>n)
	{
		sum=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(i>j)
				{
					x=i;y=j;
				}
				else
				{
					x=j;y=i;
				}
				while(x%y)
				{
					temp=y;
					y=x%y;
					x=temp;
				}
				if(y==1)
					sum++;
			}
		cout<<sum<<endl;
	}
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,l,sum,temp,x,y;
	while(cin>>n)
	{
		sum=n-1;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				l=1;
				if(i>j)
				{
					x=i;y=j;
				}
				else
				{
					x=j;y=i;
				}
				while(x%y)
				{
					temp=y;
					y=x%y;
					x=temp;
				}
				if(y==1)
					sum+=(n-i)/j+1;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
int prime[48]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,
		103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223};
long ol[50000];
int main()
{
	int j;
	int n=1;ol[1]=0;
	while(n++<50000)
	{
		bool flag=1;
		int temp=-1,ol_i=n,k=n;
		for(j=0;j<48;j++)
			if(k%prime[j]==0)
			{
				flag=0;
				if(temp!=j)
				{
					ol_i/=prime[j];
					ol_i*=prime[j]-1;
				}
				k/=prime[j];
				temp=j;
				j--;
			}
		if(flag)
			ol[n]=(ol_i-1);
		else
		{
			if(k!=1)
			{
				ol_i/=k;
				ol_i*=k-1;
			}
			ol[n]=ol_i;
		}
		ol[n]+=ol[n-1];
	}
	while(cin>>n)
		cout<<ol[n]*2+1;
	return 0;
}


/*

227
1
50000
1520910575

  50000
1519848527
227
31531
5000
15200915
50000
1519848527
10000
60794971








#include <stdio.h>

long   arr[50001] = {0, 0, 1, 2};
int   prime[48] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,
103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223};                            

int main(void)
{
 int  i, j, n;
        // 先求出初步欧拉函数表（跟欧拉函数有区别的），因为arr[i] += arr[i-1];                       
 for( i=3; i < 50001; ++i )
 {
  bool   flag = false;   
  long   sum = i; n = i;    
  for( j=0; j < 48 && n > 1; ++j )
   if( n%prime[j] == 0 && n >= prime[j])
   {
    sum /= prime[j];   sum *= prime[j]-1;
    flag = true;
    do{ 
     n /= prime[j];
    }while( n%prime[j] == 0 && n > 1 );
   }
  if( flag ){ 
   if ( n != 1 ) { sum /= n; sum *= n-1; }   arr[i] = sum; }
  else arr[i] = i-1;
  arr[i] += arr[i-1];                       
 }

 while( scanf("%d", &n) != EOF ) printf("%ld\n", 2*arr[n]+1 );

 return 0;
}
*/








	





		