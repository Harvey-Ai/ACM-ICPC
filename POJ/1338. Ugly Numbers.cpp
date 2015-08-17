/*
Description

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ... 
shows the first 10 ugly numbers. By convention, 1 is included. 
Given the integer n,write a program to find and print the n'th ugly number. 
Input

Each line of the input contains a postisive integer n (n <= 1500).Input is terminated by a line with n=0.
Output

For each line, output the n’th ugly number .:Don’t deal with the line with n=0.
Sample Input

1
2
9
0
Sample Output

1
2
10
*/


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		int arr[10000];
		arr[0] = 1;

		int p1 = 0, p2 = 0, p3 = 0;
		int p = 1;
		for(int i = 1;i < n;i++)
		{
			if (arr[p1] * 2 <= arr[p2] * 3 && arr[p1] * 2 <= arr[p3] * 5)
			{
				arr[p++] = arr[p1] * 2;
				if (arr[p1] * 2 == arr[p2] * 3)
					p2++;
				if (arr[p1] * 2 == arr[p3] * 5)
					p3++;
				p1++;
			}
			else if (arr[p2] * 3 <= arr[p1] * 2 && arr[p2] * 3 <= arr[p3] * 5)
			{
				arr[p++] = arr[p2] * 3;
				if (arr[p2] * 3 == arr[p1] * 2)
					p1++;
				if (arr[p2] * 3 == arr[p3] * 5)
					p3++;
				p2++;
			}
			else
			{
				arr[p++] = arr[p3] * 5;
				if (arr[p3] * 5 == arr[p1] * 2)
					p1++;
				if (arr[p3] * 5 == arr[p2] * 3)
					p2++;
				p3++;
			}
		}
		cout << arr[p - 1] << endl;
	}
	return 0;
}
