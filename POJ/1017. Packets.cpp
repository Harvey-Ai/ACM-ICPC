/*
Description

A factory produces products packed in square packets of the same height h and of the sizes 1*1, 2*2, 3*3, 4*4, 5*5, 6*6. These products are always delivered to customers in the square parcels of the same height h as the products have and of the size 6*6. Because of the expenses it is the interest of the factory as well as of the customer to minimize the number of parcels necessary to deliver the ordered products from the factory to the customer. A good program solving the problem of finding the minimal number of parcels necessary to deliver the given products according to an order would save a lot of money. You are asked to make such a program.
Input

The input file consists of several lines specifying orders. Each line specifies one order. Orders are described by six integers separated by one space representing successively the number of packets of individual size from the smallest size 1*1 to the biggest size 6*6. The end of the input file is indicated by the line containing six zeros.
Output

The output file contains one line for each line in the input file. This line contains the minimal number of parcels into which the order from the corresponding line of the input file can be packed. There is no line in the output file corresponding to the last ``null'' line of the input file.
Sample Input

0 0 4 0 0 1 
7 5 1 0 0 0 
0 0 0 0 0 0 
Sample Output

2 
1 

*/

#include <stdio.h>
int main()
{
	int a0,a1,a2,a3,a4,a5,left11,left22,rel;
	while(scanf("%d%d%d%d%d%d",&a0,&a1,&a2,&a3,&a4,&a5),a0|a1|a2|a3|a4|a5)
	{
		rel=(a2+3)/4+a3+a4+a5;
		left22=a3*5;
		left11=a4*11;
		a2=a2%4;
		switch(a2) 
        {
            case 3:
			{
                left22+=1;
				left11+=5;
                break;
			}
            case 2:
			{
                left22+=3;
				left11+=6;
                break;
			}
            case 1:
			{
                left22+=5;
				left11+=7;
                break;
			}
		}
        if(a1<=left22)
		{
			left11+=(left22-a1)*4;
			a1=0;
		}
		else
			a1-=left22;
		if(a0<=left11)
			a0=0;
		else
			a0-=left11;
		rel+=(4*a1+a0+35)/36;
		printf("%d\n",rel);
	}
	return 0;
}
