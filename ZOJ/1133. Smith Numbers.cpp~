/*
While skimming his phone directory in 1982, Albert Wilansky, a mathematician of Lehigh University, noticed that the telephone number of his brother-in-law H. Smith had the following peculiar property: The sum of the digits of that number was equal to the sum of the digits of the prime factors of that number. Got it? Smith��s telephone number was 493-7775. This number can be written as the product of its prime factors in the following way:



The sum of all digits of the telephone number is 4+9+3+7+7+7+5= 42� , and the sum of the digits of its prime factors is equally 3+5+5+6+5+8+3+7= 42. Wilansky was so amazed by his discovery that he named this kind of numbers after his brother-in-law: Smith numbers.

As this observation is also true for every prime number, Wilansky decided later that a (simple and unsophisticated) prime number is not worth being a Smith number, so he excluded them from the definition.

Wilansky published an article about Smith numbers in the Two Year College Mathematics Journal and was able to present a whole collection of different Smith numbers: For example, 9985 is a Smith number and so is 6036. However,Wilansky was not able to find a Smith number that was larger than the telephone number of his brother-in-law. It is your task to find Smith numbers that are larger than 4937775!


Input

The input consists of a sequence of positive integers, one integer per line. Each integer will have at most 8 digits. The input is terminated by a line containing the number 0.


Output

For every number n > 0 in the input, you are to compute the smallest Smith number which is larger than n, and print it on a line by itself. You can assume that such a number exists.


Sample Input

4937774
0


Sample Output

4937775 
*/

#include <stdio.h>
int main()
{
	int prime[110000][2];
	int dig1,dig2;
	long i,k,s,t,p,temp,n;

	for(i=1;i<=109999;i++) 
		prime[i][0]=1; 

  	for(i=2; i<=54000;i++) 
		prime[i*2][0]=0;

	prime[0][0]=1;prime[1][0]=2;prime[0][1]=0;prime[1][1]=2;
	p=2;k=2;i=2;
	while(p*p<=109999) 
	{
		p++; 
		while(prime[p][0]==0) 
			p++;
		while(i<p*p)
		{
			if(prime[i][0])
			{
				prime[k][0]=i;prime[k][1]=0;
				while(prime[k][0])
				{
					prime[k][1]+=prime[k][0]%10;
					prime[k][0]/=10;
				}
				prime[k][0]=i;
				k++;
			}
			i++;
		}
		t=p*p; 
		s=2*p; 
		while(t<=109999) 
		{ 
			prime[t][0]=0;  
			t+=s; 
		} 
	}
	while(scanf("%ld",&n))
	{
		if(n==0)
			break;
		k=n+1;
		while(1)
		{
			dig1=dig2=0;
			temp=k;
			while(temp)
			{
				dig1+=temp%10;
				temp/=10;
			}
			temp=k;
			for(i=1;prime[i][0]*prime[i][0]<=k;i++)
			{
				while(temp%prime[i][0]==0)
				{
					temp/=prime[i][0];
					dig2+=prime[i][1];
				}
				if(temp==1)
					break;
				if(dig2>dig1)
					break;
			}	
			if(temp!=1&&temp!=k)
				while(temp)
				{
					dig2+=temp%10;
					temp/=10;
				}
			if(dig1==dig2)
			{
				printf("%ld\n",k);
				break;
			}
			else
				k++;
		}
	}
	return 0;
} 

