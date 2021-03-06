/*
描述   ‘道’是中国古代哲学的重要范畴。用以说明世界的本原、本体、规律或原理。在不同的哲学体系中，其涵义有所不同。老子所写的《道德经》是关于‘道’的经典著作。   道的原始涵义指道路、坦途，以后逐渐发展为道理，用以表达事物的规律性。这一变化经历了相当长的历史过程。《易经》中有“复自道，何其咎”（《小畜》），“履道坦坦”（《履》），“反复其道，七日来复”(《复》)，都为道路之义。   《尚书•洪范》中说：“无有作好,遵王之道；无有作恶,遵王之路。无偏无党,王道荡荡;无党无偏,王道平平；无反无侧,王道正直”。这里的道，已经有正确的政令、规范和法度的意思,说明“道”的概念已向抽象化发展。   ---- 节选自有道词典(http://dict.youdao.com)  
Base64是网络上最常见的用于传输8Bit字节代码的编码方式之一。它把每三个8Bit的字节转换为四个6Bit的字节（3*8 = 4*6 = 24），然后把6Bit再添两位高位0，组成四个8Bit的字节，也就是说，转换后的字符串理论上将要比原来的长1/3。   
有道的工程师闲暇之余，将Base64编码改成了Base4编码，即把每个8Bit的字节转换成4个2Bit的字节，然后以4个字符来代替。编码和字符的对应方案如下： 00 ---- a 01 ---- o 10 ---- d 11 ---- 空格  这样，编码后的字符串就只会含有字符‘d','a','o'和空格。   例如字符y ,其ASCII码是121，对应的二进制串是01111001，这样分成 01 11 10 01四块后，用Base4编码后的字符串为"o do"。  
有道的工程师很好奇，按照这种编码方式，编码后的字符串中含有多少个完整的dao呢？一个完整的dao由连续的‘d','a','o'三个字符组成。
输入   第一行有一个正整数n，代表接下来有n个待编码的原串。（1 <= n <= 10)   
接下来有n行，每行有一个长度不超过10^6 的原串，原串中的字符可能为ASCII码中除换行符以外的任意可见字符。   
输出 
共有n行，每行为一个整数k, 表示输入数据中对应的原串用Base4编码后含有多少个完整的dao。   
样例输入   
2  www.youdao.com 
dict.youdao.com
样例输出   1 1
*/


#include <stdio.h>
#include <string.h>
#define N 10

char str[1000010];

int main()
{
	char c;
	char convert[N];
	char temp[N];
	int ncase;
	int res;
	int a;
	int value;
	int i, j, k;
	scanf("%d", &ncase);
	scanf("%c", &c);
	getchar();

	while(ncase--)
	{
		res = 0;
		strcpy(temp, "kkkkk");
		gets(str);
		for(i = 0;str[i] !='\0';i++)
		{
			value = (int)str[i];
		//	printf("%d\n", value);
			for(j = 0, k = 0;j < 4;j++)
			{
				a = (value & 0x80) ? 10 : 0;
				a += (value & 0x40) ? 1 : 0;
			//	printf("aa:%d\n", a);
				switch(a)
				{
					case 0:
						convert[k++] = 'a';
						break;
					case 1:
						convert[k++] = 'o';
						break;
					case 10:
						convert[k++] = 'd';
						break;
					case 11:
						convert[k++] = ' ';
						break;
				}
				value<<=2;
			}
			convert[4] = '\0';
			//printf("temp: %s convert: %s\n", temp, convert);
			if (temp[2] == 'd' && temp[3] == 'a' && convert[0] == 'o')
				res++;
			if (temp[3] == 'd' && convert[0] == 'a' && convert[1] == 'o')
				res++;
			if (convert[0] == 'd' && convert[1] == 'a' && convert[2] == 'o')
				res++;
			if (convert[1] == 'd' && convert[2] == 'a' && convert[3] == 'o')
				res++;
			strcpy(temp, convert);
			temp[4] = '\0';
		}
		printf("%d\n", res);
	}
}

