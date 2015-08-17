#include <stdio.h>
int main()
{
	int i,dig1,dig2,dig3,temp,sum;
	for(i=256;i<3746;i++)
	{
		temp=i;
		dig1=i/256;
		temp=temp%256;
		dig2=temp/16;
		temp=temp%16;
		dig3=temp;
		sum=dig1*dig1*dig1+dig2*dig2*dig2+dig3*dig3*dig3;
		if(sum==i)
		{
			if(dig1>9)
				printf("%c^3+",dig1-10+'A');
			else
				printf("%d^3+",dig1);
			if(dig2>9)
				printf("%c^3+",dig2-10+'A');
			else
				printf("%d^3+",dig2);
			if(dig3>9)
				printf("%c^3",dig3-10+'A');
			else
				printf("%d^3",dig3);
			printf(" == %d\n",i);
		}

	}
	return 0;
}



