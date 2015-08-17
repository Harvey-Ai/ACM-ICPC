#include <stdio.h>
#include <math.h>

int isprime(int n)
{
int i;
if (n%2 == 0)
   return 0;
for (i=3; i<=sqrt(n); i+=2)
{
   if (n%i == 0)
    return 0;
}

   return 1;
}

int main()
{
int n,i,flag;
scanf("%d",&n);
while (n != 0)
{
   flag=1;
   for (i=3; i<=n/2; i+=2)
   {
    if (isprime(i) && isprime(n-i))
    {
     printf("%d = %d + %d\n",n,i,n-i);
     flag=0;
     break;
    }
   
   }

   if(flag == 1)
   {
    printf("Goldbach's conjecture is wrong.");
   }

   scanf("%d",&n);
}

return 0;
}



	
	
	