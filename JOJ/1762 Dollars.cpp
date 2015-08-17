#include <iostream>
using namespace std;
const double EPS = 1e-3;
int main()
{
	long arr[1001][11];
	int money[11]={0,1,2,4,10,20,40,100,200,400,1000};
	int i,j,k;
	double m;
	for(i=0;i<=1000;i++)
		for(j=0;j<=10;j++)
			arr[i][j]=0;

	for(j=0;j<=10;j++)
		arr[1][j]=arr[0][j]=1;

	for(i=1;i<=1000;i++)
		arr[i][1]=1;

	for(i=2;i<=1000;i++)
		for(j=2;j<=10;j++)
		{
			k=0;
			while((i-money[j]*k)>=0)
			{
				arr[i][j]+=arr[i-money[j]*k][j-1];
				k++;
			}
		}

	while( scanf("%lf", &m), m > EPS )     
	{
		printf("%5.2lf%12ld\n", m,arr[int((m/0.05)+EPS)][10]);
	}
	return 0;
}

/*


#include <stdio.h>

const double EPS = 1e-3;
 
double     arr[11] = {0.00, 0.05, 0.10, 0.20, 0.50, 1.00, 2.00, 5.00, 10.00, 20.00, 50.00};
long     res[1001][11];

int main(void)
{
 int     i, j, k;

 for( i=1; i <= 1000; ++i ) res[i][1] = 1;
 for( i=1; i <= 10; ++i ) res[1][i] = 1;

 for( i=2; i <= 1000; ++i )
   for( j=2; j <= 10; ++j )
   {
    if( arr[j] - 0.05*i <= EPS ) k = j;

    if( arr[j] - 0.05*i > EPS )     res[i][j] = res[i][k];
    else if( arr[j] - 0.05*i < EPS && arr[j] - 0.05*i > -EPS ) res[i][j] = 1 + res[i][j-1];
    else res[i][j] = res[i][j-1] + res[i-int( arr[j]/0.05 + 1e-3 )][j];
   }
   
 double     value;
 while( scanf("%lf", &value), value > EPS )     
 {
   for( i=1; i <= 10 && arr[i] <= value; ++i );
   printf("%5.2lf%12ld\n", value, res[int(value/0.05 + 1e-3)][i-1]);
 }

 return 0;
}
*/