/*
描述
Weird Wally's Wireless Widgets, Inc. manufactures an eclectic assortment of small, wireless, network capable devices, ranging from dog collars, to pencils, to fishing bobbers. All these devices have very small memories. Encryption algorithms like Rijndael, the candidate for the Advanced Encryption Standard (AES) are demonstrably secure but they don't fit in such a tiny memory. In order to provide some security for transmissions to and from the devices, WWWW uses the following algorithm, which you are to implement.
Encrypting a message requires three integer keys, k1, k2, and k3. The letters [a-i] form one group, [j-r] a second group, and everything else ([s-z] and underscore) the third group. Within each group the letters are rotated left by ki positions in the message. Each group is rotated independently of the other two. Decrypting the message means doing a right rotation by ki positions within each group.
Consider the message the_quick_brown_fox encrypted with ki values of 2, 3 and 1. The encrypted string is _icuo_bfnwhoq_kxert. The figure below shows the decrypting right rotations for one character in each of the three character groups. 


Looking at all the letters in the group [a-i] we see {i,c,b,f,h,e} appear at positions {2,3,7,8,11,17} within the encrypted message. After a right rotation of k1=2, these positions contain the letters {h,e,i,c,b,f}. The table below shows the intermediate strings that come from doing all the rotations in the first group, then all rotations in the second group, then all the rotations in the third group. Rotating letters in one group will not change any letters in any of the other groups.


All input strings contain only lowercase letters and underscores(_). Each string will be at most 80 characters long. The ki are all positive integers in the range 1-100.
输入
Input consists of information for one or more encrypted messages. Each problem begins with one line containing k1, k2, and k3 followed by a line containing the encrypted message. The end of the input is signalled by a line with all key values of 0.
输出
For each encrypted message, the output is a single line containing the decrypted string.
样例输入
2 3 1
_icuo_bfnwhoq_kxert
1 1 1
bcalmkyzx
3 7 4
wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
2 4 3
cjvdksaltbmu
0 0 0
样例输出
the_quick_brown_fox
abcklmxyz
the_quick_brown_fox_jumped_over_the_lazy_dog
ajsbktcludmv
*/

#include <iostream>
using namespace std;

int main()
{
	int k1, k2, k3;
	char str[10000], str2[10000];
	int arr1[10000], arr2[10000], arr3[10000];
	int i;

	while(cin >> k1 >> k2 >> k3, k1 || k2 || k3)
	{
		cin >> str;
		int index1, index2, index3;
		index1 = index2 = index3 = 0;

		for(i = 0;str[i] != '\0';i++)
		{
			if (str[i] >= 'a' && str[i] <= 'i')
				arr1[index1++] = i;
			else if (str[i] >= 'j' && str[i] <= 'r')
				arr2[index2++] = i;
			else if (str[i] >= 's' && str[i] <= 'z' || str[i] == '_')
				arr3[index3++] = i;
		}

		int temp1, temp2, temp3;
		temp1 = temp2 = temp3 = 0;
		for(i = 0;str[i] != '\0';i++)
		{
			if (str[i] >= 'a' && str[i] <= 'i')
			{
				str2[arr1[(temp1 + k1) % index1]]= str[i];
				temp1++;
			}
			else if (str[i] >= 'j' && str[i] <= 'r')
			{
				str2[arr2[(temp2 + k2) % index2]]= str[i];
				temp2++;
			}
			else if (str[i] >= 's' && str[i] <= 'z' || str[i] == '_')
			{
				str2[arr3[(temp3 + k3) % index3]]= str[i];
				temp3++;
			}
		}

		str2[i] = '\0';
		cout << str2 << endl;
	}
	return 0;
}
