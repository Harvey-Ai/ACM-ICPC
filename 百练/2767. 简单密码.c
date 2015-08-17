/*
描述
Julius Caesar曾经使用过一种很简单的密码。对于明文中的每个字符，将它用它字母表中后5位对应的字符来代替，这样就得到了密文。比如字符A用F来代替。如下是密文和明文中字符的对应关系。

密文
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

明文
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 

你的任务是对给定的密文进行解密得到明文。

你需要注意的是，密文中出现的字母都是大写字母。密文中也包括非字母的字符，对这些字符不用进行解码。
输入
输入中的测试数据不超过100组。每组数据都有如下的形式，而且各组测试数据之间没有空白的行。

一组测试数据包括三部分

起始行 - 一行，包括字符串 "START" 
密文 - 一行，给出密文，密文不为空，而且其中的字符数不超过200
结束行 - 一行，包括字符串 "END" 


在最后一组测试数据之后有一行，包括字符串 "ENDOFINPUT"。 
输出
对每组数据，都有一行输出，给出密文对应的明文。
样例输入
START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
样例输出
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[1000];
	int i;
	while(cin >> str)
	{
		if (strcmp(str, "ENDOFINPUT") == 0)
			break;
		int flag = 0;
		while(cin >> str)
		{
			if (flag)
				cout << " ";
			else
				flag = 1;
			if (strcmp(str, "END") == 0)
				break;
			for(i = 0;str[i] != '\0';i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
				{
					char newOne = (char)(str[i] - 5);
					if (newOne < 'A')
						newOne += 26;
					cout << newOne;
				}
				else
					cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}
