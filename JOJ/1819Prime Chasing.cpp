/*
//ɸѡ��Ȼ���ԣ�
#include <iostream>
using namespace std;
bool number[900000001];
int main()
{
	int i,p,n1,n2,count;
	for(i=2;i<900000001;i++)
		number[i]=1;
	for(i=2;i<450000001;i++)
		number[i*2]=0;
	p=2;
	while(p*p<900000001)
	{
		p++;
		while(number[p]==0)
			p++;
		int t=p*p;
		int s=2*p;
		while(t<900000001)
		{
			number[t]=0;
			t+=s;
		}
	}

	while(cin>>n1>>n2)
	{
		count=0;
		for(i=n1;i<=n2;i++)
			if(number[i])
				count++;
		cout<<count<<endl;
	}
	return 0;
}
*/
#include <stdio.h>
//#include <math.h>
//using namespace std;
int main()
{
	long i,j,n1,n2;
	int count;
	bool flag;
	while(scanf("%ld%ld",&n1,&n2)!=EOF)
	{
		count=0;
		if(n1%2==0)
			n1++;
		for(i=n1;i<=n2;i+=2)
		{
			flag=1;
			for(j=3;j*j<=i;j+=2)
				if(i%j==0)
				{
					flag=0;
					break;
				}
			if(flag)
				count++;
		}
		printf("%ld\n",count);
	}
	return 0;
}
//�������Ĵ��룺
/*
prototype

#include <stdio.h>

int main(void)
{
 long   i, j, bin, end, sum;

     while(scanf("%ld%ld", &bin, &end) != EOF)
 {
  sum = 0;
  for(i=bin; i <= end; ++i)
   if(i%2)
   {
    for(j=3; j*j <= i; j += 2)
     if(i%j == 0)   break;
    if(j*j > i) ++sum;
   }
  printf("%ld\n", sum);
 }

 return 0;
}
��΢�Ľ����㷨��
#include <stdio.h>

int primes[167] = 
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,
107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,
223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,
337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,
457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,
593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,
719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,
857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991};

int main(void)
{
 long   i, j, bin, end, sum;
     bool   flag;

     while(scanf("%ld%ld", &bin, &end) != EOF)
 {
  sum = 0;
  for(i=bin; i <= end; ++i)
  {
   flag = true;
   for(j=0; j < 167; ++j)
    if(i%primes[j] == 0) 
    {
     flag = false;
     break;
    }
             if(flag)
   {
    for(j=997; j*j <= i; j += 2)
     if(i%j == 0)   break;
    if(j*j > i) ++sum;
   }
  }
  printf("%ld\n", sum);
 }

 return 0;
}
*/