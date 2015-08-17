/*
Description

In many applications very large integers numbers are required. Some of these applications are using keys for secure transmission of data, encryption, etc. In this problem you are given a number, you have to determine the number of digits in the factorial of the number.
Input

Input consists of several lines of integer numbers. The first line contains an integer n, which is the number of cases to be tested, followed by n lines, one integer 1 <= m <= 10^7 on each line.
Output

The output contains the number of digits in the factorial of the integers appearing in the input.
Sample Input

2
10
20
Sample Output

7
19
*/



#include "iostream"
#include "cmath"
using namespace std;

int n;
const double e = 2.7182818284590452354, pi = 3.141592653589793239;

double Stiring( int a );

int main()
{
    int N, result;
    double i, s;
cin>>N;
    while( N-- )
    {
   cin>>n;
        if( n < 100000 )
        {
            for( s=0, i=1; i<=n; i++ )
                s += log10( i );
        }
        else s = Stiring( n );
        result = (int)s;
        if( result <= s )
            result++;
   cout<<result<<endl;
    }
    return 0;
}

double Stiring( int a )
{
    return log10( sqrt( 2 * pi * a ) ) + a * log10( a / e );
}

