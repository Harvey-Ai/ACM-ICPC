/*
The Antique Comedians of Malidinesia prefer comedies to tragedies. Unfortunately, most of the ancient plays are tragedies. Therefore the dramatic advisor of ACM has decided to transfigure some tragedies into comedies. Obviously, this work is very hard because the basic sense of the play must be kept intact, although all the things change to their opposites. For example the numbers: if any number appears in the tragedy, it must be converted to its reversed form before being accepted into the comedy play.
Reversed number is a number written in arabic numerals but the order of digits is reversed. The first digit becomes last and vice versa. For example, if the main hero had 1245 strawberries in the tragedy, he has 5421 of them now. Note that all the leading zeros are omitted. That means if the number ends with a zero, the zero is lost by reversing (e.g. 1200 gives 21). Also note that the reversed number never has any trailing zeros.

ACM needs to calculate with reversed numbers. Your task is to add two reversed numbers and output their reversed sum. Of course, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12).


Input

The input consists of N cases. The first line of the input contains only positive integer N. Then follow the cases. Each case consists of exactly one line with two positive integers separated by space. These are the reversed numbers you are to add.


Output

For each case, print exactly one line containing only one integer - the reversed sum of two reversed numbers. Omit any leading zeros in the output.


Sample Input

3
24 1
4358 754
305 794


Sample Output

34
1998
1
*/

#include <iostream>
using namespace std;
int main()
{
	char num1[100],num2[100],rel[100];
	int i,n,N1,N2,REL,temp;
	bool flag;
	cin>>n;cin.get();
	while(n--)
	{
		N1=N2=0;
		cin>>num1>>num2;
		i=0;temp=1;flag=0;
		while(num1[i]!='\0')
		{
			if(num1[i]!='0')
				flag=1;
			if(flag)
			{
				N1+=(num1[i]-'0')*temp;
				temp*=10;
			}
			i++;
		}
		i=0;temp=1;flag=0;
		while(num2[i]!='\0')
		{
			if(num2[i]!='0')
				flag=1;
			if(flag)
			{
				N2+=(num2[i]-'0')*temp;
				temp*=10;
			}
			i++;
		}
		REL=N1+N2;i=0;
		while(REL)
		{
			rel[i]=(REL%10)+'0';
			REL/=10;
			i++;
		}
		rel[i]='\0';
		i=0;
		while(rel[i]=='0')
			i++;
		if(rel[i]=='\0')
			cout<<'0'<<endl;
		else
		{
			while(rel[i]!='\0')
			{
				cout<<rel[i];
				i++;
			}
			cout<<endl;
		}
	}
	return 0;
}
